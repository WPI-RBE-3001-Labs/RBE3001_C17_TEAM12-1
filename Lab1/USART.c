/*
 * USART.c
 *
 *  Created on: Jan 26, 2015
 *      Author: joest
 */


#include <RBELib/RBELib.h>
#include <avr/io.h>

void debugUSARTInit(unsigned long baudrate) {
	/*Set baud rate */
	 UBRR0H = (unsigned char)((18432000/(16 * (baudrate))-1)>>8);
	 UBRR0L = (unsigned char)((18432000/(16 * (baudrate))-1));

	 UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	 /* Set frame format: 8data, 2stop bit */
	 UCSR0C = (1<<USBS0)|(3<<UCSZ00);

}

void putCharDebug(char byteToSend){
	/* Wait for empty transmit buffer */
	 while ( !( UCSR0A & (1<<UDRE0)) )
	 ;
	 /* Put data into buffer, sends the data */
	 UDR0 = byteToSend;


}

unsigned char getCharDebug(void) {
	/* Wait for data to be received */
	 while ( !(UCSR0A & (1<<RXC0)) )
	 ;
	 /* Get and return received data from buffer */
	 return UDR0;

}