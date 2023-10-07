#include "DIO.h"
#include "keypad.h"

void keypad_init(unsigned char portname)
{
	DIO_setPORTDir(portname,0x0F);
	DIO_pullupconnect(portname,4,1);
	DIO_pullupconnect(portname,5,1);
	DIO_pullupconnect(portname,6,1);
	DIO_pullupconnect(portname,7,1);
}
unsigned char keypad_read(unsigned char portname)
{
	unsigned char arr[4][4]={ {'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'} };
	unsigned char row,col;
	unsigned char val=NOT_PRESSED;
	for(row=0;row<=3;row++)
	{
		DIO_write_low_nibble(portname,0xF);
		DIO_writePIN(portname,row,0);
		for(col=0;col<=3;col++)
		{
			if(DIO_readPIN(portname,col+4)==0)
			{
				val=arr[row][col];
				break;
			}
		}
		if(val != NOT_PRESSED)
		{
			break;
		}
	}
	return val;
}