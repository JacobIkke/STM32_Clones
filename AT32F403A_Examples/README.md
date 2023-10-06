## AT32F403A Code Examples
Collection of code examples for the AT32F403A.

### AT32F403_support_header
This is a template example for the Weact dev board with AT32F403ACGU7, intended for future projects. The AT32 IDE typically initiates all projects with example code for their own  development boards, utilizing the at32f403a_407_board.c and at32f403a_407_board.h files for board initialization. However, the LED pins differ in this case. Therefore, I've made a comparable file that initializes UART with printf support, configures SysTick for 1ms, and includes a Delay_ms function, and all the system initialisations. 
File names: support.c and support.h
