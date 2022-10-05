/**
 * @file NexHardware.cpp
 *
 * The implementation of base API for using Nextion. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#include "NexHardware.h"
#include "../util/Utilities.h"

#define NEX_RET_CMD_FINISHED (0x01)
#define NEX_RET_EVENT_LAUNCHED (0x88)
#define NEX_RET_EVENT_UPGRADED (0x89)
#define NEX_RET_EVENT_TOUCH_HEAD (0x65)
#define NEX_RET_EVENT_POSITION_HEAD (0x67)
#define NEX_RET_EVENT_SLEEP_POSITION_HEAD (0x68)
#define NEX_RET_CURRENT_PAGE_ID_HEAD (0x66)
#define NEX_RET_STRING_HEAD (0x70)
#define NEX_RET_NUMBER_HEAD (0x71)
#define NEX_RET_INVALID_CMD (0x00)
#define NEX_RET_INVALID_COMPONENT_ID (0x02)
#define NEX_RET_INVALID_PAGE_ID (0x03)
#define NEX_RET_INVALID_PICTURE_ID (0x04)
#define NEX_RET_INVALID_FONT_ID (0x05)
#define NEX_RET_INVALID_BAUD (0x11)
#define NEX_RET_INVALID_VARIABLE (0x1A)
#define NEX_RET_INVALID_OPERATION (0x1B)

char txt[32];
char cmd[64];
char buf[12];
char msg[32];
unsigned char wrData;

/*
 * Receive uint32_t data. 
 * 
 * @param number - save uint32_t data. 
 * @param 100 - set 100 time. 
 *
 * @retval 1 - success. 
 * @retval 0 - failed.
 *
 */
uint8_t recvRetNumber(uint32_t *number)
{
    uint8_t ret = 0;
    char temp[8];

    if (number){
        
        nexDelay(100);
        if (8 == nexSerial_readBytes((char *)temp, 8)){
            
            if (temp[0] == NEX_RET_NUMBER_HEAD && temp[5] == 0xFF && temp[6] == 0xFF && temp[7] == 0xFF){
                
                *number = ((uint32_t)temp[4] << 24) | ((uint32_t)temp[3] << 16) | (temp[2] << 8) | (temp[1]);
                ret = 1;
            }
        }
    }

    /*if (ret) 
    {
        dbSerialPrint("recvRetNumber :");
        dbSerialPrintln(*number);
    }
    else
    {
        dbSerialPrintln("recvRetNumber err");
    }*/

    return ret;
}

/*
 * Receive string data. 
 * 
 * @param buffer - save string data. 
 * @param len - string buffer length. 
 * @param 100 - set 100 time. 
 *
 * @return the length of string buffer.
 *
 */
uint16_t recvRetString(char *buffer, uint16_t len)
{
    uint16_t ret = 0;
    uint8_t str_start_flag = 0;
    uint8_t cnt_0xff = 0;
    uint8_t arr[32];
    uint8_t *temp = arr;
    uint8_t c = 0;
    long start;

    if (buffer && len){        
        
        start = 50000;
        
        while (start){
            while (nexSerial_available()){
                
                c = nexSerial_read();
                
                if (str_start_flag){
                
                    if (0xFF == c){
                        cnt_0xff++;
                        if (cnt_0xff >= 3){
                            break;
                        }
                    }else{
                        *temp++ = c;
                    }
                } else if (NEX_RET_STRING_HEAD == c){
                    str_start_flag = 1;
                }
            }

            if (cnt_0xff >= 3){
                break;
            }
            --start;
        }

        ret = ArrayLength(temp);
        ret = ret > len ? len : ret;
        strncpy(buffer, temp, ret);
    }

    /*
    dbSerialPrint("recvRetString[");
    dbSerialPrint(temp.length());
    dbSerialPrint(",");
    dbSerialPrint(temp);
    dbSerialPrintln("]");
     */
    return ret;
}

/*
 * Command is executed successfully. 
 *
 * @param 100 - set 100 time.
 *
 * @retval 1 - success.
 * @retval 0 - failed. 
 *
 */
uint8_t recvRetCommandFinished()
{
    uint8_t ret = 0;
    uint8_t temp[4] = {0};
    // nexSerial.set100(100);
    if (ArrayLength(temp) != nexSerial_readBytes((char *)temp, ArrayLength(temp)))
    {
        ret = 0;
    }

    if (temp[0] == NEX_RET_CMD_FINISHED && temp[1] == 0xFF && temp[2] == 0xFF && temp[3] == 0xFF)
    {
        ret = 1;
    }
    /*
    if (ret) 
    {
        dbSerialPrintln("recvRetCommandFinished ok");
    }
    else
    {
        dbSerialPrintln("recvRetCommandFinished err");
    }
     */
    return ret;
}

void sendCommand(char *command)
{
    nexSerial_print(command);
    nexSerial_write(0xFF);
    nexSerial_write(0xFF);
    nexSerial_write(0xFF);
}

uint8_t nexInit(void)
{
    uint8_t ret1 = 0;
    uint8_t ret2 = 0;

    //dbSerialBegin(9600);
    nexSerial_init(9600);
    sendCommand("");
    sendCommand("bkcmd=1");
    ret1 = recvRetCommandFinished();
    sendCommand("page 0");
    ret2 = recvRetCommandFinished();
    return ret1 && ret2;
}

void nexLoop(struct NexObject *nex_listen_list[])
{
    static uint8_t __buffer[10];

    uint16_t i;
    uint8_t limit = 20;
    uint8_t c;

    while (nexSerial_available() > 0)
    {
        nexDelay(10);
        c = nexSerial_read();

        if (NEX_RET_EVENT_TOUCH_HEAD == c)
        {
            if (nexSerial_available() >= 6)
            {
                __buffer[0] = c;
                for (i = 1; i < 7; i++)
                {
                    __buffer[i] = nexSerial_read();
                }
                __buffer[i] = 0x00;

                if (0xFF == __buffer[4] && 0xFF == __buffer[5] && 0xFF == __buffer[6])
                {
                    NexTouch_iterate(nex_listen_list, __buffer[1], __buffer[2], (int32_t)__buffer[3]);
                }
            }
        }
    }
}
