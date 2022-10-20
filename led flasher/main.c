
#define GET_PTR(ADDRESS) (*((volatile unsigned long*)(ADDRESS)))
#define SYS_CTL_BASE 0x400FE000
#define GPIO_PF_APB_BASE 0x40025000

//0x400FE000 is the base address for sys control and 0x608 is the offset value for RCGCGPIO 
//This register allows clock signal to be provided to different ports.
#define SYS_CTL_RCGCGPIO GET_PTR(SYS_CTL_BASE+0x608)

//this register is used to set the port pin as input or output
#define GPIO_DIR_F GET_PTR(GPIO_PF_APB_BASE+0x400)

//this register is used to enable the pins for digital ops
#define GPIO_DEN_F GET_PTR(GPIO_PF_APB_BASE+0x51c)

//this register is used to read/write data from and to the pins. The address offset determines which pins are read/writable
//see datasheet for more info
#define GPIO_DATA_F GET_PTR(GPIO_PF_APB_BASE+0x3FC)


#define DELAY 1e6
#define RESET_COLOR ~(0x7<<1)

const char colors[] = {0x0,0x1,0x4,0x2,0x5,0x6,0x3,0x7}; //off red green blue yellow cyan magenta white

void set_color(const int id);
void delay(int d);
void SystemInit(void){}

int main(){
	volatile unsigned long i;
	SYS_CTL_RCGCGPIO |= 0x20; //enable clock for port F
	
	i = SYS_CTL_RCGCGPIO; //used to waste clock cycles so that every module starts to get clock signal
	
	GPIO_DEN_F |= 0xFF; //enable all pins for digital i/o op
	GPIO_DIR_F |= 0xFF; // configure all pins as output
	
	while(1){
		for(i=0;i<8;i++){
			set_color(i);
			delay(DELAY);
			set_color(0);
			delay(DELAY);
		}
	}
	
}


void set_color(const int id){
	GPIO_DATA_F &= RESET_COLOR;
	GPIO_DATA_F |= colors[id]<<1;
}

void delay(int d){
	for(int i =0;i<d;i++){}
}










