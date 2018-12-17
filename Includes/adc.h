/*
 * adc.h
 *
 *  Created on: 26.11.2018
 *      Author: Przemek
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr\io.h>

void adcInit(void);
void adcStart(void);
char adcIsFinished(void);
uint16_t adcMeasure(void);

#endif /* ADC_H_ */
