# Procesy

## Procesy działające w tle

Domyślnie, jak uruchamiamy jakiś proces, program, to urachmiany jest "na planie głównym".
Między innymi oznacza to, że program "blokuje" nam terminal.
Istnieje jednak możliwość uruchomienia procesu w tle, albo uśpienia działającego procesu.

### Uruchomienie procesu w tle

Aby uruchomić proces w tle, należy po poleceniu dodać znak ampersant: **&**.

#### Przykład

```
./program &
```

### Uśpienie procesu

Aby uśpić działający na pierwszym planie proces, należy użyć skrótu **CTRL+Z**.

### Przeniesienie procesu na pierwszy plan

Aby przenieść uśpiony proces na pierwszy plan, użyjemy polecenia **fg** (ang. __foreground__).

## ps

Polecenie **ps** pozwala nam zobaczyć listę aktualnie uruchomionych procesów.
Pozwala nam stwierdzić, czym zajmują się poszczególne procesy, ile pamięci zużywają, ile czasu procesora potrzebują itp.

Polecenie **ps** wyświetla dane w następujących kolumnach:
* **PID**: identyfikator procesu
* **TTY**: type terminala, na którym proces jest uruchomiony
* **TIME**: ile czasu procesora jest zużywane na działanie procesu
* **CMD**: nazwa polecenia

### Przykładowe opcje

* **-ef**: wyświetla wszystkie procesy w pełnym formacie
* **-u** _username_: wyświetla procesy konkretnego użytkownika
* **-C** _cmd_: wyświetla procesy dla zadanego polecenia
* **-p** _PID_: wyświetla proces z zadanym identyfikatorem
* **-L**: wyświetla wszystkie wątki dla zadanego procesu

## top

Polecenie **top** wyświetla wszystkie działające procesy w czasie rzeczywistym.
Jest przydatne do monitorowania wydajności systemu.
Głównie jest używane do sprawdzenia obciążenia systemu przez administratorów.

### Znaczenie wyjścia

#### Linia 1

* czas
* jak długo system działa
* ilu użytkowników jest zalogowanych
* średnie obciążenie

#### Linia 2

* całkowita liczba zadań
* liczba działających zadań
* liczba uśpionych zadań
* liczba zatrzymanych zadań
* liczba zadań zombie

#### Linia 3

Procentowe zużycie procesora dla:

* użytkowników
* systemu
* procesów o niskim priorytecie (low priority processes)
* bezczynnych procesów (idle processes)
* czekających na wejście/wyjście (io wait)
* przerwań sprzętowych (hardware interrupts)
* przerwań systemowych (software interrupts)
* steal time

#### Linia 4

Zużycie pamięci w kilobajtach:

* pełna pamięć (total memory)
* wykorzystana pamięć (used memory)
* wolna pamięć (free memory)
* zbuforowana pamięć (buffered memory)

#### Linia 5

Zużycie pamięci wymiany (swap) w kilobajtach:

* pełna pamięć (total memory)
* wykorzystana pamięć (used memory)
* wolna pamięć (free memory)
* cached memory


#### Nagłówki tabeli

* ID procesu
* użytkownik
* priorytet
* nice user
* pamięć wirtualna
* resident memory
* pamięć współdzielona
* proces używanego CPU
* procent używanej pamięci
* czas działania procesu
* polecenie