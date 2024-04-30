

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_


typedef enum{
	M1,
	M2,
	M3,
	M4,
	M5
	}MOTOR_type;



void MOTOR_Init(void);

void MOTOR_Stop(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor);
void MOTOR_CCW(MOTOR_type motor);
/*  speed from 0 to 100  %**/
void MOTOR_Speed(MOTOR_type motor,u8 speed);


#endif /* MOTOR_INTERFACE_H_ */