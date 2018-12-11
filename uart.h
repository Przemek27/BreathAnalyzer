/*
 * uart.h
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#ifndef UART_H_
#define UART_H_

#define FOSC 1000000 // Clock Speed

/*
 * Note: Uart transmit with baud rate = 9600 bps is not working correct
 * */
void uartInit(unsigned int baudRate);
void uartTransmit(unsigned char data);

#endif /* UART_H_ */
