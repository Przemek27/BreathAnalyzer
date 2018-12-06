/*
 * uart.c
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#include <avr\io.h>

#include "uart.h"

void uartInit(unsigned int baudRate)
{
	uint32_t ubrr;

	UCSRA= 0x00;                 // Clear the UASRT status register

	/*calculate ubrr register value*/
	ubrr = FOSC/16/baudRate-1;

	/*Set baud rate */
	UBRRH = (unsigned char)(ubrr>>8);
	UBRRL = (unsigned char)ubrr;

	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);

	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);   // Async-mode
}

void uartTransmit(unsigned char data)
{
 /* Wait for empty transmit buffer */
 while ( !( UCSRA & (1<<UDRE)) );
 /* Put data into buffer, sends the data */
 UDR = data;
}
