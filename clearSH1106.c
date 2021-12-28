#include "config.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "oLedWrite.h"
void clearSH1106(void)
{
    uchar col,page;
    uchar pageAddress;
    setColumnAddress(0);
    for(page = 0; page<8; page++)
    {
        pageAddress = setPageAddress(page);
        oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, pageAddress);
        for(col = 0; col < SH1106_LCD_WIDTH; col++)
        {
            oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW, 0x00); // write display data 0x00 to all segments
        }
    }
           
}
