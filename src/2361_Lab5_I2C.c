#include "xc.h"
#include "lab5_I2C.h"
#include "Lab5_asmLib_v001.h"

#define LED LATBbits.LATB5

void _delay_ms(int ms) {
    for (int i = 0; i < ms; i++) {
        M_wait_1ms();
    }
}

void lcd_init(void) {
    I2C1CONbits.I2CEN = 0;
    I2C1BRG = 199;
    _MI2C1IF = 0;
    I2C1CONbits.I2CEN = 1;

    _delay_ms(40);

    lcd_cmd(0b00111010);
    lcd_cmd(0b00001001);
    lcd_cmd(0b00000110);
    lcd_cmd(0b00011110);
    _delay_ms(40);
    lcd_cmd(0b00111001);
    lcd_cmd(0b00011011);
    lcd_cmd(0b01101110);
    lcd_cmd(0b01010110);
    lcd_cmd(0b01111010);

    _delay_ms(40);
    lcd_cmd(0x38);
    lcd_cmd(0x0F);

    _delay_ms(40);

    lcd_cmd(0x3a);
    lcd_cmd(0x09);
    lcd_cmd(0x1a);
    lcd_cmd(0x3c);
    lcd_cmd(0x01);

    _delay_ms(1);
}

void lcd_cmd(char command) {
    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN);

    _MI2C1IF = 0;

    I2C1TRN = 0b01111000;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    _MI2C1IF = 0;
    I2C1TRN = 0x00;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    _MI2C1IF = 0;
    I2C1TRN = command;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN);
}

void lcd_setCursor(char x, char y) {
    char position;
    if (y == 0) {
        position = 0x00 + x;
    } else {
        position = 0x20 + x;
    }

    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN);

    _MI2C1IF = 0;

    I2C1TRN = 0b01111000;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    _MI2C1IF = 0;
    I2C1TRN = 0x00;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    _MI2C1IF = 0;
    I2C1TRN = 0x80 | position;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN);
}

void lcd_printChar(char myChar) {
    LED = 1;

    I2C1CONbits.SEN = 1;
    while (I2C1CONbits.SEN);

    _MI2C1IF = 0;

    I2C1TRN = 0b01111000;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    _MI2C1IF = 0;
    I2C1TRN = 0x40;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    _MI2C1IF = 0;
    I2C1TRN = myChar;
    while (I2C1STATbits.TRSTAT);
    while (!_MI2C1IF);

    I2C1CONbits.PEN = 1;
    while (I2C1CONbits.PEN);

    LED = 0;
}

void lcd_printStr(const char *str) {
    while (*str != '\0') {
        lcd_printChar(*str);
        str++;
    }
}
