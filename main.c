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


int main(void){

	portInit();
	adcInit();
	uartInit(4800);

	uartTransmit('t');
	uartTransmit('e');
	uartTransmit('s');
	uartTransmit('t');
	uartTransmit('\n');
	uartTransmit('\r');

	while(1){
		//wait for measurement trigger
		//adcStart();
		//wait for conversion finish
		//send data via UART
	}

	return 0;
}
