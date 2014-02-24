/*
 * LED.c
 *
 * Created: 25/02/2014 0:27:04
 *  Author: Angga
 */ 

#include <avr/io.h>

void vSetupLED()
{
	// Setup LED sebagai output di PORTB PIN 0 & PIN 1
	DDRB = ( 1<<DDB1 | 1<<DDB0 );
}