/*
 * uart.c
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#include <avr\io.h>

#include "uart.h"

void uartInit(void)
{
	UCSRA= 0x00;                 // Clear the UASRT status register
    UCSRB= (1<<RXEN) | (1<<TXEN);     // Enable Receiver and Transmitter
	UCSRC= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);   // Async-mode

	uartSetBaudRate(9600);
}

void uartSetBaudRate(uint32_t baudRate){
	//TODO:
}
