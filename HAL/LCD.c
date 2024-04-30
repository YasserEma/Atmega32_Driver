
#include "StdTypes.h"
#include "DIO_interface.h"
#include "LCD.h"

#define  F_CPU 8000000
#include <util/delay.h>



static void WriteIns(u8 ins)
{
	
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


static void WriteData(u8 data)
{
	
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0X38);
	WriteIns(0X0c);//0x0e,0x0f cursor
	WriteIns(0X01);//clear screen
	_delay_ms(1);
	WriteIns(0X06);
	
	
}
void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
	
	
}

void LCD_Clear(void)
{
	WriteIns(0X01);//clear screen
	_delay_ms(1);
}

void LCD_WriteNumber(s32 num)// 2504
{
	u8 i=0,str[16];
   s8 j;

if (num==0)
{
	LCD_WriteChar('0');
	return;
}
if (num<0)
{
	LCD_WriteChar('-');
	num=num*(-1);
}
	while(num)
	{
		str[i]=(num%10)+'0';
		num=num/10;
		i++;
	}
	for (j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
}


void LCD_WriteString(c8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

