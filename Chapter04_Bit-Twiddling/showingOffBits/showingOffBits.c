            /* Showing off some patterns to practice our bit-twiddling */

// ------- Preamble -------- //
#include <avr/io.h>
#include <avr/power.h>
#include <util/delay.h>                     /* Functions to waste time */

#define DELAYTIME 85                                   /* milliseconds */
#define LED_PORT                PORTB
#define LED_DDR                 DDRB

int main(void) {

  uint8_t i;
  uint8_t repetitions;
  uint8_t whichLED;
  uint16_t randomNumber = 0x1234;

  // -------- Inits --------- //
  LED_DDR = 0xff;                    /* all LEDs configured for output */
  // ------ Event loop ------ //
  while (1) {
                                                            /* Go Left */
    for (i = 0; i < 8; i++) {
      LED_PORT |= (1 << i);                    /* turn on the i'th pin */
      _delay_ms(DELAYTIME);                                    /* wait */
    }
    for (i = 0; i < 8; i++) {
      LED_PORT &= ~(1 << i);                  /* turn off the i'th pin */
      _delay_ms(DELAYTIME);                                    /* wait */
    }
    _delay_ms(5 * DELAYTIME);                                 /* pause */

                                                           /* Go Right */
    for (i = 7; i < 255; i--) {
      LED_PORT |= (1 << i);                    /* turn on the i'th pin */
      _delay_ms(DELAYTIME);                                    /* wait */
    }
    for (i = 7; i < 255; i--) {
      LED_PORT &= ~(1 << i);                  /* turn off the i'th pin */
      _delay_ms(DELAYTIME);                                    /* wait */
    }
    _delay_ms(5 * DELAYTIME);                                 /* pause */

  }
  return 0;                            /* This line is never reached */
}
