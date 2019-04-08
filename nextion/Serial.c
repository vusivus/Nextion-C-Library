#include "Serial.h"
#include "../util/Utilities.h"

unsigned char rxBuff[64];
char rxHead, rxTail;
void UART1interrupt() iv IVT_UART_1 ilevel 6 ics ICS_AUTO
{
    rxBuff[rxHead++] = UART1_Read(); // read the received data
    U1RXIF_bit = 0;
}

void Serial_Init(long baudrate)
{
    AD1PCFG = 0xFFFF; // Configure AN pins as digital I/O
    UART1_Init(9600);
    rxHead = 0;
    rxTail = 0;

    U1IP0_bit = 0; // Set UART2 interrupt
    U1IP1_bit = 1; // Set interrupt priorities
    U1IP2_bit = 1; // Set UART2 interrupt to level 6

    U1RXIE_bit = 1; // Set UART Receive Interrupt
    U1RXIF_bit = 0;
    EnableInterrupts(); // Enable interruts as previously set
}

unsigned char Serial_Write(unsigned char c)
{
    UART1_Write(c);
    return 1;
}

unsigned char Serial_Read()
{
    unsigned char c;
    if (rxTail < rxHead)
    {
        c = rxBuff[rxTail++];
        if (rxTail == rxHead)
        {
            rxHead = 0;
            rxTail = 0;
        }
    }
    else
    {
        rxHead = 0;
        rxTail = 0;
        c = -1;
    }
    return c;
}

unsigned char Serial_Available()
{
    return rxHead - rxTail;
}

unsigned char Serial_ReadBytes(char *buf, unsigned char len)
{
    unsigned char cnt = 0;
    if (len < rxHead - rxTail)
    {
        ArrayCopy(buf, &rxBuff[rxTail], len);
        rxTail += len;
        cnt = len;
    }
    else if (len == rxHead - rxTail)
    {
        ArrayCopy(buf, &rxBuff[rxTail], len);
        rxTail = 0;
        rxHead = 0;
        cnt = len;
    }
    else
    {
        ArrayCopy(buf, &rxBuff[rxTail], rxHead - rxTail);
        cnt = rxHead - rxTail;
        rxTail = 0;
        rxHead = 0;
    }
    return cnt;
}

void Serial_Print(unsigned char *txt)
{
    short i = strlen(txt);
    while (1)
    {
        UART1_Write(*txt);
        ++txt;
        --i;
        if (i == 0)
        {
            break;
        }
    }
}