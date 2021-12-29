/*
 * File:   main.c
 * Author: User
 *
 * Created on 06 December 2021, 14:11
 */


#include "config.h"
#include "configOsc.h"
#include "configPorts.h"
#include "configEUSART.h"
#include "configBaud.h"
#include "configI2C.h"
#include "i2cStart.h"
#include "i2cWrite.h"
#include "i2cRead.h"
#include "i2cReStart.h"
#include "i2cStop.h"
#include "oLedWrite.h"
#include "configSH1106.h"
#include "setPageAddress.h"
#include "setColumnAddress.h"
#include "clearSH1106.h"

void main(void) 
{
    uchar pageAddress;
    uchar i;
    configOsc();
    configPorts();
    configEUSART();
    configBaud();
    configI2C();
    printf("Hola\n");
    configSH1106();
    __delay_ms(100);
    
    clearSH1106();
    
    pageAddress = setPageAddress(0);
    printf("in main pageAddress %d\n", pageAddress);
    setColumnAddress(2);
   
    
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, pageAddress);
   
    for(i = 0; i < 103; i++)
    {
            oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, hello[i]);
            //setColumnAddress(i + 3);
          
    }
    
    setColumnAddress(45);
    pageAddress = setPageAddress(2);
   
    
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, pageAddress);
   
    for(i = 0; i < 8; i++)
    {
            oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, heart[i]);
            //setColumnAddress(i + 3);
          
    }
    
    while(1)
    {
        DIAGNOSTIC_LED = HI;
        __delay_ms(100);
        DIAGNOSTIC_LED = LO;
        __delay_ms(100);
    }
}
