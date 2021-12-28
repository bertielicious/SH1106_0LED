#include "config.h"
#include "oLedWrite.h"
void setColumnAddress(uchar columnAddr)
{
    uchar lowOffset = 0x00;     // 00000
    uchar highOffset = 0x10;    // 10000
    uchar lowNibble, highNibble;
    lowNibble = lowOffset | (columnAddr & 0x0f);
    highNibble = highOffset | ((columnAddr & 0xf0)>>4);
    printf("highNibble %d\n", highNibble);
    printf("lowNibble %d\n", lowNibble);
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, highNibble);
    oLedWrite(SH1106_WRITE_ADDRESS_COMMAND, COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW, lowNibble);
}
