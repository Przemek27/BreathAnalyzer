/*
 * main.c
 *
 *  Created on: 18.11.2018
 *      Author: Przemek
 */

#include <avr\io.h>

#include "Includes/adc.h"
#include "Includes/port.h"
#include "Includes/uart.h"
#include "Includes/utils.h"

int main(void){
	uint16_t measure;
	char temp[3];

	portInit();
	adcInit();
	uartInit(4800);

	uartSendString("Hello world\n\r", 14);

	measure = adcMeasure();

	//send data via UART
	convertToChar(measure, temp);
	uartSendChar(temp[2]);
	uartSendChar(temp[1]);
	uartSendChar(temp[0]);
	uartSendChar('\n');
	uartSendChar('\r');
	convertToChar(measure >> 8, temp);
	uartSendChar(temp[2]);
	uartSendChar(temp[1]);
	uartSendChar(temp[0]);
	uartSendChar('\n');
	uartSendChar('\r');

	while(1){
		//if button pushed
		//trigger adc
		//TODO: average out measure
	}

	return 0;
}
