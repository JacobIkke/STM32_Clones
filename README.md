(Work in progress!)
# STM32 Clones
Collection of datasheets, example codes, overclocking, benchmark scores and other info about STM32 clones.


## Some benchmarks of clones and other MCU's

### Find the first 10000 Prime Numbers Benchmark:
- CKS32F103C8T6 72MHz Code in flash = 3834ms (STM32Cube IDE, GCC)
- AIR32F103CBT6 72MHz Code in flash = 2455ms (VScode GCC) 
- AIR32F103CBT6 216MHz Code in flash = 818ms (VScode GCC) Default clock
- AIR32F103CBT6 256MHz Code in flash = 690ms (VScode GCC) Max Clock
- AT32F403ACGU7 240Mhz Code in flash = 687ms (AT32 IDE GCC) Default clock
- AT32F403ACGU7 288Mhz Code in flash = 572ms (AT32 IDE GCC) Overclocked

<br/>

- STM32F103C8T6 72MHz code in flash = 3s (Arduino software, I didn't run this myself!)
- STM32G431 170MHz code in flash = 1370 ms (stm32cube GCC, Both caches enabled, Prefecth Enabled)
- STM32H503 250MHz code in flash = 798 ms (stm32cube GCC, icache enabled)
- STM32H750 480MHz code in flash = 186 ms (stm32cube GCC, both L1 caches enabled)
- STM32H723 550MHz code in flash = 102 ms (stm32cube GCC, both L1 caches enabled, MPU enabled, clocks optimized, etc)
<br/>

- Pico Python 125Mhz = 36s (Thonny)
- Pico Python 256Mhz = 18s (Thonny)
- Pico C sdk 125Mhz  = 996 ms (vscode, code fit in the 16KB cache) 
- Pico C sdk 256Mhz  = 486 ms (vscode, code fit in the 16KB cache)
- Pico2 C SDK 150Mhz = 341 ms (vscode, sdk2.1.1, small code size)
- Pico2 C SDK 256Mhz = 200 ms (vscode, sdk2.1.1, small code size)
<br/>

- Arduino Nano Atmega328p 16Mhz = 120s (Arduino software)
- Nano clone LGT8F328p 32Mhz = 59s (Arduino software)
<br/>

- CH582F RISCV  60MHz code in flash = 15724ms (Mounriver IDE, RISC-V GCC)
- CH582F RISCV  60MHz code in RAM   =  3433ms (Mounriver IDE, RISC-V GCC)
- CH32V003F4P6  24MHz Code in Flash = 29448ms (Core V4A, Mounriver IDE, RISC-V GCC, flash 0 wait-stage)
- CH32V003F4P6  48MHz Code in Flash = 19560ms (Core V4A, Mounriver IDE, RISC-V GCC, flash 1 wait-stage)
- CH32V203F6P6  48MHz Code in Flash =  3921ms (Core V4B, Mounriver IDE, RISC-V GCC, flash 0 wait-stage)
- CH32V203F6P6 144MHz Code in Flash =  1307ms (Core V4B, Mounriver IDE, RISC-V GCC, flash 0 wait-stage)

<br/>

- ESP32-S3 WROOM 1 240MHz flash   = 1291 ms (Arduino IDE, Arduino Framework)
- ESP32-S2 240MHz code in flash   = 1047 ms (PlatformIO, Arduino Framework)
- ESP32-DOWD 240MHz code in flash = 1486 ms (PlatformIO, Arduino Framework)
- ESP32-C3 160MHz code in flash   = 1820 ms (RISC-V, PlatformIO, Arduino Framework)
- ESP8266EX 160MHz code in flash  = 3409 ms (Arduino IDE, Arduino Framework)
<br/>


### Floating point benchmark Leibniz formula 500000 iterations
- AT32F403ACGU7 240Mhz   no FPU   = 742ms
- AT32F403ACGU7 288Mhz   no FPU   = 619ms Overclocked
- AT32F403ACGU7 240Mhz   Hard FPU = 112ms
- AIR32F103CBT6 240Mhz   no FPU   = 690ms
<br/>

### AT32F403A DSP FPU sqrt benchmark - Calculate sqrt 100000 times
arm_sqrt_f32() and arm_sqrt_q15 are functions from the DSP library that utilize the hardware FPU, and they can be found in arm_math.h. <br/>
sqrt() is a software function that operates on a double integer, avoiding the use of the FPU. You can locate it in the math.h library.<br/>
![sqrt_bench](https://github.com/JacobIkke/STM32_Clones/blob/main/AT32F403A_Examples/images/AT32F403A_sqrt_dsp_fpu_bench_240M.png)

## Overclocking
Most clones run a bit faster than the STM32 version. They're made with more modern production processes. 
For instance, the STM32F103 series was designed back in 2007 and is made on a 90nm(?) process, while clones like the AIR32 are produced on a 40nm process by TSMC, giving it more potential for higher clock speeds.

* AIR32F103CBT6 M3 max overclock is 256MHz - limitation: PLL multiplier cannot go higher *1
* AT32F403ACGU7 M4 max overclock is 312MHz - Can maybe clocked higher, but need more testing. 

*1 The board use an 8MHz crystal, but you can potentially get a higher clock with a different value crystal.

## Programming
The AIR32F103 comes with DAP-link firmware pre-installed. If you order two or more of them, you can use one as a programmer if you don't already have a DAP-link.

The AT32F403ACGU7 black pill dev board comes with DFU bootloader, and supports DAP-link, AT-link and J-link. 
