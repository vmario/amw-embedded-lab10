#pragma once

/**
 * Stan klawiatury.
 */
enum KEY {
	KEY_NONE, ///< Żaden klawisz nie jest wciśnięty.
	KEY_START, ///< Wciśnięty klawisz "Start".
	KEY_STOP ///< Wciśnięty klawisz "Stop".
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