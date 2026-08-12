# I2C LCD Driver - PIC24FJ64GA002

I2C driver for DOGS104 LCD on PIC24FJ64GA002. Written from scratch for EE2361 Lab 5.

## Features
- I2C protocol (START, STOP, ACK, NACK)
- LCD initialization
- Cursor positioning
- Character and string printing
- Scrolling text animation

## Hardware
- PIC24FJ64GA002
- DOGS104 I2C LCD
- 4.7kΩ pull-ups on SCL/SDA

## Functions
- `lcd_init()` - Initialize LCD
- `lcd_cmd(char)` - Send command
- `lcd_setCursor(x,y)` - Set cursor position
- `lcd_printChar(char)` - Print character
- `lcd_printStr(const char*)` - Print string

## Wiring
<img width="569" height="397" alt="image" src="https://github.com/user-attachments/assets/d14d3e9b-cfbd-440d-9016-8088d1df31fe" />


EE2361 - Introduction to Microcontrollers (Fall 2025)
