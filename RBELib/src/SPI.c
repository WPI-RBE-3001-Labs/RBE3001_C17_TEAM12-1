/*
 * SPI.c
 *
 *  Created on: Aug 24, 2016
 *      Author: joest
 */


/*
 * SPI.c
 *
 *  Created on: Jul 14, 2014
 *      Author: ewillcox
 */

#include "RBELib/RBELib.h"

void initSPI(void){
  //Master SS line = output
  SPI_MASTER_SS = OUTPUT;
  //MOSI = output
  SPIDDRbits._MOSI = OUTPUT;
  //SPI clock = output
  SPIDDRbits._SCK = OUTPUT;
  //MISO = input
  SPIDDRbits._MISO = INPUT;

  //Bit 7: Disable interrupts
  //Bit 6: Enable the SPI lines
  //Bit 5: MSB transmitted first
  //Bit 4: Master mode
  //Bit 3: CLK low when idle
  //Bit 2: Sample on leading edge of signal
  //Bits 1 - 0: 128 CLK prescaler
  SPCR = 0x53;

  //DAC SS = output
  DAC_SS_ddr = OUTPUT;

  //Bring the SS line low first (datasheet)
  //Important after soft-resets.  Then deassert.
  DAC_SS = 0;
  DAC_SS = 1;

  // Accelerometer SS line
  SPARE_SS_ddr=OUTPUT;
  PORTCbits._P0=1;

//Encoders SS lines = outputs
  ENCODER_SS_0_ddr = OUTPUT;
  ENCODER_SS_1_ddr = OUTPUT;

  //Deassert
  ENCODER_SS_0 = 1;
  ENCODER_SS_1 = 1;
}

unsigned char spiTransceive(unsigned char cData){
  //Start transmission
  SPDR = cData;
  //Wait for transmission complete
  while(!(SPSR & 0x80));

  //Return the data register
  return SPDR;
}
