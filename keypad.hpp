#pragma once

/**
 * Stan klawiatury.
 */
enum KEY {
	KEY_NONE, ///< Żaden klawisz nie jest wciśnięty.
	KEY_DOWN, ///< Wciśnięty klawisz "Start".
	KEY_UP ///< Wciśnięty klawisz "Stop".
};

/**
 * Sterownik klawiatury.
 */
struct Keypad {
	/**
	 * Inicjalizacja GPIO.
	 */
	void init() const;

	/**
	 * Odczytuje bieżący stan klawiatury.
	 *
	 * @return Wciśnięty klawisz.
	 */
	KEY key() const;
};