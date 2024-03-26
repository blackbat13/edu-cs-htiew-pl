# Ćwiczenie 3

Zapoznaj się z poniższą specyfikacją oraz pseudokodem, a następnie rozwiąż zadania.

## Specyfikacja

### Dane

* $n$ - liczba naturalna

## Pseudokod

```
funkcja fun(n):
    1. Jeżeli n <= 2, to
        2. Zwróc 1 i zakończ
    3. wynik := fun(n - 1) + 2 * fun(n - 2)
    4. Zwróć wynik i zakończ
```

## Zadanie 1

Podaj wyniki funkcji dla kolejnych wartości $n$ od $1$ do $10$.

## Zadanie 2

Uzupełnij poniższą definicję rekurencyjną zgodnie z działaniem algorytmu:
$fun(n) =  \begin{cases}        ? & n\leq 2 \\       ? & n > 2 \\    \end{cases}$ 

## Zadanie 3

Ile razy zostanie wykonane wywołanie `fun(2)` podczas obliczania wyniku dla `n := 5`?

## Zadanie 4

Rozrysuj *drzewo wywołań rekurencyjnych* dla wywołania `fun(5)`.
