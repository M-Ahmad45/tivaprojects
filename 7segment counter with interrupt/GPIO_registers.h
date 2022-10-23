#ifndef GPIO_REGISTERS
#define GPIO_REGISTERS 1

#define GET_REG(address) *((volatile unsigned long*)(address))

#define SYS_CTL_BASE    0x400FE000
#define CLOCK_OFFSET    0x608

#define RCGCGPIO_R  GET_REG(SYS_CTL_BASE+CLOCK_OFFSET)

//NVIC

#define NVIC_BASE       0xE000E000
#define EN0_OFFSET      0x100 //to enable the 30th IRQ
#define PRI7_OFFSET     0x41C //to set priority for the 30th IRQ

#define NVIC_EN0    GET_REG(NVIC_BASE+EN0_OFFSET)
#define NVIC_PRI7   GET_REG(NVIC_BASE+PRI7_OFFSET)


//base address for portF and portB
#define PORTB_APB_BASE  0x40005000
#define PORTF_APB_BASE  0x40025000


//offsets for various registers corresponding to gpio ports

#define DATA_OFFSET     0x3FC //data
#define DIR_OFFSET      0x400 //direction
#define DEN_OFFSET      0x51c //enable
#define PUR_OFFSET      0x510 //weak pull up resistor

// Interrupt specific registers
#define IM_OFFSET       0x410 //interrup mask. determines interrupt is enabled on what pin
#define IS_OFFSET       0x404 //interrupt sense. determines how the interrupt is sensed, i.e. on edge or on level
#define IEV_OFFSET      0x40C //interrupt event. falling edge/low level or rising edge/high level
#define IBE_OFFSET      0x408 //interrupt both edges. cause interrupt on both rising and falling edges
#define IC_OFFSET       0x41C //interrupt clear. clear the interrupt for the resepective pin by writing 1 to that bit


//registers to be used
#define GPIO_DIR_B  GET_REG(PORTB_APB_BASE+DIR_OFFSET)
#define GPIO_DEN_B  GET_REG(PORTB_APB_BASE+DEN_OFFSET)
#define GPIO_DATA_B GET_REG(PORTB_APB_BASE+DATA_OFFSET)

#define GPIO_DIR_F  GET_REG(PORTF_APB_BASE+DIR_OFFSET)
#define GPIO_DEN_F  GET_REG(PORTF_APB_BASE+DEN_OFFSET)
#define GPIO_DATA_F GET_REG(PORTF_APB_BASE+DATA_OFFSET)
#define GPIO_PUR_F  GET_REG(PORTF_APB_BASE+PUR_OFFSET)

#define GPIO_IM_F   GET_REG(PORTF_APB_BASE+IM_OFFSET)
#define GPIO_IS_F   GET_REG(PORTF_APB_BASE+IS_OFFSET)
#define GPIO_IEV_F  GET_REG(PORTF_APB_BASE+IEV_OFFSET)
#define GPIO_IBE_F  GET_REG(PORTF_APB_BASE+IBE_OFFSET)
#define GPIO_IC_F   GET_REG(PORTF_APB_BASE+IC_OFFSET)

#endif
