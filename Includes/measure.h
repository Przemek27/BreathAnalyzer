/*
 * measure.h
 *
 *  Created on: 28.12.2018
 *      Author: Przemek
 */

#ifndef INCLUDES_MEASURE_H_
#define INCLUDES_MEASURE_H_

#include <avr\io.h>

#define SAMPLES_NR 100 //number of samples used to average out measure

uint32_t performMeasure(void);

#endif /* INCLUDES_MEASURE_H_ */
