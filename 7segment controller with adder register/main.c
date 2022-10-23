#include "./GPIO_registers.h"

void SystemInit(void){}

/* Give clock signal to ports A-D*/

#define CLK_ON 0x0F

/*set enable values and direction values in port A*/
#define EN_PA   0xE0 //pins 7:5 are enabled
#define DIR_PA  0x1F //pins 7:5 are inputs

#define EN_PB   0xFF //pins 7:0 are enabled
#define DIR_PB  0x00 //pins 7:0 are inputs

#define EN_PC   0xF0 //pins 7:4 are enabled
#define DIR_PC  0xF0 //pins 7:4 are outpus

#define EN_PD   0x07 //pins 2:0 are enabled
#define DIR_PD  0x07 //pins 2:0 are outputs

typedef unsigned char byte;

static byte screen_data; //this will be displayed on the screen
static byte screen_buffer[3]={7,8,6}; //this will hold the 3 digit number
static byte screen_select; //select the seven segment to display on
static byte input_op; //op to be performed
static byte last_op; //last op performed

static byte regA, regB; //registers A and B


void display_number(void);
void control(void);
void format_number(unsigned int b, byte buffer[3]); //formats and stores the byte into buffer
byte get_digit(unsigned int x, byte digit);

static inline void delay(unsigned long t);


int main(){
    unsigned long temp;
    RCGCGPIO |= CLK_ON; // give clock
    temp = RCGCGPIO; //waste clock cycles to allow clock signal to propogate to all ports

    /* Enable and set direction of pins for ports A-D*/
    PA_DEN_R |= EN_PA;
    PA_DIR_R |= DIR_PA;

    PB_DEN_R |= EN_PB;
    PB_DIR_R |= DIR_PB;

    PC_DEN_R |= EN_PC;
    PC_DIR_R |= DIR_PC;

    PD_DEN_R |= EN_PD;
    PD_DIR_R |= DIR_PD;

	regA= 3;
	regB=1;
    while (1){
        control();
        display_number();
    }

}

static inline void delay(unsigned long t){
    for(unsigned long i=0;i<t;i++){}
}

void display_number(void){
    int i,j;
    for (j=0;j<50;j++){

        for(i=0;i<3;i++){
            screen_data = screen_buffer[2-i];
			
            screen_select = 1<<i; //select that particular screen by shifting
			
            PC_DATA_R &= 0x0; //reset the data
            PC_DATA_R |= screen_data<<4; //set new data, bit shift by 4 since we are using pins 7:4

            PD_DATA_R &= 0x0; //reset selection
            PD_DATA_R |= screen_select; //

            delay(5000);
        }
    }
}


void control(void){
    input_op = (PA_DATA_R>>5) & 0x7; //shift bits 7:5 to 2:0 and select only those bits

    if(input_op!=last_op){ //avoid repeatedly executing the same operation
        switch (input_op)
        {
        case 0: //display regA
            format_number(regA, screen_buffer);
            break;
        case 1: //display reg B
            format_number(regB, screen_buffer);
            break;
        case 2: //move A to B
            regB = regA;
            break;
        case 3: //bitwise and for A , B
            regA = regA & regB;
            break;
        
        case 4: //store value into regA
            regA = PB_DATA_R;
            break;
        
        case 5: //store value into regB
            regB = PB_DATA_R;
            break;
        
        case 6: //store A+b into regA
            regA = regA+regB; 
            break;
        case 7: //store A-B into regA
            regA = regA-regB;
            break;
        }

        last_op = input_op;
    }
}

void format_number(unsigned int b, byte buffer[3]){
    buffer[0] = get_digit(b,2);
    buffer[1] = get_digit(b,1);
    buffer[2] = get_digit(b,0);
}

byte get_digit(unsigned int x, byte digit){
    byte q=0;
    while (x>=10){
        x-=10;
        q++;
    }
    if (digit==0){
        return x;
    }else if (digit==1){
        return get_digit(q,0);
    }else{
        return get_digit(q,1);
    }
}
