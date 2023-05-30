#pragma once

#include "lcd.hpp"
#include "keypad.hpp"
#include "buzzer.hpp"

/**
 * Menu na wyświetlaczu.
 */
struct Menu {
	/**
	 * Konstruktor.
	 *
	 * @param lcd Sterownik wyświetlacza.
	 */
	Menu(const Lcd& lcd):
		lcd{lcd},
		time{-1}
	{}

	/**
	 * Wyświetla wyjściowe elementy menu.
	 */
	void init() const;

	/**
	 * Odświeża stan ekranu.
	 */
	void refresh(const Buzzer& buzzer);

	/**
	 * Obsługuje zdarzenie z pokrętłą impulsatora.
	 *
	 * @param key Wciśnięty klawisz.
	 */
	void onKey(KEY key);

private:
	const Lcd& lcd; ///< Sterownik wyświetlacza.
	int16_t time; ///< Bieżący stan odliczonego czasu.
};