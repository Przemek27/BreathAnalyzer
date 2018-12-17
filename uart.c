/*
 * uart.c
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#include "Includes/uart.h"

#include <avr\io.h>


//TODO: made UART interrupt driven

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

void uartSendChar(unsigned char data)
{
 /* Wait for empty transmit buffer */
 while ( !( UCSRA & (1<<UDRE)) );
 /* Put data into buffer, sends the data */
 UDR = data;
}

void uartSendString(char* str, uint32_t size){
	uint32_t i;

	for(i=0;i<size;i++){
		uartSendChar(str[i]);
	}
}
