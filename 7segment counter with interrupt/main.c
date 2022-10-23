#include "GPIO_registers.h"

#define LED_DELAY   5e5
#define SW1         0x10
#define RGB_LED     0xE

/* taken from led flasher project*/
#define RESET_COLOR ~(0x7<<1)

const char colors[] = {0x0,0x1,0x4,0x2,0x5,0x6,0x3,0x7}; //off red green blue yellow cyan magenta white

void set_color(const int id);
//---------------------------

void delay(unsigned long d);

void EnableInterrupts(void); //implemented in startup file
void DisableInterrupts(void);

int main(){
    volatile unsigned long t;
    RCGCGPIO_R  |=  0x22; //enable clock for port B and port F
    t = RCGCGPIO_R;

    GPIO_DEN_B  |=  0x0F;// enable lower four pins on port B
    GPIO_DIR_B  |=  0x0F;//set pins as outputs

    GPIO_DEN_F  |=  (SW1|RGB_LED); //enable pin corresponding to sw1 on eval board also enable RGB LED pins
    GPIO_DIR_F  &=  (~SW1); //set pin as input
    GPIO_DIR_F  |= RGB_LED; //set RGB LED pins as output
    GPIO_PUR_F  |=  SW1; //enable pull up resistor

    DisableInterrupts();
    //configure NVIC

    NVIC_EN0    |=  0x40000000; //enable interrupt 30 or port F
    NVIC_PRI7   |=  0x00A00000; //set priority level to 5

    GPIO_IM_F   |=  SW1; //interrupt enabled on pin 0 of port F
    GPIO_IS_F   &=  (~SW1); //edge sensitive interrupt. preserve whatever is on other bits and set bit0 to 0
    GPIO_IBE_F  &=  (~SW1); //disable both edge interrupt
    GPIO_IEV_F  &=  (~SW1); //falling edge interrupt is set as the interrupt event
    GPIO_IC_F   =   (SW1); //clear interrupt on pin 0

    EnableInterrupts();

    while(1){
        //count from 0 to 9 then back to 0 and repeat
        for(t=0;t<10;t++){
            GPIO_DATA_B = t;
            delay(LED_DELAY);
        }
        for(t=8;t>0;t--){
            GPIO_DATA_B = t;
            delay(LED_DELAY);
        }
    } 
}

void delay(unsigned long d){
    for(unsigned long x=0; x<d; x++){}
}


void GPIOPortF_Handler(void){
	//cycle throught the array of colors
    for(int i=0;i<8;i++){
			set_color(i);
			delay(LED_DELAY);
			set_color(0);
			delay(LED_DELAY);
		}

    GPIO_IC_F   =   SW1; //clear interrupt on pin 0. clear interrupt on exit
}

void set_color(const int id){
	GPIO_DATA_F &= RESET_COLOR;
	GPIO_DATA_F |= colors[id]<<1;
}
