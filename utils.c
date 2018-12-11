/*
 * utils.c
 *
 *  Created on: 10.12.2018
 *      Author: Przemek
 */

#include "utils.h"


//FIXME:
void convertToChar(uint8_t number, char* tab){

	tab[0] = number%10 + '0';		//tab[0] - LSB
	tab[1] = number%100/10 + '0';
	tab[2] = number/100 + '0';
}
