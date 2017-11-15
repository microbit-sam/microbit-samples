/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"
#include "MicroBitFlash.h"

MicroBit uBit;

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    // Setup a simple triangular waveform.
    MicroBitImage img("1 0 0 0 0 0 0 0 0 1\n0 1 0 0 0 0 0 0 1 0\n0 0 1 0 0 0 0 1 0 0\n0 0 0 1 0 0 1 0 0 0\n0 0 0 0 1 1 0 0 0 0\n");

    MicroBitFlash flash;
    uint32_t buffer1 = 0x12345678;
    uint32_t buffer2 = 0x87654321;

    int result = 0;

    // Write Buffer 1
    for(uint32_t x = 0x30000; x < 0x30100; x = x +4){
        result = flash.flash_write((uint32_t *)x, &buffer1, sizeof(buffer1));
    }

    uBit.display.print(result);
    uBit.sleep(1000);

    // Write Buffer 2
    for(uint32_t y = 0x30080; y < 0x30200; y = y +4){
        result = flash.flash_write((uint32_t *)y, &buffer2, sizeof(buffer2));
    }
   
    uBit.display.print(result);
    uBit.sleep(1000);

    uBit.display.print("D");

    while(1);
     

}

