#include "xc.h"
#include "lab5_I2C.h"
#include "Lab5_asmLib_v001.h"

#pragma config ICS = PGx1
#pragma config FWDTEN = OFF
#pragma config GWRP = OFF
#pragma config GCP = OFF
#pragma config JTAGEN = OFF
#pragma config I2C1SEL = PRI
#pragma config IOL1WAY = OFF
#pragma config OSCIOFNC = ON
#pragma config FCKSM = CSECME
#pragma config FNOSC = FRCPLL

#define LED LATBbits.LATB5
#define RESET LATBbits.LATB6

void pic24_init(void);
void delay_ms(int ms);
void setup(void);

int main(void) {
    TRISBbits.TRISB6 = 0;
    TRISBbits.TRISB5 = 0;
    LED = 0;

    pic24_init();
    setup();
    lcd_init();

    char message[] = " Welcome Gophers! ";
    int len = 0;
    while (message[len] != '\0') {
        len++;
    }

    int scrollIndex = 0;

    lcd_setCursor(1, 0);
    lcd_printStr("Tamir!");

    while (1) {
        lcd_setCursor(0, 1);

        for (int i = 0; i <= 10; i++) {
            int charIndex = (scrollIndex + i) % len;
            lcd_printChar(message[charIndex]);
        }

        scrollIndex = (scrollIndex + 1) % len;
        delay_ms(400);
    }

    return 0;
}

void delay_ms(int ms) {
    for (int i = 0; i < ms; i++) {
        M_wait_1ms();
    }
}

void pic24_init(void) {
    _RCDIV = 0;
    AD1PCFG = 0xffff;
}

void setup(void) {
    delay_ms(2);
    RESET = 1;
    delay_ms(2);
    RESET = 0;
    delay_ms(2);
    RESET = 1;
    delay_ms(2);
}
