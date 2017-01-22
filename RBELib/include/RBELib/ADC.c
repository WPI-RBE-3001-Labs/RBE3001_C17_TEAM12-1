/*
 * ADC.c
 *
 *  Created on: Jan 22, 2017
 *      Author: Rayyan Khan, Ben Titus, Ryan Wiesenberg
 */

#include "RBELib/RBELib.h"


void initADC(int channel) {
	ADMUX |= (1 << REFS0);	// selects AVcc as AREF

	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0) ;
}


void clearADC(int channel) {

}


unsigned short getADC(int channel) {
	ADMUX &= ~(0x1F);
	ADMUX |= (channel & 0x001F);	// set channel
	ADCSRA |= (1 << ADSC); // start conversion

	while(ADCSRA & (1 << ADSC)); // poll for cleared start-conversion bit

	return ADCW;
}


void changeADC(int channel) {

}
