/*
 * uart.h
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#include <avr\io.h>

#define FOSC 1000000 // Clock Speed

/*
 * Note: Uart transmit with baud rate = 9600 bps is not working correct
 * */
void uartInit(unsigned int baudRate);
void uartSendChar(unsigned char data);
/*
 * @param str - string to send
 * @param size - size of a string in bytes
 * Note: End of a line should be considered when setting 'size'*/
void uartSendString(char* str, uint32_t size);

#endif /* INCLUDES_UART_H_ */
