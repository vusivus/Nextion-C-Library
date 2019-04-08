#include "nextion/Nextion.h"
#include "util/Utilities.h"
#include <string.h>
#include <stdlib.h>

struct NexObject button, slider;

struct NexObject *nex_listen_list[] = {
    &button,
    &slider};

long value;

#define buttonPageID 0
#define sliderPageID 0
#define buttonID 2
#define sliderID 2

void main()
{
    CreateNexObject(button, buttonPageID, buttonID, "MyButton");
    CreateNexObject(slider, sliderPageID, sliderID, "MySlider");

    nexInit();

    NexSlider_getValue(&slider, &value);
    NexSlider_setValue(&slider, value + 20);

    NexTouch_attachPop(&button, buttonCallback, 0);
    NexTouch_attachPop(&slider, sliderCallback, 0);

    while (1)
    {
        nexLoop(nex_listen_list);
        delay_ms(50);
    }
}

void buttonCallback(void *ptr)
{
    //TODO
}

void sliderCallback(void *ptr)
{
    //TODO
}