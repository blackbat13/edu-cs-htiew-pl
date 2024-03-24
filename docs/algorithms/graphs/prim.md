# Prim

Algorytm Prima jest jednym z algorytmów wyznaczających minimalne drzewo rozpinające dla danego grafu nieskierowanego i ważonego. Algorytm został nazwany na cześć Roberta C. Prima, który opisał go w 1957 roku.

## Opis algorytmu

1. Wybierz dowolny wierzchołek w grafie jako punkt startowy.
2. Ze wszystkich krawędzi, które łączą wierzchołki już uwzględnione w drzewie rozpinającym z wierzchołkami spoza tego drzewa, wybierz tę o najmniejszej wadze.
3. Dodaj wybraną krawędź oraz wierzchołek, do którego prowadzi, do drzewa rozpinającego.
4. Powtarzaj kroki 2-3, aż wszystkie wierzchołki grafu zostaną uwzględnione w drzewie rozpinającym.

## Złożoność

Złożoność czasowa algorytmu Prima zależy od implementacji. Przy użyciu kolejki priorytetowej zaimplementowanej jako kopiec binarny, algorytm działa w czasie $$O(E log V)$$, gdzie $$E$$ to liczba krawędzi, a $$V$$ to liczba wierzchołków w grafie. Możliwe są jednak efektywniejsze implementacje.

## Zastosowania

Algorytm Prima jest używany w wielu praktycznych zastosowaniach, na przykład do projektowania sieci komputerowych i telekomunikacyjnych, gdzie celem jest połączenie wielu punktów najmniejszą możliwą ilością kabla.

Ponadto, jest stosowany w algorytmach kompresji danych, takich jak algorytm kodowania Huffmana, który tworzy minimalne drzewo rozpinające w celu reprezentowania danych w najbardziej efektywny sposób.

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/graphs/prim.md" %}
[prim.md](../../programming/c++/algorithms/graphs/prim.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/graphs/prim.md" %}
[prim.md](../../programming/python/algorithms/graphs/prim.md)
{% endcontent-ref %}
