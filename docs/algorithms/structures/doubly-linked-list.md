# Lista dwukierunkowa

Lista dwukierunkowa to rodzaj listy łańcuchowej, gdzie każdy węzeł oprócz przechowywania danych i wskaźnika na następny węzeł, posiada również wskaźnik na poprzedni węzeł. Daje to możliwość poruszania się w obu kierunkach na liście, co umożliwia dodatkowe operacje, które nie są możliwe w listach jednokierunkowych.

## Struktura

Węzeł w liście dwukierunkowej składa się z trzech elementów: "danych", "następnego" i "poprzedniego". "Dane" to informacje przechowywane w węźle. "Następny" to wskaźnik na następny węzeł w liście, a "poprzedni" to wskaźnik na poprzedni węzeł. Dla pierwszego węzła (głowy) wskaźnik "poprzedni" jest ustawiony na null, podobnie jak wskaźnik "następny" dla ostatniego węzła.

## Operacje

Operacje, które można wykonać na liście dwukierunkowej, to między innymi:

- **Dodawanie elementu na początek listy**: tworzymy nowy węzeł, ustawiamy jego "dane" na dodawany element, "następny" na obecną "głowę" listy i "poprzedni" na null. Następnie ustawiamy "poprzedni" obecnej "głowy" na nowy węzeł i na końcu ustawiamy "głowę" listy na nowy węzeł.
- **Dodawanie elementu na koniec listy**: jest to operacja, która nie jest tak prosta jak w listach jednokierunkowych. Tworzymy nowy węzeł, ustawiamy jego "dane" na dodawany element, "poprzedni" na obecny "ogon" listy i "następny" na null. Następnie ustawiamy "następny" obecnego "ogona" na nowy węzeł i na końcu ustawiamy "ogon" listy na nowy węzeł.
- **Usuwanie elementów**: dzięki posiadaniu wskaźników "poprzedni" i "następny" możliwe jest efektywne usuwanie elementów z dowolnego miejsca na liście.
- **Przeszukiwanie listy**: można przeszukiwać listę w obu kierunkach, co może być przydatne w pewnych sytuacjach.

## Zastosowania

Listy dwukierunkowe są wykorzystywane w wielu zastosowaniach, gdzie potrzebne jest efektywne dodawanie lub usuwanie elementów z obu końców listy, jak na przykład w implementacji struktury danych *deque*. Są one również używane w niektórych algorytmach, takich jak algorytm **LRU** (*Least Recently Used*) do zarządzania pamięcią cache.

## Implementacja

### C++


[doubly-linked-list.md](../../programming/c++/algorithms/structures/doubly-linked-list.md)


### Python


[doubly-linked-list.md](../../programming/python/algorithms/structures/doubly-linked-list.md)

