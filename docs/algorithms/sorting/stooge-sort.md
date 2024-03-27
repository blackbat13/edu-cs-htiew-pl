---
description: Stoogesort
---

# Sortowanie stooge

Sortowanie stooge (ang. *Stoogesort*) to rekurencyjny algorytm sortowania znany przede wszystkim ze swojej wyjątkowo złej złożoności czasowej.

## Animacja

![By Simpsons contributor - Own work, CC0, https://commons.wikimedia.org/w/index.php?curid=16021267](../../assets/Sorting_stoogesort_anim.gif)

## Pseudokod

```
procedura SortowanieStooge(A, i, j):
    1. Jeżeli A[i] > A[j], to:
        2. Zamień(A[i], A[j])

    3. Jeżeli j - i > 1, to:
        4. t := (j - i + 1) div 3
        5. SortowanieStooge(A, i, j - t)
        6. SortowanieStooge(A, i + t, j)
        7. SortowanieStooge(A, i, j - t)
```

## Złożoność

Złożoność czasowa algorytmu jest rzędu $O(n^{\log{3}/\log{1.5}})=O(n^{2.7095...})$

## Implementacja

### [C++](../../programming/c++/algorithms/sorting/stooge-sort.md)

### [Python](../../programming/python/algorithms/sorting/stooge-sort.md)
