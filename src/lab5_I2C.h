#ifndef LAB5_I2C_H
#define LAB5_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

void lcd_cmd(char command);
void lcd_init(void);
void lcd_setCursor(char x, char y);
void lcd_printChar(char myChar);
void lcd_printStr(const char * str);

#ifdef __cplusplus
}
#endif

#endif
