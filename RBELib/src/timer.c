/*
 * timer.c
 *
 *  Created on: Jan 23, 2017
 *      Author: Ryan
 */

#include <RBELib/RBELib.h>

static const int prescale = PRESCALE1024;

void initTimer(unsigned char timer, int mode, unsigned char comp){
	cli(); // disable interrupts until setup is finished
	switch(timer){
	case 0:
		TCCR0A = mode << COM0A0 | mode << WGM00;
		TCCR0B = prescale << CS00;
		OCR0A = comp;
		TIMSK0 |= 1 << OCIE0A;
		break;
	case 1:
		TCCR1A = mode << COM1A0;
		TCCR1B = prescale << CS10 | 1 << WGM12;
		OCR1A = comp;
		TIMSK1 |= 1 << OCIE0A;
		break;
	case 2:
		TCCR2A = mode << COM2A0 | mode << WGM20;
		TCCR2B = prescale << CS20;
		OCR2A = comp;
		TIMSK2 |= 1 OCIE2A;
		break;
	}
	sei();
}

void setCompValue(unsigned char timer, unsigned char comp){
	switch(timer){
	case 0:
		OCR0A = comp;
		break;
	case 1:
		OCR1A = comp;
		break;
	case 2:
		OCR1B = comp;
		break;
	}
}


