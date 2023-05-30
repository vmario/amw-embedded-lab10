#include "buzzer.hpp"

#include <avr/io.h>
#include <util/delay.h>

#define BUZZER_PORT PORTD ///< Rejestr PORT buzzera.
#define BUZZER_DDR DDRD ///< Rejestr DDR buzzera.
#define BUZZER_BIT PD3 ///< Pin buzzera.

void Buzzer::init() const
{
}

void Buzzer::shortBeep() const
{
}

void Buzzer::longBeep() const
{
}