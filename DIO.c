#include <avr/io.h>
#include "std_macros.h"

void DIO_setPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(direction==1)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if(direction==1)
		{
			SET_BIT(DDRB,pinnumber);
		}
		else
		{
				CLR_BIT(DDRB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if(direction==1)
		{
			SET_BIT(DDRC,pinnumber);
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(direction==1)
		{
			SET_BIT(DDRD,pinnumber);
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);
		}
		break;
	}
}
void DIO_writePIN(unsigned char portname,unsigned char pinnumber,unsigned char val)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if(val==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if(val==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if(val==1)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(val==1)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
	}
}
void DIO_togglePIN(unsigned char portname,unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pinnumber);
		break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pinnumber);
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pinnumber);
		break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pinnumber);
		break;
	}
}
unsigned char DIO_readPIN(unsigned char portname,unsigned char pinnumber)
{
	unsigned char val;
	switch(portname)
	{
		case 'A':
		case 'a':
		val=READ_BIT(PINA,pinnumber);
		break;
		case 'B':
		case 'b':
		val=READ_BIT(PINB,pinnumber);
		break;
		case 'C':
		case 'c':
		val=READ_BIT(PINC,pinnumber);
		break;
		case 'D':
		case 'd':
		val=READ_BIT(PIND,pinnumber);
		break;
	}
	return val;
}
void DIO_setPORTDir(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		DDRA=direction;
		break;
		case 'B':
		case 'b':
		DDRB=direction;
		break;
		case 'C':
		case 'c':
		DDRC=direction;
		break;
		case 'D':
		case 'd':
		DDRD=direction;
		break;
	}
}
void DIO_writePORT(unsigned char portname,unsigned char val)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA=val;
		break;
		case 'B':
		case 'b':
		PORTB=val;
		break;
		case 'C':
		case 'c':
		PORTC=val;
		break;
		case 'D':
		case 'd':
		PORTD=val;
		break;
	}
}
void DIO_togglePORT(unsigned char portname)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA=(~PORTA);
		break;
		case 'B':
		case 'b':
		PORTB=(~PORTB);
		break;
		case 'C':
		case 'c':
		PORTC=(~PORTC);
		break;
		case 'D':
		case 'd':
		PORTD=(~PORTD);
		break;
	}
}
unsigned char DIO_readPORT(unsigned char portname)
{
	unsigned char val;
	switch(portname)
	{
		case 'A':
		case 'a':
		val=PINA;
		break;
		case 'B':
		case 'b':
		val=PINB;
		break;
		case 'C':
		case 'c':
		val=PINC;
		break;
		case 'D':
		case 'd':
		val=PIND;
		break;
	}
	return val;
}
void DIO_pullupconnect(unsigned char portname,unsigned char pinnumber,unsigned char connect)
{
	DIO_writePIN(portname,pinnumber,connect);
}
void DIO_write_low_nibble(unsigned char portname,unsigned char val)
{
	DIO_writePIN(portname,0,READ_BIT(val,0));
	DIO_writePIN(portname,1,READ_BIT(val,1));
	DIO_writePIN(portname,2,READ_BIT(val,2));
	DIO_writePIN(portname,3,READ_BIT(val,3));
}
void DIO_write_high_nibble(unsigned char portname,unsigned char val)
{
	DIO_writePIN(portname,4,READ_BIT(val,0));
	DIO_writePIN(portname,5,READ_BIT(val,1));
	DIO_writePIN(portname,6,READ_BIT(val,2));
	DIO_writePIN(portname,7,READ_BIT(val,3));
}