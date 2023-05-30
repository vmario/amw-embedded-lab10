---
title: "Instrukcja laboratorium systemów wbudowanych"
subtitle: "Ćwiczenie 10: Sterowanie podświetleniem wyświetlacza i&nbsp;zaawansowana obsługa przycisków"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.jpg"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
  \usepackage{gensymb}
...

> First, solve the problem. Then, write the code.
>
> — _John Johnson_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* sterowaniem podświetlenia wyświetlacza alfanumerycznego,
* zaawansowaną obsługą przycisków.

# Uruchomienie programu wyjściowego

1. Umieść zworki na pinach `RS`, `E` i `D4`…`D7` złącza `J10` (na lewo od buzzera).
1. Podłącz prawy pin `LED` złącza `J10` do pinu `PB3` mikrokontrolera.
1. Zdejmij zworkę `J45` (`BACKLIGHT`) pod wyświetlaczem.
1. Zworkę `J15` (nad buzzerem) ustaw w pozycji `RW->GND`.
1. Umieść wyświetlacz w złączu `DIS1`.
1. Podłącz przycisk `K1` do pinu `PB0` mikrokontrolera.
1. Podłącz przycisk `K2` do pinu `PB1` mikrokontrolera.
1. Po uruchomieniu na wyświetlaczu pokaże się komunikat _Brightness:_.
1. Wyświetlacz świeci się połową jasności.

# Zadanie podstawowe

## Wymagania funkcjonalne

Celem zadania podstawowego jest regulacja jasności podświetlenia wyświetlacza alfanumerycznego (diody LED umieszczonej pod wyświetlaczem).

1. Obok napisu _Brightness:_ wyświetla się bieżący stan rejestru `OCR0A`, regulującego jasność.
1. Wciśnięcie przycisku `K1` zmniejsza jasność wyświetlacza.
1. Wciśnięcie przycisku `K2` zwiększa jasność wyświetlacza.

## Modyfikacja programu

1. W metodzie `Menu::refresh()` dodaj wyświetlanie wartości rejestru `OCR0A`.
1. W metodzie `Menu::onKey()` obsłuż reakcję na wciśnięcie przycisków.

\awesomebox[teal]{2pt}{\faCode}{teal}{Możesz użyć funkcji \lstinline{snprintf()} do sformatowania łańcucha znaków z wartością liczbową.}

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Timer 0 taktuje odświeżanie ekranu i odczyt klawiatury, a jednocześnie pełni fukcję PWM, którego wypełnienie reguluje rejestr \lstinline{OCR0A}.}

# Zadanie rozszerzone

## Wymagania funkcjonalne

Celem zadania rozszerzonego jest usprawnienie działania klawiatury.

1. Krótkie wciśnięcie przycisku powinno zmieniać wartość jasności o jeden.
1. Długie przytrzymanie przycisku powinno zmieniać jasność z większą szybkością.

## Modyfikacja programu

1. W metodzie `Menu::onKey()` zaimplementuj zaawansowaną obsługę przycisków.
