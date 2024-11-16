# Lista jednokierunkowa

Lista jednokierunkowa, nazywana również listą łańcuchową, to podstawowa struktura danych, która składa się z serii "węzłów" zawierających informacje i wskaźnik do następnego węzła w sekwencji. Pozwala to na efektywne przeprowadzanie pewnych operacji, takich jak dodawanie i usuwanie elementów z początku sekwencji, za które odpowiada "głowa" listy.

## Struktura

Węzeł w liście jednokierunkowej składa się z dwóch elementów: "danych" i wskaźnika do "następnego" węzła. Dane to informacje, które chcemy przechować - mogą to być liczby, napisy, obiekty itp. "Następny" to wskaźnik na następny węzeł w liście. Ostatni węzeł na liście ma wskaźnik "następny" ustawiony na wartość null, co oznacza koniec listy.

## Operacje

Najważniejsze operacje, które można wykonać na liście jednokierunkowej, to:

- **Dodawanie elementu na początek listy**: wymaga to stworzenia nowego węzła, ustawienia jego "danych" na dodawany element, jego "następnego" na obecną "głowę" listy, a następnie ustawienia "głowy" listy na nowy węzeł. Ta operacja jest zazwyczaj szybka i ma złożoność czasową $O(1)$.
- **Usuwanie elementu z początku listy**: polega to na ustawieniu "głowy" listy na jej obecny "następny" węzeł. Ta operacja jest również szybka i ma złożoność czasową $O(1)$.
- **Przeszukiwanie listy**: wymaga to przejścia przez listę od "głowy" do końca, sprawdzając "dane" w każdym węźle. Ta operacja jest wolniejsza i ma złożoność czasową $O(n)$, gdzie $n$ to liczba węzłów w liście.

## Zastosowania

Listy jednokierunkowe są wykorzystywane w wielu algorytmach i strukturach danych, takich jak stosy, kolejki, hashowanie łańcuchowe itp. Są one szczególnie przydatne w sytuacjach, gdzie elementy są dodawane i usuwane tylko z jednego końca sekwencji, jak na przykład w implementacji stosu.

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/structures/singly-linked-list.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/structures/singly-linked-list.md){ .md-button }
