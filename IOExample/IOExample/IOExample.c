/*
 * IOExample.c
 *
 * Created: 21/02/2014 17:41:52
 *  Author: Angga
 */

#define F_CPU 16000000UL
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define t1 250
#define t2 125

volatile uint8_t time1, time2;
uint8_t led;

void task1();
void task2();
void init();

ISR (TIMER0_COMP_vect)
{
	if (time1>0) time1--;
	if (time2>0) time2--;
}

int main(void)
{
	init();
	
	PORTA &= ~(1<<PA0);
	
	while (1)
	{
		if (time1 == 0) { time1 = t1; task1(); }
		if (time2 == 0) { time2 = t2; task2(); }
	}
}

void task1()
{
	led = led ^ 0x01;
	PORTB = led;
}

void task2()
{
	led = led ^ 0x02;
	PORTB = led;
}

void init()
{
	DDRA = (1<<DDA0);
	PORTA |= (1<<PA0);
	DDRB = (1<<DDB4 | 1<<DDB1 | 1<<DDB0);
	
	// Set timer0 for 1 mSec timebase
	OCR0 = 0xF9;
	TCCR0 = (1<<WGM01 | 1<<CS02); // Set prescaler to 64 with CTC mode on timer 0
	TIMSK = (1<<OCIE0); // Turn on Output Compare Match 0 ISR
	
	led = 0x00;
	time1 = t1;
	time2 = t2;
	sei();
}