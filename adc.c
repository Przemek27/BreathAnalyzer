/*
 * adc.c
 *
 *  Created on: 26.11.2018
 *      Author: Przemek
 */

#include <avr\io.h>

#include "adc.h"

void adcInit(void){

	ADMUX = (1<<REFS0);		//set reference voltage to AVcc
	ADMUX |= 1; 			//set port ADC1 as ADC input
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(ADPS1)|(ADPS0); //Enable ADC with Prescalar=Fcpu/128
}

void adcStart(void){
	ADCSRA |= 1 << ADSC;
}
