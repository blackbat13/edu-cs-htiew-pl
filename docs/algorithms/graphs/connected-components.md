# Spójne składowe

Spójna składowa w grafie to taki podzbiór wierzchołków, że między dowolnymi dwoma wierzchołkami z tego podzbioru istnieje ścieżka. W przypadku grafu nieskierowanego, mówimy, że jest spójny, jeśli istnieje tylko jedna spójna składowa, czyli jeśli istnieje ścieżka między każdą parą wierzchołków. W przypadku grafów skierowanych pojęcie to rozwija się do silnej spójności, gdzie musi istnieć ścieżka w obu kierunkach między każdą parą wierzchołków.

## Obliczanie liczby spójnych składowych

Algorytm do obliczania liczby spójnych składowych w grafie zazwyczaj opiera się na jednym z dwóch podstawowych algorytmów przeszukiwania grafu: przeszukiwania wszerz (BFS) lub przeszukiwania w głąb (DFS).

Przyjrzyjmy się, jak wygląda algorytm wykorzystujący metodę DFS do obliczania liczby spójnych składowych:

1. Inicjalizacja: Na początku wszystkie wierzchołki są nieodwiedzone.
2. Wybieramy dowolny nieodwiedzony wierzchołek i rozpoczynamy od niego przeszukiwanie w głąb (DFS).
3. Po zakończeniu przeszukiwania w głąb z danego wierzchołka, wszystkie wierzchołki, które odwiedziliśmy, należą do tej samej spójnej składowej. Oznaczamy te wierzchołki jako odwiedzone.
4. Zwiększamy licznik spójnych składowych o $1$.
5. Powtarzamy kroki $2$-$4$, dopóki wszystkie wierzchołki nie zostaną odwiedzone.

Podobny algorytm można również opracować z użyciem BFS zamiast DFS. Przy odpowiedniej implementacji wystarczy zamienić wykorzystywaną strukturę danych (ze stosu na kolejkę).

## Złożoność obliczeniowa

Złożoność obliczeniowa tego algorytmu to $O(V+E)$, gdzie $V$ to liczba wierzchołków, a $E$ to liczba krawędzi w grafie. Jest to złożoność typowego przeszukiwania grafu (DFS lub BFS).

## Zastosowania

Obliczanie liczby spójnych składowych w grafie jest podstawowym zagadnieniem w teorii grafów. Jest niezbędne w wielu aplikacjach, takich jak analiza sieci społecznościowych, identyfikacja klastrów w danych lub wykrywanie składowych niezależnych w sieci komputerowej.

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/graphs/connected-components.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/graphs/connected-components.md){ .md-button }
