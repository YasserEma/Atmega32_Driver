
#include "StdType.h"
#include "UART.h"
#include "UART_Services.h"



/* synch function */
void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
		
	}
}

void UART_ReceiveString(u8*str)
{	
	u8 i=0;
	str[i]=UART_Receive();
	for (;str[i]!=0x0d;)
	{
		i++;
		str[i]=UART_Receive();	
	}
	str[i]=0;

}

void UART_SendNumber(u32 num)
{
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
    UART_Send((u8)(num>>24));
	
	u8*p=&num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
	
}

void UART_ReceiveNumber(u32*pnum)
{
	u32 num=0;
	u8 b1=UART_Receive();
	u8 b2=UART_Receive();
	u8 b3=UART_Receive();
	u8 b4=UART_Receive();
	num=(u32)b1|(u32)b2<<8|(u32)b3<<16|(u32)b4<<24;
	u8*p=&num;
	p[0]=UART_Receive();
	p[1]=UART_Receive();
	p[2]=UART_Receive();
	p[3]=UART_Receive();
}


#define  LITTLE 1
#define  BIG    0

u8 endian_check(void)
{
	u32 x=1;
	u8*p=&x;
	if (*p==1)
	{
		return LITTLE;
	}
	else
	{
		return BIG;
	}
}

u32 endian_convert(u32 num)
{
		return  (num<<24)|(num>>24)|((num>>8)&(0x0000ff00))|((num<<8)&(0x00ff0000));		
}
u16 endian_convert_16(u16 num)
{
	return  (num<<8)|(num>>8);
}


void diagCallOut(u8*data)
{
	
	
}


void UART_SendStringCheckSum(u8*str)
{
	u8 len=0;
	u16 sum=0;
	for (len=0;str[len];len++)
	{
		
	}
	UART_Send(len);
	for (len=0;str[len];len++)
	{
		UART_Send(str[len]);
		sum+=str[len];
	}
	UART_Send((u8)sum);
	UART_Send((u8)(sum>>8));
	
	
}


u8 UART_ReceiveStringCheckSum(u8*str)
{
	u8 i,len,b0,b1;
	u16 sum_rec=0,sum_calc=0;
	len=UART_Receive();
	for (i=0;i<len;i++)
	{
		str[i]=UART_Receive();
		sum_calc+=str[i];
	}
	b0=UART_Receive();
	b1=UART_Receive();
	sum_rec=(u16)b0|(u16)(b1<<8);
	if (sum_rec==sum_calc)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
	
}

static u8*TX_Str[10];
static u8 flag=1;
static u8 i=0;
void func_tx(void)
{
	static u8 j=1;
	static u8 i=0;
	if (TX_Str[i][j])
	{
		UART_SendNoBlock(TX_Str[i][j]);
		j++;
	}
	else
	{
		j=1;
		i++;
	}
}

void UART_SendStringAshync(u8*str)
{
	static u8 i=0;
	UART_TX_SetCallBack(func_tx);
	
	UART_TX_InterruptEnable();
	
	UART_SendNoBlock(str[0]);
	TX_Str[i]=str;
	
	i++;
}


void func_tx2(void)
{
	flag=1;
}

void UART_SendStringInit(void)
{
	UART_TX_SetCallBack(func_tx2);
	UART_TX_InterruptEnable();
}

void UART_SendStringRunnable(void)
{
	static u8 j=0;
	static u8 i=0;
	if (flag==1)
	{
		if (TX_Str[i][j])
		{
			UART_SendNoBlock(TX_Str[i][j]);
			j++;
		}
		else
		{
			j=0;
			i++;
		}
		flag=0;
	}
		
}

void UART_SendStringSetter(u8*str)
{
	TX_Str[i]=str;
	i++;
}

u8* RXStr;
u8 changeflag;
static void func_Rx(void)
{
	static u8 i=0;
	if (changeflag==1)
	{
		i=0;
		changeflag=0;
	}
	RXStr[i]=UART_ReceiveNoBlock();
	i++;
}
void UART_ReceiveStringAshync(u8*str)
{
	UART_RX_SetCallBack(func_Rx);
	
	UART_RX_InterruptEnable();
	if (str!=RXStr)
	{
		changeflag=1;
	}
	RXStr=str;
}


u8 RX_Buffer1[8];
u8 RX_Buffer2[8];
static u8 Bufferflag=0;
u8 readyflag=0;
static void func_Rx2(void)
{
	static u8 i=0;
	
	if (Bufferflag==0)
	{
		RX_Buffer1[i]=UART_ReceiveNoBlock();
	}
	else
	{
		RX_Buffer2[i]=UART_ReceiveNoBlock();
	}
	i++;
	if (i==8)
	{
		i=0;
		readyflag=1;
		Bufferflag^=1;
	}
	
}

void UART_BufferInit(void)
{
	UART_RX_SetCallBack(func_Rx2);
	
	UART_RX_InterruptEnable();
}

u8 UART_BufferGetter(u8*str)
{
	u8 i;
	if (readyflag==0)
	{
		return 0;
	}
	for (i=0;i<8;i++)
	{
		if (Bufferflag==0)
		{
			str[i]=RX_Buffer2[i];
		}
		else
		{
			str[i]=RX_Buffer1[i];
		}
	}
	readyflag=0;
	return 1;
}