# BFS

BFS (*Breadth First Search*) to algorytm przeszukiwania grafu, który przeszukuje wierzchołki w kolejności ich odległości od źródła, odwiedzając najpierw wierzchołki bezpośrednio sąsiadujące ze źródłem, następnie wierzchołki, które są dwa kroki od źródła, i tak dalej.

## Opis działania algorytmu

BFS zaczyna od wybranego wierzchołka (zwanego wierzchołkiem źródłowym/początkowym) i odwiedza wszystkie wierzchołki na tym samym poziomie (czyli w tej samej odległości od wierzchołka źródłowego) przed przejściem do następnego poziomu. W praktyce oznacza to, że algorytm BFS "rozszerza" się na wszystkie kierunki jednocześnie, co jest użyteczne w takich zastosowaniach jak znajdowanie najkrótszej ścieżki w grafie nieważonym.

## Pseudokod

```
funkcja BFS(G, s):   (G - graf, s - wierzchołek startowy)
    1. Utwórz kolejkę Q
    2. Umieść s w kolejce Q
    3. Oznacz s jako odwiedzone
    4. Dopóki kolejka Q nie jest pusta, wykonuj:
        5. Usuń pierwszy element z kolejki Q i zapisz w zmiennej v
        6. Dla każdego wierzchołka u sąsiadującego z v, wykonuj:
            7. Jeżeli u nie jest odwiedzony, to:
                8. Oznacz u jako odwiedzony
                9. Umieść u w kolejce Q
```

## Zastosowania

BFS ma wiele zastosowań w praktyce, między innymi:

- Wyszukiwanie elementu w grafie.
- Wyszukiwanie najkrótszej ścieżki w grafie nieważonym.
- Sprawdzanie, czy graf jest spójny.
- Wyszukiwanie cykli w grafie.
- Rozwiązywanie problemów takich jak problem labiryntu, problem ścieżki Hamiltona itp.

## Złożoność obliczeniowa

Złożoność czasowa algorytmu BFS wynosi $O(V + E)$, gdzie $V$ to liczba wierzchołków, a $E$ to liczba krawędzi, ponieważ każdy wierzchołek i każda krawędź są przeszukiwane dokładnie raz.

## Implementacja

Algorytm BFS jest zwykle implementowany za pomocą struktury danych zwaną **kolejką**, która zachowuje wierzchołki do odwiedzenia. Początkowo, wierzchołek startowy jest dodawany do kolejki. Następnie, dopóki kolejka nie jest pusta, wierzchołek jest usuwany z kolejki, a wszystkie jego niewizytowane sąsiednie wierzchołki są dodawane do kolejki. Operacje są powtarzane, aż kolejka zostanie opróżniona.

Poniżej znajdziesz przykładowe implementacje w wybranych językach.

### [:simple-cplusplus: C++](../../programming/c++/algorithms/graphs/bfs.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/graphs/bfs.md){ .md-button }
