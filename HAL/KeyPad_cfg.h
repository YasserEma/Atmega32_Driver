

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define  COLS    4
#define  ROWS    4


#ifdef KEYPAD_C

const   u8 KeysArray[ROWS][COLS]={  {'7','8','9','f'},
							        {'4','5','6','e'},
							        {'1','2','3','a'},
							        {'c','0','=','b'} };
#endif									  

#define  NO_KEY   'T'
						
#define  FIRST_OUTPUT  PINB4
#define  FIRST_INPUT   PIND2
						






#endif /* KEYPAD_CFG_H_ */