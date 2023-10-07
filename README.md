(Work in progress!)
# STM32 Clones
Collection of datasheets, example codes, overclocking, benchmark scores and other info about STM32 clones.


## Some benchmarks of clones and other MCU's

### Find the first 10000 Prime Numbers Benchmark:
- AIR32F103CBT6 72MHz Code in flash = 2455ms (VScode GCC) 
- AIR32F103CBT6 216MHz Code in flash = 818ms (VScode GCC) Default clock
- AIR32F103CBT6 256MHz Code in flash = 690ms (VScode GCC) Max Clock
- AT32F403ACGU7 240Mhz Code in flash = 944ms (AT32 IDE GCC)
- STM32F103C6T6 72Mhz code in flash = 3s (Arduino software, I didn't run this myself!)
- STM32H750 480Mhz code in flash = 186 ms (stm32cube GCC, both L1 caches enabled)
<br/>

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


### Floating point benchmark Leibniz formula 500000 iterations
- AT32F403ACGU7 240Mhz   no FPU   = 742ms
- AT32F403ACGU7 240Mhz   Hard FPU = 112ms
- AIR32F103CBT6 240Mhz   no FPU   = 690ms
<br/>

## Overclocking
Most clones run a bit faster than the STM32 version. They're made with more modern production processes. 
For instance, the STM32F103 series was designed back in 2007 and is made on a 90nm process, while clones like the AIR32 are produced on a 40nm process by TSMC, giving it more potential for higher clock speeds.

* AIR32F103CBT6 M3 max overclock is 256MHz - limitation: PLL multiplier cannot go higher *1
* AT32F403ACGU7 M4 max overclock is 256MHz - limitation: PLL multiplier cannot go higher *1

*1 My board uses an 8MHz crystal, but you can potentially achieve higher speeds with different value crystals.

