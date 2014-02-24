/*
 * LEDdriver.c
 *
 * Created: 23/02/2014 1:22:36
 *  Author: Angga
 */ 

#include <avr/io.h>

void vLEDInit()
{
	DDRB = ( 1<<DDB1 | 1<<DDB0 ); // Sama dengan DDRB = 0b00000001;
	//PORTB |= ( 1<<PB0 ); // Mengaktifkan pull-up pada PORTB PIN0
	//PORTB &= ~( 1<<PB0 ); // Mematikan pull-up pada PORTB PIN0
}

void vLEDToggle()
{
	PORTB ^= ( 1<<PB0 ); // Membalik kondisi PB0
}

void vLED2Toggle()
{
	PORTB ^= ( 1<<PB1 ); // Membalik kondisi PB1
}