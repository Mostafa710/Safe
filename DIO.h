#ifndef DIO_H_
#define DIO_H_

void DIO_setPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction);
void DIO_writePIN(unsigned char portname,unsigned char pinnumber,unsigned char val);
void DIO_togglePIN(unsigned char portname,unsigned char pinnumber);
unsigned char DIO_readPIN(unsigned char portname,unsigned char pinnumber);
void DIO_setPORTDir(unsigned char portname,unsigned char direction);
void DIO_writePORT(unsigned char portname,unsigned char val);
void DIO_togglePORT(unsigned char portname);
unsigned char DIO_readPORT(unsigned char portname);
void DIO_pullupconnect(unsigned char portname,unsigned char pinnumber,unsigned char connect);
void DIO_write_low_nibble(unsigned char portname,unsigned char val);
void DIO_write_high_nibble(unsigned char portname,unsigned char val);

#endif