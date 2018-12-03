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
	uartInit();
	//

	while(1){
		//wait for measurement trigger
		//adcStart();
		//wait for conversion finish
		//send data via UART
	}

	return 0;
}
