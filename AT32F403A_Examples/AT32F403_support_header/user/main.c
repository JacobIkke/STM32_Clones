#include "at32f403a_407_clock.h"
#include "support.h"
#include "stdio.h"


int main(void){

  msTicks = 0;

  SystemInit(); 			// Enable FPU and other crucial stuff
  system_clock_config();	// 240Mhz main clock
  SysTick_init(); 			// For 1 millisecond SysTick and Delay function
  led_init(); 				// PC13 board led
  uart_print_init(115200);	// Printf enabled UART

  // Test Printf
  printf("Hello World\n");

  while(1) {

	  GPIOC->clr = GPIO_PINS_13; // reset = LED on (LED is connected via transistor so is inverted)
	  Delay_ms(1000);

	  GPIOC->scr = GPIO_PINS_13; // set = LED off
	  Delay_ms(1000);

	  printf("SysTick ms : %i \n", msTicks);
  }

}
