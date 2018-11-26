/*
 * main.c
 *
 *  Created on: 18.11.2018
 *      Author: Przemek
 */
#include <avr\io.h>
#include "adc.h"

#define IN 0
#define OUT 1

int main(void){

	/*Configure PORTA Pin 0*/
	DDRA |= OUT << PIN0;	//set pin direction as output
	PORTA |= 1 << PIN0;		//set pin value to high

	adcInit();

	//

	while(1);

	return 0;
}
