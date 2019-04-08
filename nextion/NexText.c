#include "NexText.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../util/Utilities.h"

extern char buf[12];
extern char cmd[64];

uint16_t NexText_getText(struct NexObject *text, char *buffer, uint16_t len)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".txt");
    sendCommand(cmd);
    return recvRetString(buffer, len);
}

uint8_t NexText_setText(struct NexObject *text, char *buffer)
{
    ClearString(cmd);
    strcat(cmd, text->__name);
    strcat(cmd, ".txt=\"");
    strcat(cmd, buffer);
    strcat(cmd, "\"");
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_Get_background_color_bco(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".bco");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_Set_background_color_bco(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".bco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, text->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_Get_font_color_pco(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".pco");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_Set_font_color_pco(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".pco=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, text->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_Get_place_xcen(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".xcen");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_Set_place_xcen(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".xcen=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, text->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_Get_place_ycen(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".ycen");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_Set_place_ycen(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".ycen=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, text->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_getFont(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".font");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_setFont(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".font=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, text->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_Get_background_crop_picc(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".picc");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_Set_background_crop_picc(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".picc=");
    strcat(cmd, buf);
    sendCommand(cmd);

    ClearString(cmd);
    strcat(cmd, "ref ");
    strcat(cmd, text->__name);
    sendCommand(cmd);
    return recvRetCommandFinished();
}

uint32_t NexText_Get_background_image_pic(struct NexObject *text, uint32_t *number)
{
    ClearString(cmd);
    strcat(cmd, "get ");
    strcat(cmd, text->__name);
    strcat(cmd, ".pic");
    sendCommand(cmd);
    return recvRetNumber(number);
}

uint8_t NexText_Set_background_image_pic(struct NexObject *text, uint32_t number)
{
    ClearString(buf);
    ClearString(cmd);

    utoa(buf, number, 10);
    strcat(cmd, text->__name);
    strcat(cmd, ".pic=");
    strcat(cmd, buf);

    sendCommand(cmd);
    return recvRetCommandFinished();
}