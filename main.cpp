#include "lcd.hpp"
#include "timer.hpp"
#include "menu.hpp"
#include "keypad.hpp"

#include <avr/interrupt.h>

#include <stdlib.h>
#include <stdio.h>

/**
 * Obsługa wyświetlacza, buzzera i klawiatury.
 *
 * @param menu Menu na wyświetlaczu.
 * @param keypad Klawiatura.
 */
void onSystemTick(Menu& menu, const Keypad& keypad)
{
	menu.onKey(keypad.key());
	menu.refresh();
}

/**
 * Funkcja główna.
 */
int main()
{
	const SystemTick tick;
	const Lcd lcd;
	const Keypad keypad;
	Menu menu{lcd};

	tick.init();
	lcd.init();
	keypad.init();
	menu.init();
	sei();

	while (true) {
		if (tick.pop()) {
			onSystemTick(menu, keypad);
		}
	}

	return EXIT_SUCCESS;
}