#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "ap/Trafficsignal/Trafficsignal.h"

int main(void)
{
	TrafficSignal_init();
	
	while (1)
	{
		TrafficSignal_run();
	}
}
