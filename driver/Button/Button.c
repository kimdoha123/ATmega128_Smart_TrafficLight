#include "button.h"


void Button_inti(button_t *btn, volatile uint8_t* ddr, volatile uint8_t* pin, uint8_t pinNum)
{
	btn->DDR = ddr;
	btn->PIN = pin;
	btn->pinNum = pinNum;
	btn->prevState = 1;
	*btn->DDR &= ~(1<<btn->pinNum);
}


uint8_t button1(button_t* btn)
{
	uint8_t curState = *btn->PIN & (1<<btn->pinNum);
	if((curState == 0) && (btn->prevState == 1))
	{
		_delay_ms(10);
		btn->prevState = 0;
		return 1;
	}
	else if ((curState != 0) && (btn->prevState == 0))
	{
		_delay_ms(10);
		btn->prevState = 1;
		return 0;
	}
	return 2;
}
