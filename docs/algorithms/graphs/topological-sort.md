# Sortowanie topologiczne

Sortowanie topologiczne to procedura, która dla danego skierowanego grafu acyklicznego (DAG), zwraca liniowy porządek wierzchołków taki, że dla każdej krawędzi skierowanej od wierzchołka $$u$$ do $$v$$, $$u$$ jest przed $$v$$ w porządku.

Mówiąc prościej, sortowanie topologiczne danego grafu acyklicznego to liniowe uporządkowanie wierzchołków takie, że jeżeli istnieje krawędź od wierzchołka $$u$$ do $$v$$, to $$u$$ pojawia się przed $$v$$ w porządkowaniu.

## Opis działania algorytmu

Jednym z podstawowych algorytmów sortowania topologicznego jest algorytm oparty na przeszukiwaniu w głąb (DFS). Lista kroków tego algorytmu może wyglądać następująco:

1. Tworzymy stos, który będzie przechowywał posortowane topologicznie wierzchołki.
2. Dla każdego wierzchołka, który nie został jeszcze odwiedzony, wykonujemy operację DFS.
3. Podczas operacji DFS, po odwiedzeniu wszystkich sąsiadów danego wierzchołka, umieszczamy ten wierzchołek na stosie.
4. Po zakończeniu operacji DFS dla wszystkich wierzchołków, stos zawiera wierzchołki posortowane topologicznie. Wierzchołki są poprawnie posortowane, gdy usuwamy je ze stosu od góry.

## Złożoność

Złożoność czasowa tego algorytmu to $$O(V+E)$$, gdzie $$V$$ to liczba wierzchołków, a $$E$$ to liczba krawędzi w grafie, co wynika bezpośrednio z złożoności przeszukiwania w głąb.

## Zastosowanie

Sortowanie topologiczne ma wiele zastosowań, szczególnie w dziedzinach, które wymagają określonego porządku zadań. Jest używane do określania sekwencji zadań, planowania projektów, budowy planów zajęć, rozwiązywania problemów zależności między zadaniami i wiele innych.

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/graphs/topological-sort.md" %}
[topological-sort.md](../../programming/c++/algorithms/graphs/topological-sort.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/graphs/topological-sort.md" %}
[topological-sort.md](../../programming/python/algorithms/graphs/topological-sort.md)
{% endcontent-ref %}
