ISR(TIMER0_OVF_vect)
{
	
	DIO_TogglePin(PINA2);
	TCNT0=156;
}
/*
ISR(TIMER0_OVF_vect)
{
	static u16 c=0;
	static u16 c2=0;
	c++;
	c2++;
	if (c==3906)
	{
		DIO_TogglePin(PINC0);
		c=0;
	}
	if (c2==1953)
	{
		DIO_TogglePin(PINC1);
		c2=0;
	}

}
*/
/*
ISR(TIMER0_OVF_vect)
{
	static u16 c=0;
    TCNT0=6;
	c++;
	
	if (c==10)
	{
		DIO_WritePin(PINC0,HIGH);
	}
	else if (c==40)
	{
		DIO_WritePin(PINC0,LOW);
		c=0;
	}

}*/
/*
ISR(TIMER0_OVF_vect)
{
	static u16 flag=0;

	if (flag==0)
	{
		TCNT0=236;
		DIO_WritePin(PINC0,HIGH);
		flag=1;
	}
	else if (flag==1)
	{
		TCNT0=176;
		DIO_WritePin(PINC0,LOW);
		flag=0;
	}

}
*/

ISR(TIMER0_OVF_vect)
{
	static u16 c=0;
	TCNT0=236;
	c++;
	
	if (c==4)
	{
		DIO_WritePin(PINC0,HIGH);
	}
	else if (c==5)
	{
		DIO_WritePin(PINC0,LOW);
		c=0;
	}

}
/*
ISR(TIMER0_OVF_vect)
{
	static u16 c=0;

	c++;
	
	if (c==3907)
	{
		TCNT0=192;
		DIO_TogglePin(PINC0);
		c=0;
	}
	

}
*/
/*
ISR(TIMER0_OVF_vect)
{
	static u16 c=0;
  TCNT0=6;
	c++;
	
	if (c==4000)
	{
		DIO_TogglePin(PINC0);
		c=0;
	}
	

}
*/
