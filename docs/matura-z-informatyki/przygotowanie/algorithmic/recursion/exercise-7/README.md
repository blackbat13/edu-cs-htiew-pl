# Ćwiczenie 7

Przeanalizuj poniższy algorytm i wykonaj zadania.

## Pseudokod

```
Fukcja fun(a, b):
    1. Jeżeli a > b, to:
        2. Zwróć ""
    3. c := (a + b) div 2
    4. Jeżeli c mod 2 = 0, to:
        5. Zwróć fun(a, c - 1) + "0" + fun(c + 1, b)
    6. W przeciwnym przypadku:
        7. Zwróć fun(a, c - 1) + "1" + fun(c + 1, b)
```

## Zadanie 1

Uzupełnij poniższą tabelę o wyniki działania funkcji `fun` dla podanych parametrów.

| **a** | **b** | **fun(a,b)** |
|:-----:|:-----:|:------------:|
|   0   |   2   |      010     |
|   1   |   4   |     1010     |
|   2   |   5   |              |
|   3   |   8   |              |
|   7   |   10  |              |

## Zadanie 2

Podaj przykładowe wartości **a** oraz **b**, dla których funkcja `fun` zwróci wynik zawierający dokładnie pięć zer oraz pięć jedynek.

## Zadanie 3

Uzupełnij poniższą tabelę podając liczbę wywołań funkcji `fun` (wliczając w to początkowe wywołanie) dla podanych parametrów.

| **a** | **b** | **Liczba wywołań** |
|:-----:|:-----:|:----------------:|
|   0   |   5   |      13          |
| 1 | 5 | 11 |
| 0 | 6 |   |
| 1 | 6 |   |
| 0 | 10 |  |
| 2 | 20 |  |

## Zadanie 4

Podaj wzór na liczbę wywołań funkcji `fun` dla dowolnych liczb naturalnych $a$ oraz $b$, takich że $a\leq b$.
