/**
 * @file NexProgressBar.cpp
 *
 * The implementation of class NexProgressBar. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/13
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software); you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation); either version 2 of
 * the License, or (at your option) any later version.
 */

#include "NexProgressBar.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../util/Utilities.h"

extern char cmd[64];
extern char buf[12];

uint8_t NexProgressBar_getValue(struct NexObject *bar, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, bar->__name);
    strcat(cmd, ".val");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexProgressBar_setValue(struct NexObject *bar, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, bar->__name);
    strcat(cmd, ".val=");
    strcat(cmd, buf);

    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexProgressBar_Get_background_color_bco(struct NexObject *bar, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, bar->__name);
    strcat(cmd, ".bco");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexProgressBar_Set_background_color_bco(struct NexObject *bar, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, bar->__name);
    strcat(cmd, ".bco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, bar->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexProgressBar_Get_font_color_pco(struct NexObject *bar, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, bar->__name);
    strcat(cmd, ".pco");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexProgressBar_Set_font_color_pco(struct NexObject *bar, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, bar->__name);
    strcat(cmd, ".pco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, bar->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}