#include "lcd.hpp"
#include "timer.hpp"
#include "menu.hpp"
#include "keypad.hpp"
#include "buzzer.hpp"

#include <avr/interrupt.h>

#include <stdlib.h>
#include <stdio.h>

/**
 * Obsługa wyświetlacza, buzzera i klawiatury.
 *
 * @param menu Menu na wyświetlaczu.
 * @param keypad Klawiatura.
 * @param buzzer Buzzer.
 */
void onSystemTick(Menu& menu, const Keypad& keypad, const Buzzer& buzzer)
{
	menu.onKey(keypad.key());
	menu.refresh(buzzer);
}

/**
 * Funkcja główna.
 */
int main()
{
	const SystemTick tick;
	const Lcd lcd;
	const Buzzer buzzer;
	const Keypad keypad;
	Menu menu{lcd};

	tick.init();
	lcd.init();
	buzzer.init();
	keypad.init();
	menu.init();
	sei();

	while (true) {
		if (tick.pop()) {
			onSystemTick(menu, keypad, buzzer);
		}
	}

	return EXIT_SUCCESS;
}