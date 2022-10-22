# tivaprojects
Contains small projects I made while learning to program TM4C123GH6PM MCU. TM4C123GH6PM MCU is made by Texas Instruments and is based around the ARM Cortex M4F mircroprocessor. I use the TM4C123G evaluation board by Texas Instruments.

The following projects have been made.

1. [RGB LED Flasher Circuit](https://github.com/M-Ahmad45/tivaprojects/tree/main/led%20flasher)  
The RGB LED on the evalutaion board cycles through different combinations of RGB colors.

2. [Basic 7Segment Display](https://github.com/M-Ahmad45/tivaprojects/tree/main/7segment%20basic)  
A seven segment display is controlled using the evaluation board. It counts from 0 to 9 and then restarts.

3. [7 Segment Adder and Register](https://github.com/M-Ahmad45/tivaprojects/tree/main/7segment%20controller%20with%20adder%20register)  
The MCU has been programmed to emulate two registers along with an adder and subtractor. Different operations are performed using control signals.  

## StartUp file  
The `startup_TM4C123.s` must be added to the project. It is has been placed out of the individual project folders as it is the same across all projects.

## Acknowledgements

I would like to thank [Hamza Akhtar](https://github.com/HamxaCodes) for lending me his Tiva evaluation board.
