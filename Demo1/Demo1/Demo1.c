/*
 * Demo1.c
 *
 * Created: 23/02/2014 0:28:59
 *  Author: Angga
 */ 


#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "LEDdriver.h"

#define LEDTaskPriority	1

void vLEDTask1();
void vLEDTask2();

int main()
{
	xTaskCreate( vLEDTask1, ( const char * ) "LED", configMINIMAL_STACK_SIZE, NULL, LEDTaskPriority, NULL );
	xTaskCreate( vLEDTask2, ( const char * ) "LED2", configMINIMAL_STACK_SIZE, NULL, LEDTaskPriority, NULL );
	
	// Start task scheduler
	vTaskStartScheduler();

	return 0;
}

void vLEDTask1()
{
	vLEDInit();
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	const portTickType xFrequency = 1000;
	while (1)
	{
		vLEDToggle();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

void vLEDTask2()
{
	vLEDInit();
	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	const portTickType xFrequency = 500;
	while (1)
	{
		vLED2Toggle();
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}