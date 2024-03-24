# Obsługa wejścia-wyjścia

## Wyjście

Najprostszym sposobem na wypisanie komunikatu jest skorzystanie z polecenia `echo`.

### Przykład 1

Do polecenia echo możemy przekazać tekst zamknięty w podwójny cudzysłów.
Tekst ten zostanie wypisany w konsoli po uruchomieniu skryptu.

```bash
#!/bin/bash

echo "Hello World!"
```

### Przykład 2

Komunikat do wypisania możemy także zapisać w zmiennej, którą następnie przekazujemy do polecenia echo.
W tym celu przed nazwą zmiennej wstawiamy znak dolara.

```bash
#!/bin/bash

# Tworzymy zmienna
powitanie="Hello World!"

# Wypisujemy wartosc zmiennej
echo $powitanie
```

### Przykład 3

Wartości zmiennych możemy także podstawiać wewnątrz komunikatów, jednak tylko wtedy, gdy komunikat opatrzymy podwójnym cudzysłowiem.
Gdy tekst zamknięty jest w pojedyńczy cudzysłów, to znaki specjalne, takie jak dolar, nie są interpretowane.

Możemy także zignorować znaczenie specjalnego znaku w standardowym tekście poprzez skorzystanie ze znaku `\`.

```bash
#!/bin/bash

powitanie="Hello World!"

# Tekst z interpretowaniem symboli
echo "Komunikat: $powitanie"

# Czysty tekst
echo 'Komunikat: $powitanie'

# Ignorowanie specjalnego znaczenia znaku
echo "Komunikat: \$powitanie"
```

## Wejście

Jednym ze sposobów na wczytanie wejścia od użytkownika z poziomu konsoli jest użycie polecenia `read`.
Możemy także korzystać z wartości przekazanych podczas uruchamiania skryptu.

### Przykład 1

Polecenie read pozwala nam w sposób interaktywny wczytać wejście od użytkownika i zapisać je w podanej zmiennej.

```bash
#!/bin/bash

echo "Wpisz swoj nick:"

# Wartosci z wejscia wczytujemy poleceniem read
read username

echo "Podano: $username"
echo
echo "Podaj 3 liczby:"

read num1 num2 num3
echo "Podano: $num1, $num2, $num3"

# Korzystamy z read w formie prompt
read -p "Tekst: " tekst
echo $tekst
```

### Przykład 2

Parametry przekazane podczas uruchamiania skryptu możemy odczytać korzystając ze znaku dolar, po którym podajemy liczbę oznaczającą numer parametru.

```bash
#!/bin/bash

echo "Polecenie: $0"
echo "Pierwszy parametr: $1"
echo "Drugi parametr: $2"
echo "Wszystkie parametry: $@"
echo "Liczba parametrow: $#"
```