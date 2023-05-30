#pragma once

/**
 * Sterownik buzzera.
 */
struct Buzzer{
	/**
	 * Inicjalizacja GPIO.
	 */
	void init() const;

	/**
	 * Krótki sygnał dźwiękowy.
	*/
	void shortBeep() const;

	/**
	 * Długi sygnał dźwiękowy.
	 * 
	 * (Kilkukrotne powtórzenie krótkiego).
	 */
	void longBeep() const;
};