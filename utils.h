/*
 * utils.h
 *
 *  Created on: 10.12.2018
 *      Author: Przemek
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <avr\io.h>

/*
 * Converts 8 bit number to three elements char table
 * */
void convertToChar(uint8_t nr, char* tab);

#endif /* UTILS_H_ */
