#ifndef LCD_H_
#define LCD_H_

//SPECIFIED MACROS (Connections)
#define FOUR_BIT_MODE     //Note:In 4-bit mode, I work with the high nibble  
#define LCD_DATA_PORT 'A'
#define LCD_CTRL_PORT 'B'
#define EN 0
#define RS 1
#define RW 2

//GENERAL MACROS (Commands)
#define CLR_SCREEN 0x01
#define RET_HOME   0x02
#define ENTRY_MODE 0x06
#define DISPLAY_ON_CURSOR_ON 0x0E

//PROTOTYPES
void LCD_init();
static void Enable();
void LCD_send_cmd(char cmd);
void LCD_send_char(char data);
void LCD_clear_screen();
void LCD_return_home();
void LCD_send_string(char *ptr);
void LCD_move_cursor(char row,char column);

#endif /* LCD_H_ */