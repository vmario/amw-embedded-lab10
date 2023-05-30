#pragma once

#include "lcd.hpp"
#include "keypad.hpp"

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
		lcd{lcd}
	{}

	/**
	 * Wyświetla wyjściowe elementy menu.
	 */
	void init() const;

	/**
	 * Odświeża stan ekranu.
	 */
	void refresh();

	/**
	 * Obsługuje zdarzenie wciśnięcia klawisza.
	 *
	 * @param key Wciśnięty klawisz.
	 */
	void onKey(KEY key);

private:
	const Lcd& lcd; ///< Sterownik wyświetlacza.
};