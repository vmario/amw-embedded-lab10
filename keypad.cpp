#include "keypad.hpp"

#include <avr/io.h>

#define KEYPAD_PORT PORTD ///< Rejestr PORT klawiatury.
#define KEYPAD_PIN PIND ///< Rejestr PIN klawiatury.
#define KEYPAD_START_BIT PD0 ///< Pin klawisza "Start".
#define KEYPAD_STOP_BIT PD1 ///< Pin klawisza "Stop".

void Keypad::init() const
{
}

KEY Keypad::key() const
{
	return KEY_NONE;
}