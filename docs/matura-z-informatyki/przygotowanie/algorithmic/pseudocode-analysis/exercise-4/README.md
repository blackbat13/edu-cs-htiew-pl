# Ćwiczenie 4

Zapoznaj się z poniższą specyfikacją oraz pseudokodem, a następnie rozwiąż zadania.

## Specyfikacja

### Dane

* $n$ - liczba naturalna, liczba elementów w tablicy.
* $tab[1..n]$ - tablica $n$ wartości całkowitych, numerowana od jedynki.

## Pseudokod

```
1. el := tab[1]
2. i := 1
3. Dopóki i <= n, wykonuj:
    4. Jeżeli tab[i] > el, to:
        5. el := tab[i]
    6. i := i + 1
    
7. Wypisz el
```

## Zadanie 1

Podaj wynik programu dla danych `n := 5, tab := [4, 7, 2, 10, 1]`

## Zadanie 2

Podaj wynik programu dla danych `n := 10, tab := [5, 8, 1, 3, 6, 10, 1, 10, 12, 9]`

## Zadanie 3

Ile razy zostanie wykonana instrukcja **4** dla danych z pierwszego zadania, a ile razy dla danych z drugiego zadania?

## Zadanie 4

Podaj **specyfikację wyniku** dla powyższego algorytmu.

## Zadanie 5

Jaka jest złożoność powyższego algorytmu?
