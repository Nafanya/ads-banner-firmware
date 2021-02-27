#include <avr/io.h>

#define pb7 (1<<PB7)
#define pb6 (1<<PB6)
#define pb5 (1<<PB5)
#define pb4 (1<<PB4)
#define pb3 (1<<PB3)
#define pb2 (1<<PB2)
#define pb1 (1<<PB1)
#define pb0 (1<<PB0)

#define pd6 (1<<PD6)
#define pd5 (1<<PD5)
#define pd4 (1<<PD4)

#define dot1 pb1
#define dot2 pb0
#define dot3 pd6
#define dot4 pb5
#define dot5 pd4

#define windows  pb7
#define curtains pb6
#define jalousie pb5
#define gates    pb4
#define kitchens pb3
#define ceilings pb2

void wait(void);
void clear(void);

int main(void) {
  // There are 11 LEDs in total, so use all 8 PB pins
  // plus 3 PD pins (6, 5 and 4).
  DDRB |= pb7 | pb6 | pb5 | pb4 | pb3 | pb2 | pb1 | pb0;
  DDRD |= pd6 | pd5 | pd4;

  while (1) {
    // steps 1-6. Light each dot one after another.
    // step 1.
    clear();
    PORTB |= dot1;
    wait(2);

    // step 2.
    clear();
    PORTB |= dot2;
    wait(2);

    // step 3.
    clear();
    PORTD |= dot3;
    wait(2);

    // step 4.
    clear();
    PORTD |= dot4;
    wait(2);

    // step 5.
    clear();
    PORTD |= dot5;
    wait(2);

    // step 6. Light all dots.
    clear();
    PORTB |= dot1 | dot2;
    PORTD |= dot3 | dot4 | dot5;
    wait(2);

    // step 7.
    clear();
    PORTB |= dot1 | dot2 | windows;
    PORTD |= dot3 | dot4 | dot5;
    wait(3);

    // step 8.
    clear();
    PORTB |= dot1 | dot2 | curtains;
    PORTD |= dot3 | dot4 | dot5;
    wait(3);

    // step 9.
    clear();
    PORTB |= dot1 | dot2 | jalousie;
    PORTD |= dot3 | dot4 | dot5;
    wait(3);

    // step 10.
    clear();
    PORTB |= dot1 | dot2 | gates;
    PORTD |= dot3 | dot4 | dot5;
    wait(3);

    // step 11.
    clear();
    PORTB |= dot1 | dot2 | kitchens;
    PORTD |= dot3 | dot4 | dot5;
    wait(3);

    // step 12.
    clear();
    PORTB |= dot1 | dot2 | ceilings;
    PORTD |= dot3 | dot4 | dot5;
    wait(3);

    // step 13. Light everything.
    clear();
    PORTB |= dot1 | dot2 | windows | curtains | jalousie | gates | kitchens | ceilings;
    PORTD |= dot3 | dot4 | dot5;
    wait(5);

    // step 14. Turn off everything
    clear();
    wait(1);

    // step 15.
    clear();
    PORTB |= dot1 | dot2 | windows | curtains | jalousie | gates | kitchens | ceilings;
    PORTD |= dot3 | dot4 | dot5;
    wait(5);

    // step 16. Turn off everything
    clear();
    wait(1);

    // step 17.
    clear();
    PORTB |= dot1 | dot2 | windows | curtains | jalousie | gates | kitchens | ceilings;
    PORTD |= dot3 | dot4 | dot5;
    wait(5);
  }      
}

void wait(unsigned int seconds) {
  // TODO: tweak
  volatile unsigned int del = 20000 * seconds;
  while(del--);
}

void clear(void) {
  PORTD = 0;
  PORTB = 0;
}