/*
 *  support.h
 *
 *  Created on: 2023 Oct 5
 *      Author: PeetHobby
 */

#ifndef INCLUDE_SUPPORT_H_
#define INCLUDE_SUPPORT_H_

volatile extern uint32_t msTicks;

void SysTick_init(void);
void Delay_ms(uint32_t milliseconds);
void led_init();
void uart_print_init(uint32_t baudrate);

#endif /* INCLUDE_SUPPORT_H_ */
