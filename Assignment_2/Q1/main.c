#include <util/delay.h>
#include "../../stdTypes.h"

#define PORTA *((u8*)         0x3B)
#define DDRA  *((u8*)         0x3A)
#define PINA  *((volatile u8*)0x39)

#define PRESSED 0
#define NOT_PRESSED 1

#define PORTB *((u8*)         0x38)
#define DDRB  *((u8*)         0x37)
#define PINB  *((volatile u8*)0x36)

int main(void){
    //the button has to be in a pull up resistor configuration.
    DDRA = 0;
    DDRB = 0;

    // set the two pins to output  led 1 & 2
    DDRA|=(1<<0);
    DDRA|=(1<<1);

    // set the two pins to input  switches 1 & 2 & 3
    DDRB&=~(1<<0);
    DDRB&=~(1<<1);
    DDRB&=~(1<<2);

    // intialize port a to 0
    PORTA=0;

    // intialize port b to 255 to use the pull-up resistor
    PORTB=255;

    while (1)
    {
        if (((PINB&(1<<0))>>0)==PRESSED) { // if button 1 is pressed 
           // turn on led 1 
            PORTA|=(1<<0);
        }else if (((PINB&(1<<2))>>2)==NOT_PRESSED) { // if button 3 is not pressed
            // turn off led 1
            PORTA&=~(1<<0);
        }
        if (((PINB&(1<<1))>>1)==PRESSED) { // if button 2 is pressed
            // turn on led 2
            PORTA|=(1<<1);
        }else if (((PINB&(1<<2))>>2)==NOT_PRESSED) { // if button 3 is not pressed
            // turn off led 2
            PORTA&=~(1<<1);
        }
        if (((PINB&(1<<2))>>2)==PRESSED) { // if button 3 is pressed
            // turn on led 1
            PORTA|=(1<<0);
            // turn on led 2
            PORTA|=(1<<1);
        }
    }
}

