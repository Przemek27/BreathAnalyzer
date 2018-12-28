/*
 * port.c
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#include "Includes/port.h"

#include <avr\io.h>


void portInit(void){
	/*Configure PORTA Pin 0 - Power On LED*/
	DDRA |= OUT << PIN0;	//set pin direction as output
	PORTA |= ON << PIN0;		//set pin value to high

	//configure output pin for LEDs - indicate amount of alcohol in breath*/
	DDRB |= OUT << PIN0 | OUT << PIN1 | OUT | PIN2;
	PORTB &= ~(ON << PIN0 | ON << PIN1 | ON << PIN2);
}
