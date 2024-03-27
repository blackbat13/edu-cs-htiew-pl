---
description: BST
---

# Drzewa przeszukiwań binarnych

Drzewo przeszukiwań binarnych (ang *BST*) to podstawowa struktura danych, która umożliwia efektywne przeszukiwanie, dodawanie i usuwanie elementów. BST to drzewo binarne, które spełnia specjalną właściwość: dla każdego węzła, wszystkie wartości w lewym poddrzewie są mniejsze od wartości węzła, a wszystkie wartości w prawym poddrzewie są większe.

## Własności

Każdy węzeł ma najwyżej dwoje "dzieci": lewe i prawe.
Każdy węzeł przechowuje klucz (wartość).
Wszystkie klucze w lewym poddrzewie danego węzła są mniejsze od klucza w tym węźle.
Wszystkie klucze w prawym poddrzewie danego węzła są większe od klucza w tym węźle.

## Operacje

Podstawowe operacje wykonywane na BST to:

- **Wstawianie**: aby wstawić nowy klucz do BST, porównujemy go z kluczem korzenia. Jeżeli klucz jest mniejszy, przechodzimy do lewego poddrzewa. Jeżeli klucz jest większy, przechodzimy do prawego poddrzewa. Powtarzamy ten proces, aż dojdziemy do węzła null, gdzie wstawiamy nowy klucz.
- **Szukanie**: aby znaleźć klucz w BST, porównujemy go z kluczem korzenia. Jeżeli klucz jest mniejszy, przechodzimy do lewego poddrzewa. Jeżeli klucz jest większy, przechodzimy do prawego poddrzewa. Jeżeli klucz jest równy kluczowi węzła, znaleźliśmy szukany klucz. Jeżeli dojdziemy do węzła null, klucz nie jest obecny w drzewie.
- **Usuwanie**: usuwanie klucza z BST jest bardziej złożone i może obejmować kilka różnych przypadków, w zależności od liczby dzieci węzła, który ma zostać usunięty.

Dodatkowo, BST może obsługiwać operacje takie jak:

- **Przechodzenie**: Przechodzenie przez drzewo w różnych porządkach: w porządku (ang. *inorder*), przed porządkiem (ang. *preorder*), po porządku (ang. *postorder*).
- **Znajdowanie min/max**: Znajdowanie wartości minimalnej i maksymalnej w BST jest efektywne. Minimalna wartość jest przechowywana w najbardziej lewym węźle, a maksymalna wartość jest przechowywana w najbardziej prawym węźle.

## Zastosowania

BST są powszechnie używane w informatyce z powodu ich efektywności. Znajdują zastosowanie w wielu dziedzinach, w tym:

- **Systemy baz danych**: BST są używane do indeksowania danych, co umożliwia szybkie wyszukiwanie, dodawanie i usuwanie rekordów.
- **Systemy plików**: niektóre systemy plików używają BST do indeksowania plików.
- **Rysowanie drzew genealogicznych**: BST mogą być używane do reprezentowania hierarchicznych relacji, takich jak drzewa genealogiczne.

BST są podstawą dla wielu zaawansowanych struktur danych, które oferują lepszą wydajność w różnych sytuacjach, takich jak drzewa AVL, drzewa czerwono-czarne, drzewa B i drzewa splay.

## Implementacja

### [C++](../../programming/c++/algorithms/structures/bst.md)

### [Python](../../programming/python/algorithms/structures/bst.md)
