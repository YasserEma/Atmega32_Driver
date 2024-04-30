

#include "StdType.h"
#include "MemMap.h"
#include "Utils.h"
#include "SPI.h"


void SPI_Init(SPIMode_type mode)
{
	if (mode==MASTER)
	{
		//clock 2MHZ
		SET_BIT(SPCR,MSTR);
		
	}
	else
	{
		
		CLR_BIT(SPCR,MSTR);
	}
	
	// SPI ENABLE
	SET_BIT(SPCR,SPE);
	
}


u8 SPI_SendReceive(u8 data)
{
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}


u8 SPI_ReceivePerodic(u8*pdata)
{
	if (READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}