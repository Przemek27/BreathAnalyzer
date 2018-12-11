/*
 * main.c
 *
 *  Created on: 18.11.2018
 *      Author: Przemek
 */

#include <avr\io.h>

#include "adc.h"
#include "port.h"
#include "uart.h"
#include "utils.h"

int main(void){
	uint16_t measure;
	char temp[3];

	portInit();
	adcInit();
	uartInit(4800);

	uartTransmit('H');
	uartTransmit('e');
	uartTransmit('l');
	uartTransmit('l');
	uartTransmit('o');
	uartTransmit('\n');
	uartTransmit('\r');

	measure = adcMeasure();

	//send data via UART
	convertToChar(measure, temp);
	uartTransmit(temp[2]);
	uartTransmit(temp[1]);
	uartTransmit(temp[0]);
	uartTransmit('\n');
	uartTransmit('\r');
	convertToChar(measure >> 8, temp);
	uartTransmit(temp[2]);
	uartTransmit(temp[1]);
	uartTransmit(temp[0]);
	uartTransmit('\n');
	uartTransmit('\r');

	while(1){

	}

	return 0;
}
