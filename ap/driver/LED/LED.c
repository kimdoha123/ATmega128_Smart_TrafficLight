#include "LED.h"

uint8_t LED_PORT;

void LED_inti()
{
	LED_DDR = 0xff;
}


//LED all on
void LED_allon()
{
	LED_PORT = 0xff;
}

// data 전달 받아서 그 data 값으로 on
void LED_writeData(uint8_t data)
{
	LED_PORT = data;
}
