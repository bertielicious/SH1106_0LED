/* 
 * File:   config.h
 * Author: User
 *
 * Created on 06 December 2021, 14:08
 *           ___________
 *          |           |
 *          |           |
 *          |           |
 *              
 */

#ifndef CONFIG_H
#define	CONFIG_H

void config(void);

// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = ON        // Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdio.h>
#include <stdbool.h>
enum {LO, HI};
typedef unsigned char uchar;

#define _XTAL_FREQ 4000000
#define  DIAGNOSTIC_LED PORTCbits.RC7   // RC7 pin 9 is connected to DIAGNOSTIC_LED

#define SH1106_LCD_WIDTH  132
#define SH1106_LCD_HEIGHT  64
#define SH1106_WRITE_ADDRESS_COMMAND 0x78
#define SH1106_READ_ADDRESS 0x79
#define SH1106_SET_LO_COLUMN_ADDR 0x00  // RANGE 0 - 15
#define SH1106_SET_HI_COLUMN_ADDR 0x10  // RANGE 16 - 31
#define SH1106_SET_PUMP_VOLTAGE 0x33 // 9V PUMP VOLTAGE
#define SH1106_SET_DISPLAY_START_LINE 0x40  // RANGE 0X40 - 0X7F  LINES 0 TO 63 / 0X00 - 0X3F
#define SH1106_SET_CONTRAST_CTRL_MODE_SET 0x81   //ENABLES THE CONTRAST DATA REGISTER SET
#define SH1106_SET_CONTRAST_DATA_REG_SET 0x80   //SETS THE CONTRAST OF THE DISPLAY FROM 0 - 255, POR VALUE IS 0X80
#define SH1106_SET_SEGMENT_REMAP 0xA1   // RANGE 0xA0 - 0xA1 (A0 = seg0 on LHS)
#define SH1106_SET_ENTIRE_DISPLAY_ON 0xA5   //  0xA5 ON
#define SH1106_SET_ENTIRE_DISPLAY_OFF 0xA4   //  0xA4 OFF
#define SH1106_SET_NORMAL_REVERSE_DISPLAY 0xA6 // 0xA6 - 0xA7
#define SH1106_SET_DISPLAY_ON 0XAF      // 0xAF ON
#define SH1106_SET_DISPLAY_OFF 0XAE      // 0xAE OFF 
#define SH1106_SET_PAGE_ADDRESS 0xB0        // PAGE ADDRESS RANGES FROM 0xB0 TO 0xB7
#define SH1106_SET_DISPLAY_CLK_DIV 0xd5
#define SH1106_SETOSC_FREQ 0x80






/*CONTROL BYTE*/
#define COMMAND_ONE_CTRL_BYTE_ONLY_DATA_BYTES_TO_FOLLOW 0x00                         //C0 = 0   D/C = 0 HAPPY XMAS! 24/12/21
#define COMMAND_NEXT_TWO_BYTES_ARE_A_CTRL_BYTE_AND_A_DATA_BYTE 0x80                  //CO = 1   D/C = 0
#define DISPLAY_DATA_ONE_CTRL_BYTE_DATA_BYTES_TO_FOLLOW 0X40                         //C0 = 0   D/C = 1
#define DISPLAY_DATA_NEXT_TWO_BYTES_ARE_A_CTRL_BYTE_AND_A_DATA_BYTE 0xCO             //CO = 1   D/C = 1
#endif	/* CONFIG_H */

