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

char adcIsFinished(void){
	if(ADCSRA & (1 << ADIF))
		return 1;
	else
		return 0;
}

uint16_t adcMeasure(void){
	uint16_t result;

	adcStart();

	while(!adcIsFinished());

	result = ADCL;
	result |= ADCH << 8;

	return result;
}
