# Kruskal

Algorytm Kruskala jest algorytmem wyznaczania minimalnego drzewa rozpinającego w grafie nieskierowanym ważonym. Jest to jeden z najprostszych algorytmów do rozwiązania tego problemu. Został nazwany na cześć swojego twórcy, Józefa Kruskala, który opublikował go po raz pierwszy w 1956 roku.

## Opis algorytmu

1. Sortujemy wszystkie krawędzie grafu według rosnących wag.
2. Przeglądamy krawędzie w kolejności od najmniejszej do największej. Jeżeli krawędź łączy dwa różne drzewa (na początku każdy wierzchołek jest traktowany jako osobne drzewo), to dodajemy ją do minimalnego drzewa rozpinającego i łączymy dwa drzewa w jedno. W przeciwnym razie pomijamy krawędź.
3. Powtarzamy krok $2$ aż do momentu, gdy wszystkie wierzchołki będą w jednym drzewie, które będzie minimalnym drzewem rozpinającym.

Algorytm Kruskala korzysta z własności, że krawędź o najmniejszej wadze, która łączy dwa różne drzewa, jest zawsze częścią minimalnego drzewa rozpinającego.

## Złożoność

Algorytm Kruskala ma złożoność czasową $O(E log E)$, gdzie $E$ jest liczbą krawędzi w grafie. Jest to wynik potrzeby posortowania krawędzi na początku algorytmu.

## Zastosowania

Podobnie jak algorytm Prima, algorytm Kruskala ma wiele zastosowań, szczególnie tam, gdzie trzeba optymalnie połączyć różne punkty, np. w problemach komunikacyjnych i sieciowych.

## Implementacja

### [C++](../../programming/c++/algorithms/graphs/kruskal.md)

### [Python](../../programming/python/algorithms/graphs/kruskal.md)
