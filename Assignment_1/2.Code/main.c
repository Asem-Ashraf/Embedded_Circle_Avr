#include <util/delay.h>
#include "../../stdTypes.h"

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

int main(void){
  DDRA=0xff;
  PORTA = 0;
  s8 i=0;
  while (1)
  {
    for (i = 0; i < 8; i++)
    {
      PORTA|=(1<<i);
      _delay_ms(500);
    }
    for (i = 0; i<8; i++)
    {
      PORTA&=~(1<<i);
      _delay_ms(500);
    }
  }
}
