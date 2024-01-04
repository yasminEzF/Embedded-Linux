/*
 * main.c
 *
 * Created: 09-Dec-23 6:47:58 PM
 *  Author: Yasmin
 */ 
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "port.h"

int main(void)
{
	/* configure i/p & o/p pins */
	portInit();
	
	u8 u8_localVar_SwitchValue = 0;
	u8* u8_localPtr_SwitchPinValue = NULL;
	while(1)
	{
		DIO_enumError_t errorState = DIO_enumReadState(DIO_enumPortC, DIO_enumPin0, u8_localPtr_SwitchPinValue);
		if(errorState == DIO_enumOk) {
			if(!u8_localPtr_SwitchPinValue) {
				if(*u8_localPtr_SwitchPinValue) {
					u8_localVar_SwitchValue++;
					if(u8_localVar_SwitchValue == 16) {
						u8_localVar_SwitchValue = 0;
					}
					u8_localPtr_SwitchPinValue = NULL;
					do {
						errorState = DIO_enumReadState(DIO_enumPortC, DIO_enumPin0, u8_localPtr_SwitchPinValue);
					} while((errorState == DIO_enumOk) && (*u8_localPtr_SwitchPinValue));
				}
			}
		}
		
		if(GET_BIT(u8_localVar_SwitchValue, 0)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLogicLow);
		}
		if(GET_BIT(u8_localVar_SwitchValue, 1)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLogicLow);
		}
		if(GET_BIT(u8_localVar_SwitchValue, 2)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLogicLow);
		}
		if(GET_BIT(u8_localVar_SwitchValue, 3)) {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLogicHigh);
		}
		else {
			DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLogicLow);
		}
	}
}