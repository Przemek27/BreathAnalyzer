/*
 * adc.c
 *
 *  Created on: 26.11.2018
 *      Author: Przemek
 */

#include "Includes/adc.h"

#include <avr\io.h>


//TODO: make adc interrupt driven

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

uint32_t adcMeasure(void){
	uint32_t result;

	adcStart();

	while(!adcIsFinished());

	result = ADCL;
	result |= ADCH << 8;

	return result;
}
