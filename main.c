#include <msp430.h>
#define RED_LED BIT0 //P1.0
#define BUTTON1 BIT1 //push button P4.1
#define GREEN_LED BIT6 //P6.6
#define BUTTON2 BIT3 //push button P2.3

/*
 #include <msp430.h>
#define RED_LED BIT0 //P1.0
#define BUTTON1 BIT1 //push button P4.1

void main(void)
{*/

void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    P1OUT &= ~BIT0;
    P1DIR |= BIT0;

    P6DIR |= BIT6;
    P6OUT &= ~BIT6; //p6.6 greenled


    P4DIR &= ~BIT1;
    P4REN |= BIT1;
    P4OUT |= BIT1;

  P2DIR &= ~BIT3;//clear P2.3(s2)
    P2REN |= BIT3;//Enable pull up/down resistor
    P2OUT |= BIT3;//Make resistor a pull up

    PM5CTL0 &= ~LOCKLPM5;

    int count = 0;
    while (1) {
        if((P4IN & BUTTON1)== 0x00){
         _delay_cycles(5000);
        if ((P1IN & BUTTON1)== 0x00) {
            P1OUT ^= RED_LED;
        } while((P4IN & BUTTON1)==0x00);
        }
        else if((P2IN & BUTTON2)== 0x00){
                _delay_cycles(5000);
               if ((P2IN & BUTTON2)== 0x00) {
                   P6OUT^= GREEN_LED;
               } while((P2IN & BUTTON2)==0x00);
          }
    }
}
