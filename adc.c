/*
 * adc.c
 *
 *  Created on: 26.11.2018
 *      Author: Przemek
 */

#include <avr\io.h>

void adcInit(void){

	ADMUX=(1<<REFS0);		//set reference voltage to AVcc
	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(ADPS1)|(ADPS0); //Enable ADC with Prescalar=Fcpu/128
}

