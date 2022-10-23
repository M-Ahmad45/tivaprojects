
#define GET_REG(ADDRESS) (*((volatile unsigned long*)(ADDRESS)))
#define SYS_CTL_BASE 0x400FE000
#define GPIO_PD_APB_BASE 0x40007000

#define GPIO_DIR_OFFSET 0x400
#define GPIO_DEN_OFFSET 0x51c

#define SYS_CTL_RCGCGPIO_R GET_REG(SYS_CTL_BASE+0x608)

#define GPIO_PD_DIR GET_REG(GPIO_PD_APB_BASE+GPIO_DIR_OFFSET)

#define GPIO_PD_DEN GET_REG(GPIO_PD_APB_BASE+0x51c)

#define GPIO_PD_DATA GET_REG(GPIO_PD_APB_BASE+0x3C)

#define DELAY 5e5

void SystemInit(void){}

void delay(int d);


int main(){
    int x;
    SYS_CTL_RCGCGPIO_R |=0x8; //enable clock for port D
    x = SYS_CTL_RCGCGPIO_R;

    GPIO_PD_DEN |=0xFF;
    GPIO_PD_DIR |=0xFF;

    while(1){
        for(x=0;x<10;x++){
            GPIO_PD_DATA = x;
            delay(DELAY);
            
        }
    }

    return 0;
}

void delay(int d){
    for(int i=0;i<d;i++){}
}
