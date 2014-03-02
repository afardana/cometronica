/*
 * Tombol.c
 *
 * Created: 24/02/2014 23:48:57
 *  Author: Angga
 */ 

#include <avr/io.h>

void vSetupTombol()
{
	// Tombol di PORT A PIN 0 dan PIN 1 sebagai input
	DDRA &= ~( 1<<DDA1 | 1<<DDA0 );
	
	// Aktifkan pull-up untuk tombol
	PORTA |= ( 1<<PA1 | 1<<PA0 );
}