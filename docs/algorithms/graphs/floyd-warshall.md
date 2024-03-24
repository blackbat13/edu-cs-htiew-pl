---
description: Najkrótsze ścieżki pomiędzy wszystkimi wierzchołkami
---

# Floyd-Warshall

Algorytm Floyda-Warshalla to algorytm wykorzystywany do znalezienia najkrótszych ścieżek między **wszystkimi** parami wierzchołków w grafie skierowanym ważonym. Algorytm ten jest zdolny do obsługi grafów z ujemnymi krawędziami, ale nie z ujemnymi cyklami.

## Opis algorytmu

Floyd-Warshall korzysta z zasady optymalności Bellmana, która mówi, że najkrótsza ścieżka między dwoma wierzchołkami jest albo bezpośrednią ścieżką między nimi, albo zawiera pewne inne wierzchołki. Dlatego algorytm Floyda-Warshalla działa poprzez porównywanie wszystkich możliwych ścieżek między wszystkimi parami wierzchołków i aktualizowanie najkrótszych ścieżek, gdy znajdzie krótszą alternatywę.

## Pseudokod

```
funkcja FloydWarshall(G, V):   (G - graf, V - liczba wierzchołków w grafie, numerowanych od jedynki)
    1. Utwórz dwuwymiarową tablicę dist[1..V][1..V]
    2. Wypełnij tablicę dist wartością inf reprezentującą nieskończoność
    3. Dla i := 1 do V, wykonuj:
        4. dist[i][i] := 0
    5. Dla każdej krawędzi (u, v) w grafie, wykonuj:
        6. dist[u][v] := waga krawędzi (u, v)
    7. Dla k := 1 do V, wykonuj:
        8. Dla i := 1 do V, wykonuj:
            9. Dla j := 1 do V, wykonuj:
                10. Jeżeli dist[i][j] > dist[i][k] + dist[k][j], to:
                    11. dist[i][j] := dist[i][k] + dist[k][j]
```

## Złożoność obliczeniowa

Algorytm Floyda-Warshalla ma złożoność czasową $$O(V^3)$$, gdzie $$V$$ to liczba wierzchołków w grafie. Jest to wynik trzykrotnego zagnieżdżania pętli, gdzie każda pętla przechodzi przez wszystkie wierzchołki.

## Zastosowania

Algorytm Floyda-Warshalla jest używany w sieciach komputerowych do routingu, jak również w operacjach badawczych do problemu najkrótszej ścieżki. W praktyce jest często stosowany tam, gdzie mamy do czynienia z niewielką liczbą wierzchołków, lub gdy potrzebujemy najkrótszych ścieżek między wszystkimi parami wierzchołków, a nie tylko między pojedynczą parą wierzchołków.

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/graphs/floyd-warshall.md" %}
[floyd-warshall.md](../../programming/c++/algorithms/graphs/floyd-warshall.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/graphs/floyd-warshall.md" %}
[floyd-warshall.md](../../programming/python/algorithms/graphs/floyd-warshall.md)
{% endcontent-ref %}
