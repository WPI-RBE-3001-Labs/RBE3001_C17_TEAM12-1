/**
 * @file timer.h
 *
 * @brief The header file and function prototypes for Timers 0-2.
 *
 * @author Justin Barrett
 * @date August 25, 2011
 *
 * @author Eric Willcox
 * @date August 20, 2013
 */

#ifndef TIMER_H_
#define TIMER_H_
/**
 * @brief Timer normal mode.
 */
#define NORMAL 0
/**
 * @brief Timer Clear Timer on Compare (CTC) mode.
 */
#define CTC	2

#define PRESCALE1		0b001
#define PRESCALE8 		0b010
#define PRESCALE64 		0b011
#define PRESCALE256 	0b100
#define PRESCALE1024	0b101

//#define fclk_IO 18432000;
#define fclk_IO 8000000;

/**
 * @brief Initializes the specified timer in the specified mode. This
 * header file provides constants for NORMAL operation mode and
 * CTC operation mode, however there are many more modes of operation
 * for the Timers that can be experimented with.
 *
 * @param timer The number of the timer to be initialized (0-2).
 * @param mode The mode to initialize the specified timer in.
 * @param comp Only used in CTC mode. The value that the
 * timer counts to before it triggers an interrupt and resets.
 *
 * @todo Create a function that initializes the desired timer in a given mode and set the compare value
 * (as appropriate).
 */
void initTimer(unsigned char timer, int mode, unsigned char comp);

/**
 * @brief Only used when the specified timer is in CTC mode. Changes
 * the value of the comparison register to the new specified value.
 *
 * @param timer The timer comparison value to change (0-2).
 * @param comp The value to set the comparison register to.
 *
 * @todo Create a function that will set a new compare value for the given timer.
 */
void setCompValue(unsigned char timer, unsigned char comp);

#endif /* TIMER_H_ */
