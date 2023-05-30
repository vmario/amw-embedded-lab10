#include "menu.hpp"

#include <avr/io.h>

#include <string.h>
#include <stdio.h>

void Menu::init() const
{
	lcd.clear();
	lcd.goTo(0, 0);
	lcd.write("Brightness:");
}

void Menu::refresh()
{
}

void Menu::onKey(KEY key)
{
}