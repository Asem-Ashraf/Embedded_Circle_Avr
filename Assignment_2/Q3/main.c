#include <util/delay.h>
#include "../../stdTypes.h"

#define PORTA *((u8*)         0x3B)
#define DDRA  *((u8*)         0x3A)
#define PINA  *((volatile u8*)0x39)

#define PRESSED 0
#define NOT_PRESSED 1

#define DELAY 50

#define PORTB *((u8*)         0x38)
#define DDRB  *((u8*)         0x37)
#define PINB  *((volatile u8*)0x36)

int main(void){
    //the button has to be in a pull up resistor configuration.
    DDRA = 0;
    DDRB = 0;

    // set the two pins to input switch 1 & 2
    DDRA&=~(1<<0);
    DDRA&=~(1<<1);

    // set the two pins for output screen selection
    DDRA|=(1<<2);
    DDRA|=(1<<3);

    // set the 7 pins to output for 7-segment
    DDRB|=(1<<0);
    DDRB|=(1<<1);
    DDRB|=(1<<2);
    DDRB|=(1<<3);
    DDRB|=(1<<4);
    DDRB|=(1<<5);
    DDRB|=(1<<6);

    // intialize port A to 0x03
    PORTA|=(1<<0);
    PORTA|=(1<<1);
    PORTA|=(1<<2);
    PORTA|=(1<<3);

    u8 i= 50;
    // 7-segment array
    u8 _7SegNo[10] = { 0x3F,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6F};

    while (1)
    {
        if (((PINA&(1<<0))>>0)==PRESSED) { // if button 1 is pressed 
            // increase the number by one
            i++;
            if (i==100) { i=0; }
            while (((PINA&(1<<0))>>0)==PRESSED) {// while the button is presesd keep updating display
                PORTB = _7SegNo[(u8)i/10];
                PORTA&=~(1<<2);
                _delay_ms(DELAY);
                PORTA|=(1<<2);
                PORTB = _7SegNo[i%10];
                PORTA&=~(1<<3);
                _delay_ms(DELAY);
                PORTA|=(1<<3);
            }
        }
        if (((PINA&(1<<1))>>1)==PRESSED) { // if button 2 is pressed
            // decrease the number by one
            i--;
            if (i==255) { i=99; }
            while (((PINA&(1<<1))>>1)==PRESSED) {
                PORTB = _7SegNo[(u8)i/10];
                PORTA&=~(1<<2);
                _delay_ms(DELAY);
                PORTA|=(1<<2);
                PORTB = _7SegNo[i%10];
                PORTA&=~(1<<3);
                _delay_ms(DELAY);
                PORTA|=(1<<3);
            }
        }
        PORTB = _7SegNo[(u8)i/10];
        PORTA&=~(1<<2);
        _delay_ms(DELAY);
        PORTA|=(1<<2);
        PORTB = _7SegNo[i%10];
        PORTA&=~(1<<3);
        _delay_ms(DELAY);
        PORTA|=(1<<3);
    }
}

