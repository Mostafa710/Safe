#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"

void LCD_init()
{
	_delay_ms(150);
	#if defined EIGHT_BIT_MODE
	DIO_setPORTDir(LCD_DATA_PORT,0xFF);
	DIO_setPINDir(LCD_CTRL_PORT,EN,1);
	DIO_setPINDir(LCD_CTRL_PORT,RS,1);
	DIO_setPINDir(LCD_CTRL_PORT,RW,1);
	DIO_writePIN(LCD_CTRL_PORT,RW,0);
	LCD_send_cmd(0x38);
	#elif defined FOUR_BIT_MODE
	DIO_setPINDir(LCD_DATA_PORT,4,1);
	DIO_setPINDir(LCD_DATA_PORT,5,1);
	DIO_setPINDir(LCD_DATA_PORT,6,1);
	DIO_setPINDir(LCD_DATA_PORT,7,1);
	DIO_setPINDir(LCD_CTRL_PORT,EN,1);
	DIO_setPINDir(LCD_CTRL_PORT,RS,1);
	DIO_setPINDir(LCD_CTRL_PORT,RW,1);
	DIO_writePIN(LCD_CTRL_PORT,RW,0);
	LCD_return_home();
	LCD_send_cmd(0x28);
	#endif
	LCD_send_cmd(DISPLAY_ON_CURSOR_ON);
	LCD_clear_screen();
	LCD_send_cmd(ENTRY_MODE);
}
static void Enable()
{
	DIO_writePIN(LCD_CTRL_PORT,EN,1);
	_delay_ms(2);
	DIO_writePIN(LCD_CTRL_PORT,EN,0);
	_delay_ms(2);
}
void LCD_send_cmd(char cmd)
{
	#if defined EIGHT_BIT_MODE
	DIO_writePIN(LCD_CTRL_PORT,RS,0);
	DIO_writePORT(LCD_DATA_PORT,cmd);
	Enable();
	#elif defined FOUR_BIT_MODE
	DIO_writePIN(LCD_CTRL_PORT,RS,0);
	DIO_write_high_nibble(LCD_DATA_PORT,cmd>>4);
	Enable();
	DIO_write_high_nibble(LCD_DATA_PORT,cmd);
	Enable();
	#endif
	_delay_ms(1);
}
void LCD_send_char(char data)
{
	#if defined EIGHT_BIT_MODE
	DIO_writePIN(LCD_CTRL_PORT,RS,1);
	DIO_writePORT(LCD_DATA_PORT,data);
	Enable();
	#elif defined FOUR_BIT_MODE
	DIO_writePIN(LCD_CTRL_PORT,RS,1);
	DIO_write_high_nibble(LCD_DATA_PORT,data>>4);
	Enable();
	DIO_write_high_nibble(LCD_DATA_PORT,data);
	Enable();
	#endif
	_delay_ms(1);
}
void LCD_clear_screen()
{
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(9);
}
void LCD_return_home()
{
	LCD_send_cmd(RET_HOME);
	_delay_ms(9);
}
void LCD_send_string(char *ptr)
{
	while( (*ptr) != 0)
	{
		LCD_send_char(*ptr);
		ptr++;
	}
}
void LCD_move_cursor(char row,char column)
{
	char data;
	if(row>2 || row<1 || column>16 || column<1)
	{
		data=0x80;
	}
	else if(row == 1)
	{
		data = 0x80 + column - 1;
	}
	else if(row == 2)
	{
		data = 0xC0 + column - 1;
	}
	LCD_send_cmd(data);
}