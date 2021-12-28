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
    uchar pageAddress, i;
    
    configOsc();
    configPorts();
    configEUSART();
    configBaud();
    configI2C();
    printf("Hola\n");
    configSH1106();
    
   // pageAddress = setPageAddress(7);
    //oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, pageAddress);
    
    __delay_ms(1000);
    clearSH1106();
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, SH1106_SET_DISPLAY_ON);                // display ON 0xaf, display OFF 0xae   
     pageAddress = setPageAddress(7);
    setColumnAddress(3);
   
    
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, pageAddress);
    for(i = 0; i < 1; i++)
    {
            oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, 0xff);
    }
    while(1)
    {
        DIAGNOSTIC_LED = HI;
        __delay_ms(100);
        DIAGNOSTIC_LED = LO;
        __delay_ms(100);
    }
}
