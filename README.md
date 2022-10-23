# tivaprojects
Contains small projects I made while learning to program TM4C123GH6PM MCU. TM4C123GH6PM MCU is made by Texas Instruments and is based around the ARM Cortex M4F mircroprocessor. I use the TM4C123G evaluation board by Texas Instruments.

The following projects have been made.

1. [RGB LED Flasher Circuit](https://github.com/M-Ahmad45/tivaprojects/tree/main/led%20flasher)  
The RGB LED on the evalutaion board cycles through different combinations of RGB colors.

2. [Basic 7Segment Display](https://github.com/M-Ahmad45/tivaprojects/tree/main/7segment%20basic)  
A seven segment display is controlled using the evaluation board. It counts from 0 to 9 and then restarts.

3. [7 Segment Adder and Register](https://github.com/M-Ahmad45/tivaprojects/tree/main/7segment%20controller%20with%20adder%20register)  
The MCU has been programmed to emulate two registers along with an adder and subtractor. Different operations are performed using control signals. 

4. [7 Segment Counter with Interrupt](https://github.com/M-Ahmad45/tivaprojects/tree/main/7segment%20counter%20with%20interrupt)  
A seven segment display counts from 0 to 9 and back to 0, and repeats this cycle indefinitely. Switch 1 on the evaluation board is used as an interrupt source. When the switch is pressed the ISR cycles through different RGB LED combinations before returning to the counter.

## StartUp file  
The `startup_TM4C123.s` must be added to the project. It is has been placed out of the individual project folders as it is the same across all projects.

## Acknowledgements

I would like to thank [Hamza Akhtar](https://github.com/HamxaCodes) for lending me his Tiva evaluation board.
