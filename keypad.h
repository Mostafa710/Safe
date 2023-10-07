#ifndef KEYPAD_H_
#define KEYPAD_H_

#define NOT_PRESSED 0xFF

void keypad_init(unsigned char portname);
unsigned char keypad_read(unsigned char portname);

#endif