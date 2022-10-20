/*function macro to easily get register reference*/
#define GET_REG(ADDRESS) (*((volatile unsigned long*)(ADDRESS)))

/*sys module and sys clock offset values*/
#define SYS_BASE            0x400FE000
#define CLK_OFFSET          0x608

/*use previous macro to get register for sys clock*/
#define RCGCGPIO GET_REG(SYS_BASE+CLK_OFFSET)

/*offset values for gpio ports*/
#define GPIO_DIR_OFFSET     0x400
#define GPIO_DEN_OFFSET     0x51C
#define GPIO_DATA_OFFSET    0x3FC

/*gpio port base addresses for apb*/
#define PORTA_APB_BASE      0x40004000
#define PORTB_APB_BASE      0x40005000
#define PORTC_APB_BASE      0x40006000
#define PORTD_APB_BASE      0x40007000

/*DATA Direction and Digital enable registers  for port A*/
#define PA_DATA_R GET_REG(PORTA_APB_BASE+GPIO_DATA_OFFSET)
#define PA_DIR_R  GET_REG(PORTA_APB_BASE+GPIO_DIR_OFFSET)
#define PA_DEN_R  GET_REG(PORTA_APB_BASE+GPIO_DEN_OFFSET)

/*DATA Direction and Digital enable registers  for port B*/
#define PB_DATA_R GET_REG(PORTB_APB_BASE+GPIO_DATA_OFFSET)
#define PB_DIR_R  GET_REG(PORTB_APB_BASE+GPIO_DIR_OFFSET)
#define PB_DEN_R  GET_REG(PORTB_APB_BASE+GPIO_DEN_OFFSET)

/*DATA Direction and Digital enable registers  for port C*/
#define PC_DATA_R GET_REG(PORTC_APB_BASE+GPIO_DATA_OFFSET)
#define PC_DIR_R  GET_REG(PORTC_APB_BASE+GPIO_DIR_OFFSET)
#define PC_DEN_R  GET_REG(PORTC_APB_BASE+GPIO_DEN_OFFSET)

/*DATA Direction and Digital enable registers  for port D*/
#define PD_DATA_R GET_REG(PORTD_APB_BASE+GPIO_DATA_OFFSET)
#define PD_DIR_R  GET_REG(PORTD_APB_BASE+GPIO_DIR_OFFSET)
#define PD_DEN_R  GET_REG(PORTD_APB_BASE+GPIO_DEN_OFFSET)