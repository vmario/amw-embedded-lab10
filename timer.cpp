#include "timer.hpp"

#include "lcd.hpp"

#include <avr/interrupt.h>
#include <util/atomic.h>

#define BACKLIGHT_DDR DDRB ///< Rejestr DDR podświetlenia.
#define BACKLIGHT_BIT PB3 ///< Pin podświetlenia.

/**
 * Połowa jasności podświetlenia.
 */
static uint8_t HALF_BRIGHTNESS{80};

/**
 * Konfiguracja Timer/Counter0 w trybie Fast PWM.
 */
static constexpr uint8_t TIMER0_FAST_PWM = _BV(WGM01) | _BV(WGM00);

/**
 * Taktowanie Timer/Counter0 zegarem podzielonym przez 64.
 */
static constexpr uint8_t TIMER0_PRESCALER_64 = _BV(CS01) | _BV(CS00);

/**
 * Konfiguracja OC0A w trybie normalnym.
 */
static constexpr uint8_t TIMER0_NON_INVERTING_MODE = _BV(COM0A1);

static volatile bool expired; ///< Czy timer ustawił flagę?

/**
 * Obsługa przerwania TIMER0_OVF.
 */
ISR(TIMER0_OVF_vect)
{
	expired = true;
}

void SystemTick::init() const
{
	TCCR0A = TIMER0_FAST_PWM | TIMER0_NON_INVERTING_MODE;
	TCCR0B = TIMER0_PRESCALER_64;
	OCR0A = HALF_BRIGHTNESS;
	TIMSK0 = _BV(TOIE0);
	BACKLIGHT_DDR = _BV(BACKLIGHT_BIT);
}

bool SystemTick::pop() const
{
	bool status;
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
		status = expired;
		if (status) {
			expired = false;
		}
	}
	
	return status;
}