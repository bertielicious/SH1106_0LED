#include "config.h"
void i2cWrite(uchar byte)
{
    SSP1BUF = byte;                 // byte is 7 bit address, RW bit is 0 (write) or 1 (read))
    while(PIR1bits.SSP1IF == LO);   // wait for all 8 bits to be sent to slave
    PIR1bits.SSP1IF = LO;           // clear SSP1IF interrupt flag
}
