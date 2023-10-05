/*
 *  support.c
 *
 *  Created on: 2023 Oct 5
 *      Author: PeetHobby
 */
#include "at32f403a_407_clock.h"
#include "stdio.h"

volatile uint32_t msTicks;

void SysTick_init(void){
	systick_clock_source_config(SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV);
	SysTick_Config((system_core_clock / 1000U));
}

// I disabled the SysTick_Handler in at32f403a_407_int.c so everything is together in this file.
void SysTick_Handler(void){
	msTicks ++;
}

void Delay_ms(uint32_t milliseconds) {
    uint32_t startTicks = msTicks; // Record the current value of msTicks
    while ((msTicks - startTicks) < milliseconds) {
    	__ASM("NOP");
    }
}

void led_init(){

  gpio_init_type gpio_init_struct;

  crm_periph_clock_enable(CRM_GPIOC_PERIPH_CLOCK, TRUE); // enable the led clock

  gpio_default_para_init(&gpio_init_struct); // Reset default parameter

  // configure the led gpio
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_OUTPUT;
  gpio_init_struct.gpio_pins = GPIO_PINS_13;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOC, &gpio_init_struct);
}


void uart_print_init(uint32_t baudrate){

  gpio_init_type gpio_init_struct;

#if defined (__GNUC__) && !defined (__clang__)
  setvbuf(stdout, NULL, _IONBF, 0);
#endif

  //enable the uart and gpio clock
  crm_periph_clock_enable(CRM_USART1_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

  gpio_default_para_init(&gpio_init_struct);

  // configure the uart tx pin
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type  = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pins = GPIO_PINS_9;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init(GPIOA, &gpio_init_struct);

  // configure uart param
  usart_init(USART1, baudrate, USART_DATA_8BITS, USART_STOP_1_BIT);
  usart_transmitter_enable(USART1, TRUE);
  usart_enable(USART1, TRUE);
}

int __write(int fd, char *pbuffer, int size){

  for(int i = 0; i < size; i ++)
  {
    while(usart_flag_get(USART1, USART_TDBE_FLAG) == RESET);
    usart_data_transmit(USART1, (uint16_t)(*pbuffer++));
    while(usart_flag_get(USART1, USART_TDC_FLAG) == RESET);
  }

  return size;
}
