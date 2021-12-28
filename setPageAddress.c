/*This function returns the page address to the caller
 * by accepting the required page number as a parameter */
#include "config.h"
uchar setPageAddress(uchar page)
{
    uchar pageAddr;
    pageAddr = page | (0b10110000);// page takes a value from 0 to 7   
    printf("pageAddr %d\n", pageAddr);
    return pageAddr;
}