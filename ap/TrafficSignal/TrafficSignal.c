#include "Trafficsignal.h"

button_t btnAuto, btnmanual, btnCtrl;
uint8_t trafficState;
uint32_t timeTick;
uint8_t trafficModeState;
uint8_t trafficData;



void TrafficSignal_init()
{
	trafficState =  RED_GREEN;
	timeTick = 0;
	// if PORTF 0 1 2 3 4 5
	LED_inti();
	Button_init(&btnAuto, &DDRA, &PINA, 3);
	Button_init(&btnmanual, &DDRA, &PINA, 3);
	Button_init(&btnCtrl, &DDRA, &PINA, 3);
	
	//TRAFFIC_LED_DDR = 0xff;
	
	uint8_t trafficModeState = AUTO;
	
	
	
	
	// State Running
	switch (trafficModeState)
	{
		case AUTO :
		TrafficSignal_AUTO();
		break;
		case MANUAL :
		TrafficSignal_MANUAL();
		break;
	}
	
	_delay_ms(1);
	timeTick++;
	
}

void TrafficSignal_REDGREEN()
{
	trafficData = (1<<TRAFFIC_LIGHT_VRED) | (1<<TRAFFIC_LIGHT_HGREEN);
	LED_writeData(trafficData);
}

void TrafficSignal_REDYELLOW()
{
	trafficData = (1<<TRAFFIC_LIGHT_VRED) | (1<<TRAFFIC_LIGHT_HYELLOW);
	LED_writeData(trafficData);
}

void TrafficSignal_GREENRED()
{
	trafficData = (1<<TRAFFIC_LIGHT_VGREEN) | (1<<TRAFFIC_LIGHT_HRED);
	LED_writeData(trafficData);
}

void TrafficSignal_YELLOWRED()
{
	trafficData = (1<<TRAFFIC_LIGHT_VYELLOW) | (1<<TRAFFIC_LIGHT_HRED);
	LED_writeData(trafficData);
}

//void TrafficSignal_run()
//{
	////Event Process
	//if((TRAFFIC_BUTTON_PIN & (1<<TRAFFIC_BUTTON_AUTO)) == 0)
	//{
		//trafficModeState = AUTO;
	//}
	//else if((TRAFFIC_BUTTON_PIN & (1<<TRAFFIC_BUTTON_MANUAL)) == 0)
	//{
		//trafficModeState = MANUAL;
	//}
	//
//}
void TrafficSignal_AUTO()
{
	static uint32_t prevTime = 0;
	
	switch(trafficState)
	{
		case RED_GREEN :
		TrafficSignal_REDGREEN();
		if(timeTick - prevTime >= 3000)
		{
			timeTick = 0;
			trafficState = RED_YELLOW;
		}
		break;
		case RED_YELLOW :
		TrafficSignal_REDYELLOW();
		if(timeTick - prevTime >= 1000)
		{
			timeTick = 0;
			trafficState = RED_YELLOW;
		}
		trafficState = GREEN_RED;
		break;
		case GREEN_RED :
		TrafficSignal_GREENRED();
		if(timeTick - prevTime >= 3000)
		{
			timeTick = 0;
			trafficState = RED_YELLOW;
		}
		trafficState = YELLOW_RED;
		break;
		case YELLOW_RED :
		TrafficSignal_YELLOWRED();
		if(timeTick - prevTime >= 1000)
		{
			timeTick = 0;
			trafficState = RED_YELLOW;
		}
		trafficState = RED_GREEN;
		break;
	}
}

void TrafficSignal_MANUAL()
{
	switch(trafficState)
	{
		case RED_GREEN :
		TrafficSignal_REDGREEN();
		if(Button_GetState(&btnCtrl) == 1)
		{
			trafficState = RED_YELLOW;
		}
		break;
		case RED_YELLOW :
		TrafficSignal_REDYELLOW();
		if(Button_GetState(&btnCtrl) == 1)
		{
			trafficState = GREEN_RED;
		}
		break;
		case GREEN_RED :
		TrafficSignal_GREENRED();
		if(Button_GetState(&btnCtrl) == 1)
		{
			trafficState = YELLOW_RED;
		}
		break;
		case YELLOW_RED :
		TrafficSignal_YELLOWRED();
		if(Button_GetState(&btnCtrl) == 1)
		{
			trafficState = RED_GREEN;
		}
		break;
	}
	
}
