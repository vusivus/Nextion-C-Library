# Nextion-C-Library
The C Library version of the Nextion Arduino C++ Library

# Introduction
This is a C implementation of the [Nextion Arduino](https://github.com/itead/ITEADLIB_Arduino_Nextion) Library and was developed and tested on a PIC32MX340F512H microcontroller but the library can be adapted to work on any IDE with any microcontroller.
 
# Usage
All the functions that exist in the original library are available here hence I will only focus on how different the implemetnation is with this library. 

## Initial setup
For starters, you will need to define the following functions in the NexConfig.h file inside the nextion folder:
````
#define nexSerial_init(b)           Serial_Init(b)  
#define nexSerial_available()       Serial_Available() 
#define nexSerial_read()            Serial_Read() 
#define nexSerial_write(d)          Serial_Write(d) 
#define nexSerial_print(p)          Serial_Print(p)  
#define nexSerial_readBytes(b,l)    Serial_ReadBytes(b, l)
#define nexDelay(d)                 delay_ms(d) 
````
Most of the functions are self explanatory, a UART driver is included inside the nextion folder to show you how to implement a Serial driver that meets these requirements.

## Creating Nextion Objects
In the original arduino Library, you would create an instance of a nextion object in such a manner:

````
NexButton b0 = NexButton(0, 1, "b0");
````

which allows you to specify what type of component you want to create an instance of. With this library, to create a Nextion object, you would need to define the following structure then invoke the macro that follows to create the object.

`````
struct NexObject b0;
CreateNexObject(b0, 0, 1, "b0");
`````

The notable difference here is that all Nextion objects (buttons, sliders etc.) are created with the same instance of the Nextion Object and what will seperate them with the the object name, page id and component id.

## Invoking Nextion Objects
As mentioned ealier, all the functions from the original library exist in this library, the invokation is slightly different.
For example, to get the text on the previous button inside the arduino IDE, you would use:
````
char buffer[16];
char len;
b0.getText(buffer,len)
````
but with this library, you would use:
````
NexButton_getText(&b0, buffer, len);
````

A good observation is that all functions and function parameters exist as they are in the original library. With this library, you don't invoke the functions using the class instance of the Nextion object. To get the text from a button you would use NexButton_getText, to set the text you would use NexButton_setTex(&buttonPointer, XXX).

In short, ypu need to specify the instance of the nex object with every function, in this library the instance of the object will be the pointer to the NexObject structure.

# Example Code
````
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
````

# Does it work?
This library was tested on a confidential project hence details of the project will not be shared, but a compressed video clip of the working display will be shared with you.
[Video Clip](https://youtu.be/4lPtvwyoER4)
