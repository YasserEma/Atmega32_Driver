
#ifndef LCD_H_
#define LCD_H_




#define  RS  PINB1
#define  EN  PINB0

#define  LCD_PORT   PA



void LCD_Init(void);

void LCD_Clear(void);
void LCD_WriteNumber(s32 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(c8*str);

void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u8 num);

void LCD_WriteNumber_4D(u16 num);

/** line 0:1  cell 0:15 **/
void LCD_SetCursor(u8 line ,u8 cell);
	


void LCD_SetCursorString(u8 line,u8 cell,u8*str);


https://drive.google.com/drive/folders/1_BeF51ffa8_V_pInf5cpwjPyjdSLC8HL?usp=share_link


#endif /* LCD_H_ */