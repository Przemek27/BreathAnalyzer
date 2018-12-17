/*
 * utils.h
 *
 *  Created on: 10.12.2018
 *      Author: Przemek
 */

#ifndef INCLUDES_UTILS_H_
#define INCLUDES_UTILS_H_

#include <avr\io.h>

/*
 * Converts 8 bit number to three elements char table
 * */
void convertToChar(uint8_t number, char* tab);

#endif /* INCLUDES_UTILS_H_ */
