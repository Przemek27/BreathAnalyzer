/*
 * port.c
 *
 *  Created on: 03.12.2018
 *      Author: Przemek
 */

#include <avr\io.h>

#include "port.h"

void portInit(void){
	/*Configure PORTA Pin 0 - Power On LED*/
	DDRA |= OUT << PIN0;	//set pin direction as output
	PORTA |= 1 << PIN0;		//set pin value to high

	/*TODO: configure input pin for button - start adc measure*/

}
