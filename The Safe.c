#include "LCD.h"
#include "EEPROM.h"
#include "keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define EEPROM_STATUS_LOCATION 0x10
#define EEPROM_PASS_LOCATION1 0x11
#define EEPROM_PASS_LOCATION2 0x12
#define EEPROM_PASS_LOCATION3 0x13
#define EEPROM_PASS_LOCATION4 0x14
#define MAX_TRIES 3

int main(void)
{
	keypad_init('D');
	LCD_init();
	char i,val;
	signed char tries=MAX_TRIES,flag=0;
	char arr[4]={0xFF,0xFF,0xFF,0xFF};
    while(1)
    {
		if(EEPROM_read(EEPROM_STATUS_LOCATION)==0xFF)
		{
			LCD_send_string("Set Pass:");
			for(i=0;i<=3;i++)
			{
				do 
				{
					val=keypad_read('D');
				} while (val==NOT_PRESSED);
				LCD_send_char(val);
				EEPROM_write(EEPROM_PASS_LOCATION1+i,val);
				_delay_ms(500);
				LCD_send_cmd(0x10);
				LCD_send_char('*');
			}
			EEPROM_write(EEPROM_STATUS_LOCATION,0x00);
			_delay_ms(500);
		}
		while(flag==0)
		{
			LCD_clear_screen();
			LCD_send_string("Check Pass:");
			for(i=0;i<=3;i++)
			{
				do
				{
					arr[i]=keypad_read('D');
				} while (arr[i]==NOT_PRESSED);
				LCD_send_char(arr[i]);
				_delay_ms(500);
				LCD_send_cmd(0x10);
				LCD_send_char('*');
			}
			if(arr[0]==EEPROM_read(EEPROM_PASS_LOCATION1) && arr[1]==EEPROM_read(EEPROM_PASS_LOCATION2) && arr[2]==EEPROM_read(EEPROM_PASS_LOCATION3) && arr[3]==EEPROM_read(EEPROM_PASS_LOCATION4))
			{
				LCD_clear_screen();
				LCD_send_string("Correct Password");
				LCD_move_cursor(2,1);
				LCD_send_string("Safe is opened");
				flag=1;
			}
			else
			{
				tries--;
				if(tries>0)
				{
					LCD_clear_screen();
					LCD_send_string("Wrong Password");
					_delay_ms(1000);
					LCD_clear_screen();
					LCD_send_string("Tries left:");
					LCD_send_char(tries+48);
					_delay_ms(1000);
				}
				else
				{
					LCD_clear_screen();
					LCD_send_string("Wrong Password");
					LCD_move_cursor(2,1);
					LCD_send_string("Safe is closed");
					flag=1;
				}
			}
		}
    }
}