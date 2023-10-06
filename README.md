(Work in progress!)
# STM32 clones
Collection of datasheets, SDK, example code and other info about STM32 clones.


## Some benchmarks of clones and other MCU's

### Find the first 10000 prime numbers benchmark:
- Pico Python 125Mhz = 36s (Thonny)
- Pico Python 256Mhz = 18s (Thonny)
- Pico C sdk 125Mhz  = 996 ms (vscode)
- Pico C sdk 256Mhz  = 486 ms (vscode)
<br/>

- Arduino 16Mhz = 120s (Arduino software)
- LGT8F328p 32Mhz 59s (Arduino software)
<br/>

- CH582F RISCV 60MHz code in flash = 15724ms (Mounriver IDE, RISCV GCC)
- CH582f RISCV 60MHz code in RAM = 3433ms (Mounriver IDE, RISCV GCC)
<br/>

- STM32F103 72Mhz code in flash = 3s (Arduino software, I didn't run this myself!)
- STM32H750 480Mhz code in flash = 186 ms (stm32cube GCC, both L1 caches enabled)
- AIR32F103CBT6 72MHz Code in flash = 2455ms (VScode GCC) 
- AIR32F103CBT6 216MHz Code in flash = 818ms (VScode GCC) Default clock
- AIR32F103CBT6 256MHz Code in flash = 690ms (VScode GCC) Max Clock
- AT32F403ACGU7 240Mhz Code in flash = 944ms (AT32 IDE GCC)
<br/>

### Floating point benchmark
- AT32F403ACGU7 240Mhz   no FPU   = 742ms
- AT32F403ACGU7 240Mhz   Hard FPU = 112ms
- AIR32F103CBT6 240Mhz   no FPU   = 690ms
