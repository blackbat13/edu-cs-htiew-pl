# Połączenia HTTPS

Podczas nasłuchiwania połączeń szyfrowanych HTTPS w programie Wireshark nie zobaczymy szczegółów pobieranych danych, np. kodu pobieranej strony, ponieważ dane będą zaszyfrowane. W celu odszyfrowania tych danych należy wykonać następujące czynności.

## 1. Ustawiamy zmienną środowiskową SSLKEYLOGFILE

1. W menu start wyszukujemy "***Edytuj zmienne środowiskowe systemu***".
2. Klikamy przycisk "***Zmienne środowiskowe***".
3. Dodajemy nową zmienną środowiskową dla zalogowanego użytkownika klikając pierwszy od góry przycisk "***Nowa...***".
4. W pole "***Nazwa zmiennej***" wpisujemy **SSLKEYLOGFILE**
5. W pole "***Wartość zmiennej***" wpisujemy ścieżkę do pliku, w którym będziemy przechowywać logi dotyczące połączeń SSL, np. `C:\Users\[NazwaUżytkownika]\Documents\Wireshark\ssl-keys.log`.
6. Zatwierdzamy dodanie zmiennej przyciskiem "***OK***".

## 2. Weryfikujemy pojawienie się pliku z logami

1. Otwieramy przeglądarkę, np. Google Chrome.
2. Wchodzimy na stronę zabezpieczoną przez https, np. [https://pl.wikipedia.org/wiki/Wikipedia:Strona_g%C5%82%C3%B3wna](https://pl.wikipedia.org/wiki/Wikipedia:Strona_g%C5%82%C3%B3wna)
3. Otwieramy ścieżkę, którą podaliśmy w polu "***Wartość zmiennej***".
4. Powinniśmy zobaczyć plik z logami, np. "***ssl-keys.log***".

## 3. Zmieniamy ustawienia programu Wireshark

1. W programie Wireshark wchodzimy w menu "***Edytuj->Preferencje..***".
2. W menu po lewej rozwijamy "***Protocols***" i wybieramy "***TLS***".
3. W opcji "***(Pre)-Maste-Secret log filename***" klikamy przycisk "***Przeglądaj***" i wybieramy plik z logami utworzony wcześniej przez przeglądarkę.
4. Zatwierdzamy zmiany przyciskiem "***OK***".
