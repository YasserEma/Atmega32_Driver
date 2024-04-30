
#include "StdTypes.h"
#include "DIO_interface.h"
#include "MOTOR_interface.h"
#include "MOTOR_cfg.h"


void MOTOR_Init(void)
{
	/* do nothing*/
	
}



void MOTOR_Stop(MOTOR_type motor)
{
	if (motor>NUMBER_MOTORS)
	{
		return OUT_OF_RANGE;
	}
	
	DIO_WritePin(M1_IN1,LOW);
	DIO_WritePin(M1_IN2,LOW);
	
}
void MOTOR_CW(MOTOR_type motor)
{
	DIO_WritePin(M1_IN1,HIGH);
	DIO_WritePin(M1_IN2,LOW);
}
void MOTOR_CCW(MOTOR_type motor)
{
	DIO_WritePin(M1_IN1,LOW);
	DIO_WritePin(M1_IN2,HIGH);
}