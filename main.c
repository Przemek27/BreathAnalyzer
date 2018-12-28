/*
 * main.c
 *
 *  Created on: 18.11.2018
 *      Author: Przemek
 */

#include <avr\io.h>
#include <stdio.h>

#include "Includes/adc.h"
#include "Includes/port.h"
#include "Includes/uart.h"
#include "Includes/utils.h"
#include "Includes/measure.h"

int main(void){
	uint32_t measure;
	char *temp = "    ";

	portInit();
	adcInit();
	uartInit(4800);

	uartSendString("Hello world\n\r", 14);

	measure = adcMeasure();

	sprintf(temp,"%u",measure);

	//send data via UART
	uartSendString(temp,4);
	uartSendChar('\n');
	uartSendChar('\r');

	while(1){
		measure = performMeasure();
		//TODO: light on LEDs
		//% BAC = breath mg/L * 0.21
		//TODO: save record in EEPROM
	}

	return 0;
}
