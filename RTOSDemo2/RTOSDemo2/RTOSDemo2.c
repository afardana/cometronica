/*
 * RTOSDemo2.c
 *
 * Created: 24/02/2014 23:24:07
 *  Author: Angga
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "Tombol.h"
#include "LED.h"

#define LED1 PB0
#define LED2 PB1
#define LED_PORT PORTB

uint8_t tombol1, tombol2;

// Kerangka fungsi untuk tasks
void vTaskTombol(void * vParam);
void vTaskLED1(void * vParam);
void vTaskLED2(void * vParam);

int main(void)
{
	// Inisialisasi port
	vSetupTombol();
	vSetupLED();
	
	// Buat task yang akan dikerjakan
	xTaskCreate( vTaskTombol, ( const char * ) "Tombol", configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	xTaskCreate( vTaskLED1, ( const char * ) "LED1", configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	xTaskCreate( vTaskLED2, ( const char * ) "LED2", configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	
	vTaskStartScheduler();
	
    return 0;
}

void vTaskTombol(void * vParam)
{
	while (1)
	{
		// Cek keadaan tombol, masukkan keadaan tombol ke variabel tombol1
		tombol1 = PINA & ( 1<<PA0 );
		tombol2 = PINA & ( 1<<PA1 );
	}
}

void vTaskLED1(void * vParam)
{
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	const portTickType xFrequency = 1000; // Berapa lama
	
	while (1)
	{
		// Hidupkan LED sesuai keadaan tombol1 & tombol2
		if (tombol1 == 0)
		{
			do
			{
				// Led flip-flop ke-1 hidup
				LED_PORT |= ( 1<<LED1 );
				
				// Fungsi delay sampai waktu yang ditentukan
				vTaskDelayUntil( &xLastWakeTime, xFrequency );
				
				// Matikan LED1
				LED_PORT &= ~( 1<<LED1 );
				
				// Fungsi delay sampai waktu yang ditentukan
				vTaskDelayUntil( &xLastWakeTime, xFrequency );
			}
			while (tombol2 != 0);
			
			// Matikan LED1
			LED_PORT &= ~( 1<<LED1 );
		}
		
		vTaskDelayUntil( &xLastWakeTime, (portTickType) 1 );
	}
}

void vTaskLED2(void * vParam)
{
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	const portTickType xFrequency = 1000; // Berapa lama
	
	while (1)
	{
		// Led flip-flop ke-2 hidup
		LED_PORT |= ( 1<<LED2 );
		
		// Fungsi delay sampai waktu yang ditentukan
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
		
		// Matikan LED2
		LED_PORT &= ~( 1<<LED2 );
		
		// Fungsi delay sampai waktu yang ditentukan
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}