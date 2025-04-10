# Ćwiczenie 4

Zapoznaj się z poniższą specyfikacją oraz pseudokodem, a następnie rozwiąż zadania.

## Specyfikacja

### Dane

* n - liczba naturalna, $n>0$. 

## Pseudokod

```
funkcja fun(n):
    1. Jeżeli n = 0, to
        2. Zakończ
    3. Jeżeli n mod 2 = 0, to 
        4. Wywołaj fun(n div 2)
        5. Wypisz "0"
    6. Jeżeli n mod 2 = 1, to
        7. Wywołaj fun(n div 2)
        8. Wypisz "1"
```

## Zadanie 1

Przeanalizuj powyższą funkcję i uzupełnij poniższą tabelkę.

|  n  | Wypisany komunikat |
| :-: | :----------------: |
|  1  |         "1"        |
|  2  |        "10"        |
|  4  |                    |
|  5  |                    |
|  10 |                    |
|  20 |                    |

## Zadanie 2

Oblicz ilość wywołań funkcji `fun` dla różnych wartości $n$.

| n   | liczba wywołań funkcji fun |
| :-: | :------------------------: |
| 0   | 1                          |
| 1   | 2                          |
| 4   |                            |
| 8   |                            |
| 10  |                            |
| 16  |                            |
| 20  |                            |

## Zadanie 3

Jaka jest złożoność funkcji `fun`?
