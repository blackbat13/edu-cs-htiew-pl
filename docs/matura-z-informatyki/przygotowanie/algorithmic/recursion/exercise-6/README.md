# Ćwiczenie 6

Przeanalizuj poniższy algorytm i wykonaj zadania.

## Pseudokod

```
Funkcja sort(A, pocz, kon):
    1. Jeżeli A[pocz] > A[kon], to:
        2. Zamień(A[pocz], A[kon])
    3. Jeżeli kon - pocz + 1 > 2:
        4. t := (kon - pocz + 1) div 3
        5. A := sort(A, pocz, kon - t)
        6. A := sort(A, pocz + t, kon)
        7. A := sort(A, pocz, kon - t)
    8. Zwróć A
```

!!! info
	 **Zamień** zamienia dwie zmienne wartościami.

!!! info
	 **div** oznacza dzielenie całkowite.

## Zadanie 1

Narysuj drzewo wywołań rekurencyjnych dla danych:

- $A[1..3] = [5, 1, 3]$
- $pocz = 1$
- $kon = 3$

## Zadanie 2

Narysuj drzewo wywołań rekurencyjnych dla danych:

- $A[1..4] = [5, 1, 3, 4]$
- $pocz = 1$
- $kon = 4$

## Zadanie 3

Uzupełnij poniższą tabelkę podając liczbę wywołań funkcji *sort* (łącznie z początkowym wywołaniem) dla dowolnej zawartości tablicy $A$ oraz podanych wartości $pocz$ i $kon$.

|  A     | pocz | kon | Liczba wyników |
| :-:    | :--: | :-: | :----:         |
| [1..1] | 1    |  1  | 1              |
| [1..2] | 1    |  2  | 1              |
| [1..3] | 1    |  3  |                |
| [1..4] | 1    |  4  |                |
