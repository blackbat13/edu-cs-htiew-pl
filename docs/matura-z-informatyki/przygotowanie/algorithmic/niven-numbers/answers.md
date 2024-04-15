# Rozwiązania

## Zadanie 1

| **n** | **Suma cyfr** | **Liczba Nivena** |
|:-----:|:-------------:|:-----------------:|
|   1   |       1       |        TAK        |
|  123  |       6       |        NIE        |
|   48  |       12      |        TAK        |
|  453  |       12      |        NIE        |
|  800  |       8       |        TAK        |

## Zadanie 2

```
funkcja sumuj_cyfry(n):
    1. suma := 0
    2. Dopóki n > 0:
        3. suma := suma + n mod 10
        4. n := n // 10
    5. Zwróć suma

funkcja czy_liczba_nivena(n):
    1. Jeśli n mod sumuj_cyfry(n) = 0:
        2. Zwróć PRAWDA
    3. Zwróć FAŁSZ
```

## Zadanie 3

### Odpowiedź

```
423612
437805
257124
271809
638187
398115
113632
480975
150332
276780
682539
323622
101762
496587
```

### Rozwiązanie

=== "Python"

    ```python linenums="1"
    def is_niven(n):
        return n % (sum(map(int, str(n)))) == 0


    with open("niven.txt") as file:
        numbers = [int(line) for line in file]

    niven_numbers = [k for k in numbers if is_niven(k)]

    print(*niven_numbers, sep="\n")
    ```
