# Rozwiązania

## Zadanie 1

| **k** | **Liczba gnomiczna** |
|:-----:|:-----------------:|
|   9   |        TAK        |
|  10  |        NIE        |
|   15  |        TAK           |
|  24  |         NIE          |
|  121  |         TAK          |

## Zadanie 2

```
funkcja czy_gnomiczna(k):
    1. Jeżeli k mod 2 == 1:
        2. Zwróć PRAWDA
    3. Zwróć FAŁSZ
```

## Zadanie 3

### Odpowiedź

$42$

### Rozwiązanie

=== "Python"

    ```python linenums="1"
    with open("gnomiczne.txt") as file:
        binary = file.read().strip().split("\n")

    for num in binary:
        if num[-1] == '1':
            result += 1

    print(result)
    ```
