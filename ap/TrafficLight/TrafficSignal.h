
#ifndef TRAFFICSIGNAL_H_
#define TRAFFICSIGNAL_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "../../driver/Button/Button.h"
#include "../../driver/LED/LED.h"

#define		TRAFFIC_LED_DDR				DDRF
#define		TRAFFIC_LED_PORT			PORTF
#define		TRAFFIC_LED_PIN				PINF
#define		TRAFFIC_BUTTON_DDR			DDRA
#define		TRAFFIC_BUTTON_PORT			PORTA
#define		TRAFFIC_BUTTON_PIN			PINA

#define		TRAFFIC_BUTTON_AUTO			0
#define		TRAFFIC_BUTTON_MANUAL		1
#define		TRAFFIC_BUTTON_CONTROL		2

#define		TRAFFIC_LIGHT_VRED			2
#define		TRAFFIC_LIGHT_VYELLOW		1
#define		TRAFFIC_LIGHT_VGREEN		0

#define		TRAFFIC_LIGHT_HRED			7
#define		TRAFFIC_LIGHT_HYELLOW		6
#define		TRAFFIC_LIGHT_HGREEN		5
enum {AUTO, MANUAL};
enum {RED_GREEN, RED_YELLOW, GREEN_RED, YELLOW_RED};
	
	
void LED_init();

void Button_init();

void TrafficSignal_AUTO();
void TrafficSignal_MANUAL();
void TrafficSignal_REDGREEN();
void TrafficSignal_REDYELLOW();
void TrafficSignal_GREENRED();
void TrafficSignal_YELLOWRED();



#endif /* TRAFFICSIGNAL_H_ */
