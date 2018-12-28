/*
 * measure.c
 *
 *  Created on: 28.12.2018
 *      Author: Przemek
 */

#include "Includes\measure.h"
#include "Includes\adc.h"

uint32_t performMeasure(void){
	uint32_t result;
	uint32_t i;

	result = 0;

	for(i=0;i<SAMPLES_NR;i++){
		result += adcMeasure();		//acquire samples
	}

	result = result/SAMPLES_NR;		//average out measure

	return result;

}

