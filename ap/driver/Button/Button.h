#ifndef BUTTON_H_
#define  BUTTON_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

enum {PUSHED, RELEASED};
enum {ACT_PUSHED, ACT_RELEASED, ACT_NONE};

typedef struct _button
#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>

typedef struct _button
{
	volatile uint8_t *DDR;  // port 정보
	volatile uint8_t *PIN; // pin number 정보
	uint8_t pinNum;
	uint8_t prevState; // static prevState
}button_t;


void Button_inti(button_t *btn, volatile uint8_t* ddr, volatile uint8_t* pin, uint8_t pinNum);
uint8_t Button_GetState(button_t* btn);

#endif
