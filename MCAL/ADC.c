
#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "ADC.h"



void ADC_Init(ADC_Vref_type vref,ADC_Prescaler_type scaler)
{
	/* clock*/ 
	scaler=scaler&0x07; //00000111
	ADCSRA=ADCSRA&0xf8; //11111000
	ADCSRA=ADCSRA|scaler;
	/* volt ref */
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;	
	}
	CLR_BIT(ADMUX,ADLAR);
	
	/* ADC ENABLE*/
	SET_BIT(ADCSRA,ADEN);
}

u16 ADC_Read(ADC_Channel_type ch)
{
	u16 adc;
	u8 adcl,adch;
	/* select channel*/
	/* start conversion */
	/* w8 until finish */
	/* get read */
	/*adcl=ADCL;
	adch=ADCH;
	
	adc=adch<<8 |adcl;*/
	adc=ADC;
}

