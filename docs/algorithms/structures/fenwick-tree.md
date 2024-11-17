# Drzewo Fenwicka

Struktura danych znana jako Drzewo Fenwicka (ang. *Fenwick Tree*), lub Drzewo Indeksowane Binarnie (ang. *Binary Indexed Tree*, *BIT*) jest używana do efektywnego przechowywania i manipulowania prefiksowymi sumami elementów tablicy. Umożliwia szybkie wykonywanie operacji takich jak:

1. Aktualizacja wartości elementu tablicy w czasie $O(\log{n})$.
2. Obliczanie sumy prefiksowej (sumy elementów od początku tablicy do danego indeksu) w czasie $O(\log{n})$.

Drzewo Fenwicka jest szczególnie przydatne w sytuacjach, gdzie często wykonuje się operacje aktualizacji i zapytań o sumy prefiksowe, np. w algorytmach przetwarzania strumieni danych, analizie danych i problemach związanych z dynamicznymi tablicami.

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/structures/fenwick-tree.md){ .md-button }
