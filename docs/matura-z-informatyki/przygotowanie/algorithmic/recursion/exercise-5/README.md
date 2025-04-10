# Ćwiczenie 5

Przeanalizuj poniższy algorytm i wykonaj zadania.

## Pseudokod

```
Funkcja per(A, pocz, kon):
    1. Jeżeli pocz > kon, to:
        2. Wypisz A
        3. Zakończ
    4. Dla i := pocz do kon, wykonuj:
        5. Zamień(A[pocz], A[i])
        6. per(A, pocz + 1, kon)
        7. Zamień(A[pocz], A[i])
```

!!! info
	 **Zamień** zamienia dwie zmienne wartościami.

## Zadanie 1

Podaj wynik działania algorytmu dla danych:

- $A[1..3] = [1, 2, 3]$
- $pocz = 1$
- $kon = 3$

## Zadanie 2

Uzupełnij poniższą tabelę podając liczbę wypisanych wartości dla wskazanych argumentów.

|  A     | pocz | kon | Liczba wyników |
| :-:    | :--: | :-: | :----:         |
| [1..1] | 1    |  1  | 1              |
| [1..2] | 1    |  2  | 2              |
| [1..3] | 1    |  3  |                |
| [1..4] | 1    |  4  |                |
| [1..5] | 1    |  5  |                |
| [1..n] | 1    |  n  |                |
