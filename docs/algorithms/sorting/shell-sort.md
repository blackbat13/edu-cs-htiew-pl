---
description: Shellsort
---

# Sortowanie Shella

Sortowanie Shella (ang. *Shellsort*) można traktować jako uogólnienie algorytmów sortowania przez wstawianie lub sortowania bąbelkowego. Różni się od wspomnianych algorytmów tym, że dopuszcza porównywanie i zamianę elementów leżących daleko od siebie. W jakiej odległości będą się znajdować porównywane elementy zależy już od konkretnej wersji algorytmu. Początkowo porównywane są elementy bardziej od siebie oddalone, a z każdym przejściem odległość ta maleje.

W oryginalnej wersji algorytmu odstęp jest równy $N/2^k$, gdzie $N$ to rozmiar sortowanej tablicy, a $k$ to numer iteracji algorytmu

## Animacja

[Animacja sortowania Shella](https://www.youtube.com/watch?v=n4sk-SzGvZA)

## Taneczne sortowanie

[Taneczne sortowanie](https://www.youtube.com/watch?v=CmPA7zE8mx0&t=2s)

## Pseudokod

```
procedura SortowanieShella(A, n):
    1. odstep := n div 2
    2. dopóki odstep > 0:
        3. dla i := 1 do n - odstep:
            4. Jeżeli A[i] > A[i + odstep], to:
                5. Zamień(A[i], A[i + odstep])
        6. odstep := odstep div 2
```

## Złożoność

Złożoność czasowa algorytmu zależna jest od stosowanego ciągu odstępów. Złożonośc oryginalnej wersji algorytmu jest rzędu $O(n^2)$.

## Implementacja

### [C++](../../programming/c++/algorithms/sorting/shell-sort.md)

### [Python](../../programming/python/algorithms/sorting/shell-sort.md)
