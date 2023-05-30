#include "menu.hpp"

#include <string.h>
#include <stdio.h>

const uint8_t TICKS_PER_SECOND{1}; ///< Liczba tików systemowych na sekundę.
const int16_t BRUSH_TIME{2 * 60 * TICKS_PER_SECOND}; ///< Czas szczotkowania.

enum PERIOD {
	PERIOD_UP_LEFT = BRUSH_TIME / 4 * 4, ///< Czas na górną lewą część uzębienia.
	PERIOD_UP_RIGHT = BRUSH_TIME / 4 * 3, ///< Czas na górną prawą część uzębienia.
	PERIOD_DOWN_LEFT = BRUSH_TIME / 4 * 2, ///< Czas na dolną lewą część uzębienia.
	PERIOD_DOWN_RIGHT = BRUSH_TIME / 4 * 1, ///< Czas na dolną prawą część uzębienia.
};

void Menu::init() const
{
	lcd.clear();
	lcd.goTo(0, 4);
	lcd.write("Brushing");
	lcd.goTo(1, 6);
	lcd.write("time!");
}

void Menu::refresh(const Buzzer& buzzer)
{
}

void Menu::onKey(KEY key)
{
}