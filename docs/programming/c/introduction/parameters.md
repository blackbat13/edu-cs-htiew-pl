# Wejście jako parametry

W języku C można wczytywać parametry z linii poleceń podczas uruchamiania programu za pomocą funkcji `main`, która może przyjmować dwa argumenty: `argc` i `argv`.

## Argumenty funkcji main

Często, gdy tworzymy funkcję `main`, to po jej nazwie podajemy puste nawiasy. Funkcja ta jednak może przyjmować dwa argumenty, opisane poniżej.

- `int argc`: liczba argumentów przekazanych do programu, wliczając nazwę programu.
- `char *argv[]`: tablica wskaźników do argumentów, gdzie każdy element tablicy jest wskaźnikiem do ciągu znaków reprezentującego jeden argument.

## Przykład

Spójrzmy na poniższy przykład, by lepiej zrozumieć z czym mamy do czynienia. Poniższy kod wypisuje liczbę przekazanych mu argumentów podczas uruchamiania, a także wypisuje każdy z tych argumentów.

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Liczba argumentów: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}
```

## Uruchamianie programu

Załóżmy, że zapisaliśmy powyższy kod w pliku `program.c` i skompilowaliśmy go do pliku wykonywalnego (`a.out` pod Linuxem, `a.exe` pod Windowsem). Możemy uruchomić nasz program z argumentami w następujący sposób:

=== "Linux"

    ```bash
    ./a.out arg1 arg2 arg3
    ```

=== "Windows"

    ```bat
    .\a.exe arg1 arg2 arg3
    ```

Wynik działania programu będzie wyglądał następująco:

=== "Linux"

    ```
    Liczba argumentów: 4
    Argument 0: ./a.out
    Argument 1: arg1
    Argument 2: arg2
    Argument 3: arg3
    ```

=== "Windows"

    ```
    Liczba argumentów: 4
    Argument 0: .\a.exe
    Argument 1: arg1
    Argument 2: arg2
    Argument 3: arg3
    ```

Jak widać, pierwszy argument to zawsze sposób, w jaki uruchomiliśmy nasz program.
