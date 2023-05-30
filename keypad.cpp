#include "keypad.hpp"

#include <avr/io.h>

#define KEYPAD_PORT PORTB ///< Rejestr PORT klawiatury.
#define KEYPAD_PIN PINB ///< Rejestr PIN klawiatury.
#define KEYPAD_DOWN_BIT PB0 ///< Pin klawisza "Down".
#define KEYPAD_UP_BIT PB1 ///< Pin klawisza "Up".

void Keypad::init() const
{
	KEYPAD_PORT |= _BV(KEYPAD_DOWN_BIT) | _BV(KEYPAD_UP_BIT);
}

KEY Keypad::key() const
{
	if (bit_is_clear(KEYPAD_PIN, KEYPAD_DOWN_BIT)) {
		return KEY_DOWN;
	} else if (bit_is_clear(KEYPAD_PIN, KEYPAD_UP_BIT)) {
		return KEY_UP;
	} else {
		return KEY_NONE;
	}
}