# DFS

DFS (*Depth First Search*) to jeden z podstawowych algorytmów przeszukiwania grafu. Jak sama nazwa wskazuje, algorytm ten skupia się na przechodzeniu w głąb, co sprowadza się do zbadania jak największej liczby krawędzi wzdłuż każdej możliwej ścieżki przed powrotem i eksploracją innych ścieżek.

DFS jest często wykorzystywany do rozwiązywania różnego rodzaju problemów, takich jak sprawdzanie czy graf jest **spójny**, szukanie **cykli** czy rozwiązanie problemu **ścieżki Hamiltona**.

## Opis działania algorytmu

DFS zaczyna od wybranego wierzchołka (zwanego wierzchołkiem źródłowym/początkowym) i wykonuje przeszukiwanie możliwie najdalej wzdłuż każdej gałęzi grafu, zanim wróci do poprzedniego wierzchołka i spróbuje przeszukać kolejną ścieżkę. Głównym celem algorytmu jest odwiedzenie każdego wierzchołka grafu dokładnie raz.

## Pseudokod

```
funkcja DFS(G, s):   (G - graf, v - wierzchołek startowy)
    1. Utwórz stos S
    2. Umieść v na stosie S
    3. Oznacz v jako odwiedzone
    4. Dopóki stos S nie jest pusty, wykonuj:
        1. Usuń pierwszy element ze stosu S i zapisz w zmiennej k
        2. Dla każdego wierzchołka u sąsiadującego z k, wykonuj:
            1. Jeżeli u nie jest odwiedzony, to:
                1. Oznacz u jako odwiedzony
                2. Umieść u na stosie S
```

## Zastosowania

DFS ma wiele zastosowań w praktyce, między innymi:

- Wyszukiwanie elementu w grafie.
- Sprawdzanie, czy graf jest spójny.
- Wyszukiwanie cykli w grafie.
- Rozwiązywanie problemów takich jak problem labiryntu, problem ścieżki Hamiltona itp.
- Tworzenie drzewa rozpinającego dla grafu nieskierowanego.

## Złożoność obliczeniowa

Złożoność czasowa algorytmu DFS wynosi $O(V + E)$, gdzie $V$ to liczba wierzchołków, a $E$ to liczba krawędzi, ponieważ każdy wierzchołek i każda krawędź są przeszukiwane dokładnie raz.

## Implementacja

Algorytm DFS można zaimplementować za pomocą struktury danych **stosu**. Stos jest używany do śledzenia wierzchołków, które są jeszcze do odwiedzenia. Na początku algorytmu wrzucamy na stos wierzchołek startowy. Algorytm kontynuuje przeszukiwanie, zdejmując wierzchołek ze stosu i dodając wszystkie nieodwiedzone jeszcze sąsiadujące wierzchołki na stos. Operacje powtarzamy, aż stos będzie pusty. Zamiast stosu można także skorzystać z rekurencji.

Poniżej znajdziesz przykładowe implementacje w wybranych językach.

### C++


[dfs.md](../../programming/c++/algorithms/graphs/dfs.md)


### Python


[dfs.md](../../programming/python/algorithms/graphs/dfs.md)

