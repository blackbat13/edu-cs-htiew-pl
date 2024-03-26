# Drzewo przedziałowe

Drzewo przedziałowe to struktura danych, która pozwala na efektywne przeprowadzanie pewnych operacji na tablicach. Szczególnie przydaje się, gdy mamy do czynienia z tablicą, która nie zmienia się często (jest "statyczna"), ale potrzebujemy często wykonywać operacje na pewnych segmentach (stąd nazwa) tej tablicy.

## Struktura

Drzewo segmentowe jest drzewem binarnym. Każdy węzeł w drzewie reprezentuje segment tablicy - dla węzła korzenia jest to cała tablica, a dla innych węzłów są to różne podsegmenty. Liście drzewa reprezentują pojedyncze elementy tablicy. Każdy węzeł wewnętrzny drzewa reprezentuje segment tablicy, który jest unią segmentów reprezentowanych przez jego dzieci.

## Operacje

Najważniejsze operacje, które można wykonać na drzewie segmentowym, to:

- **Budowanie drzewa z tablicy**: ta operacja wymaga przejścia przez całą tablicę i budowy odpowiednich węzłów drzewa, więc jej złożoność czasowa to $O(n)$, gdzie $n$ to liczba elementów w tablicy.
- **Aktualizowanie wartości w tablicy**: w drzewie segmentowym można to zrobić, przechodząc od węzła reprezentującego zmieniany element do korzenia i aktualizując informacje w węzłach po drodze. Ta operacja ma złożoność $O(\log n)$.
- W**ykonywanie operacji na segmencie tablicy**: taka operacja może polegać na znalezieniu minimalnego elementu, sumie elementów itd. W drzewie segmentowym można to zrobić, przetwarzając tylko $O(\log n)$ węzłów.

## Zastosowania

Drzewa segmentowe są wykorzystywane w wielu dziedzinach programowania, takich jak grafika komputerowa, statystyka, systemy baz danych i wiele innych. W programowaniu konkursowym często są używane do rozwiązywania zadań, które wymagają szybkiego wykonywania operacji na segmentach tablic.

## Implementacja

### C++


[segment-tree.md](../../programming/c++/algorithms/structures/segment-tree.md)


### Python


[segment-trees.md](../../programming/python/algorithms/structures/segment-trees.md)

