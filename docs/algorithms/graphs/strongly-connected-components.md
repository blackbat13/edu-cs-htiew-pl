# Silnie spójne składowe

Silnie spójna składowa grafu skierowanego to taka część grafu, gdzie z każdego wierzchołka do każdego innego można dojść po ścieżce skierowanej, która jest wewnątrz tej składowej. Mówiąc prościej, w silnie spójnej składowej możemy dojść z dowolnego wierzchołka do dowolnego innego, idąc tylko w kierunku strzałek (krawędzi).

## Algorytm Kosaraju

Algorytm Kosaraju jest popularnym algorytmem do znajdowania silnie spójnych składowych w grafie skierowanym. Składa się on z trzech kroków:

1. Wykonujemy przeszukiwanie w głąb na oryginalnym grafie. Zapisujemy kolejność odwiedzania wierzchołków.
2. Odwracamy kierunek wszystkich krawędzi w grafie.
3. Wykonujemy przeszukiwanie w głąb na odwróconym grafie, ale zaczynamy od wierzchołka, który był odwiedzany jako ostatni w pierwszym przeszukiwaniu. Wszystkie wierzchołki odwiedzone podczas tego przeszukiwania tworzą jedną silnie spójną składową. Następnie wybieramy kolejny jeszcze nieodwiedzony wierzchołek, który był odwiedzany jako ostatni w pierwszym przeszukiwaniu, i powtarzamy przeszukiwanie, co daje nam kolejną silnie spójną składową. Proces kontynuujemy, aż odwiedzimy wszystkie wierzchołki.

## Złożoność

Złożoność obliczeniowa algorytmu Kosaraju wynosi $O(V + E)$, gdzie $V$ to liczba wierzchołków, a $E$ to liczba krawędzi w grafie. Jest to wynik tego, że algorytm wykonuje dwa przeszukiwania w głąb.

## Zastosowania

Silnie spójne składowe są używane w wielu różnych dziedzinach informatyki, w tym w analizie sieci społecznościowych, planowaniu tras, analizie stron internetowych i wiele innych.

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/graphs/connected-components.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/graphs/connected-components.md){ .md-button }
