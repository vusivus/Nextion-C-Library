
#ifndef __NEXCONFIG_H__
#define __NEXCONFIG_H__
#include "Serial.h"

#define nexSerial_init(b)        Serial_Init(b)
#define nexSerial_available()    Serial_Available()
#define nexSerial_read()         Serial_Read()
#define nexSerial_write(d)       Serial_Write(d)
#define nexSerial_print(p)       Serial_Print(p) 
#define nexSerial_readBytes(b,l) Serial_ReadBytes(b, l)
#define nexDelay(d)              delay_ms(d)

#endif /* #ifndef __NEXCONFIG_H__ */
