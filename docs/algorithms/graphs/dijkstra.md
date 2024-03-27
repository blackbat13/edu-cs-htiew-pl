---
description: Najkrótsze ścieżki z jednego wierzchołka
---

# Dijkstra

Algorytm Dijkstry jest jednym z najpopularniejszych algorytmów służących do szukania najkrótszej ścieżki w grafie. Został on opracowany przez holenderskiego informatyka Edsgera Dijkstrę w 1956 roku. Algorytm ten jest szczególnie przydatny w sieciach komunikacyjnych, gdzie służy do znajdowania najkrótszej ścieżki od źródłowego węzła do wszystkich innych węzłów w sieci.

Algorytm Dijkstry może być używany tylko w grafach ważonych (w grafach nieważonych możemy przyjąć wagę $1$ dla każdej krawędzi), gdzie wagi reprezentują długość lub koszt przejścia między wierzchołkami. Ważne jest, że wagi nie mogą być ujemne, ponieważ w takim przypadku algorytm Dijkstry może nie działać poprawnie.

## Opis algorytmu

1. Inicjalizacja: Na początku ustawiamy wartość odległości do wierzchołka startowego na $0$, a dla wszystkich pozostałych wierzchołków na nieskończoność (lub bardzo dużą liczbę).
2. Tworzymy zbiór nienaruszonych wierzchołków, na początku zawierający wszystkie wierzchołki grafu.
3. Wybieramy wierzchołek z najmniejszą odległością spośród nienaruszonych wierzchołków, a następnie usuwamy go ze zbioru.
4. Aktualizujemy odległości do wszystkich sąsiadów wybranego wierzchołka. Jeżeli aktualna odległość do sąsiada jest większa niż odległość do wybranego wierzchołka plus waga krawędzi między nimi, to aktualizujemy odległość do sąsiada.
5. Powtarzamy kroki $3$ i $4$, dopóki zbiór nienaruszonych wierzchołków nie jest pusty.

Na koniec algorytmu, dla każdego wierzchołka mamy najkrótszą możliwą odległość od wierzchołka startowego.

## Złożoność obliczeniowa

Złożoność obliczeniowa algorytmu Dijkstry zależy od implementacji. Jeśli algorytm jest zaimplementowany z użyciem prostej kolejki, jego złożoność obliczeniowa wynosi $O(V^2)$, gdzie $V$ to liczba wierzchołków w grafie. Jeżeli używamy kopca binarnego do przechowywania nienaruszonych wierzchołków, złożoność obliczeniowa wynosi $O((V+E) \log{V})$, gdzie $E$ to liczba krawędzi w grafie.

## Podsumowanie

Algorytm Dijkstry jest podstawowym narzędziem do rozwiązywania problemów związanych z najkrótszą ścieżką w grafach ważonych bez ujemnych wag. Pomimo swojego wieku, nadal jest powszechnie stosowany w wielu dziedzinach, od sieci komputerowych po systemy nawigacji GPS.

## Implementacja

### [C++](../../programming/c++/algorithms/graphs/dijkstra.md)

### [Python](../../programming/python/algorithms/graphs/dijkstra.md)
