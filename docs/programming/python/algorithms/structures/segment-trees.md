# Drzewa przedziałowe

## [Opis problemu](../../../../algorithms/structures/segment-trees.md)

## Implementacja

```python linenums="1"
class SumSegmentTree:
    class Node:
        def __init__(self, index_from, index_to):
            self.index_from = index_from
            self.index_to = index_to
            self.value = 0
            self.lazy = 0
            self.left = None
            self.right = None

        def print(self, tabulation=""):
            print(f"{tabulation}[{self.index_from}, {self.index_to}]: (val: {self.value}, lazy: {self.lazy})")
            if self.index_from != self.index_to:
                self.left.print(tabulation + "\t")
                self.right.print(tabulation + "\t")

        def apply_lazy(self):
            if self.index_from == self.index_to:
                self.value += self.lazy
                self.lazy = 0
                return
            
            self.value += self.lazy * (self.index_to - self.index_from + 1)
            self.left.lazy += self.lazy
            self.right.lazy += self.lazy
            self.lazy = 0

        def change(self, index_from, index_to, value):
            if self.index_from == index_from and self.index_to == index_to:
                self.lazy += value
                return
            
            middle = (self.index_from + self.index_to) // 2
            self.apply_lazy()
            self.value += value * (index_to - index_from + 1)

            if index_from <= middle:
                if index_to <= middle:
                    self.left.change(index_from, index_to, value)
                else:
                    self.left.change(index_from, middle, value)
                    self.right.change(middle + 1, index_to, value)
            else:
                self.right.change(index_from, index_to, value)

        def get_value(self, index_from, index_to):
            if self.index_from == index_from and self.index_to == index_to:
                return self.value + self.lazy * (self.index_to - self.index_from + 1)
            
            middle = (self.index_from + self.index_to) // 2
            self.apply_lazy()

            if index_from <= middle:
                if index_to <= middle:
                    return self.left.get_value(index_from, index_to)
                else:
                    return self.left.get_value(index_from, middle) + self.right.get_value(middle + 1, index_to)
            else:
                return self.right.get_value(index_from, index_to)
            
    def __init__(self, tab):
        self.root = self.build(0, len(tab) - 1, tab)

    def build(self, index_from, index_to, tab):
        current = self.Node(index_from, index_to)
        if index_from == index_to:
            current.value = tab[index_from]
            return current
        
        middle = (index_from + index_to) // 2
        current.left = self.build(index_from, middle, tab)
        current.right = self.build(middle + 1, index_to, tab)
        current.value = current.left.value + current.right.value
        return current
    
    def change(self, index_from, index_to, value):
        self.root.change(index_from, index_to, value)

    def get_value(self, index_from, index_to):
        return self.root.get_value(index_from, index_to)
    
    def print(self):
        self.root.print()

if __name__ == "__main__":
    tab = [1] * 10
    
    sum_segment_tree = SumSegmentTree(tab)
    sum_segment_tree.print()

    print(f"\n\n[3, 5] = {sum_segment_tree.get_value(3, 5)}")

    sum_segment_tree.change(3, 5, 2)

    print("\n\n[3, 5] + 2")

    sum_segment_tree.print()

    print(f"\n\n[3, 5] = {sum_segment_tree.get_value(3, 5)}")
```

### Opis implementacji

Klasa **SumSegmentTree** definiuje drzewo przedziałowe do liczenia sum na przedziałach. Klasa **Node** opisuje strukturę wewnętrznego węzła drzewa segmentowego.
Węzeł przechowuje informacje o wartości, przedziale, leniwej aktualizacji (lazy update) oraz wskaźniki na lewe i prawe poddrzewo.
Węzeł posiada metody do drukowania informacji o sobie, leniwej aktualizacji, zmiany wartości na danym przedziale oraz pobrania sumy wartości na danym przedziale.

Klasa **SumSegmentTree** posiada pole root, które jest korzeniem drzewa segmentowego.
Metoda **build** rekurencyjnie tworzy drzewo segmentowe na podstawie tablicy **tab**.
Konstruktor klasy **SumSegmentTree** tworzy drzewo segmentowe na podstawie podanej długości i tablicy.
Metoda **print** wywołuje metodę **print** na korzeniu drzewa segmentowego, co powoduje wypisanie informacji o strukturze drzewa.
Metoda **change** wykonuje operację zmiany wartości na danym przedziale, korzystając z leniwych aktualizacji, natomiast metoda **get_value** zwraca sumę wartości na danym przedziale.

W części globalnej tworzona jest instancja klasy **SumSegmentTree** na podstawie przykładowej tablicy.
Następnie wywoływana jest metoda **print** dla wyświetlenia struktury drzewa przed wykonaniem operacji.
Wywoływana jest operacja **get_value** na przedziale $[3, 5]$ i wynik zostaje wyświetlony.
Następnie wywoływana jest operacja **change** na przedziale $[3, 5]$ z wartością $2$ po czym wyświetlena jest zaktualizowana struktura drzewa.
Na końcu obliczana jest aktualna suma na przedziale $[3, 5]$.

Wynik działania programu:

```
[0, 9]: (val: 10, lazy: 0)
    [0, 4]: (val: 5, lazy: 0)
        [0, 2]: (val: 3, lazy: 0)
            [0, 1]: (val: 2, lazy: 0)
                [0, 0]: (val: 1, lazy: 0)
                [1, 1]: (val: 1, lazy: 0)
            [2, 2]: (val: 1, lazy: 0)
        [3, 4]: (val: 2, lazy: 0)
            [3, 3]: (val: 1, lazy: 0)
            [4, 4]: (val: 1, lazy: 0)
    [5, 9]: (val: 5, lazy: 0)
        [5, 7]: (val: 3, lazy: 0)
            [5, 6]: (val: 2, lazy: 0)
                [5, 5]: (val: 1, lazy: 0)
                [6, 6]: (val: 1, lazy: 0)
            [7, 7]: (val: 1, lazy: 0)
        [8, 9]: (val: 2, lazy: 0)
            [8, 8]: (val: 1, lazy: 0)
            [9, 9]: (val: 1, lazy: 0)

[3, 5] = 3

[3, 5] + 2
[0, 9]: (val: 16, lazy: 0)
    [0, 4]: (val: 9, lazy: 0)
        [0, 2]: (val: 3, lazy: 0)
            [0, 1]: (val: 2, lazy: 0)
                [0, 0]: (val: 1, lazy: 0)
                [1, 1]: (val: 1, lazy: 0)
            [2, 2]: (val: 1, lazy: 0)
        [3, 4]: (val: 2, lazy: 2)
            [3, 3]: (val: 1, lazy: 0)
            [4, 4]: (val: 1, lazy: 0)
    [5, 9]: (val: 7, lazy: 0)
        [5, 7]: (val: 5, lazy: 0)
            [5, 6]: (val: 4, lazy: 0)
                [5, 5]: (val: 1, lazy: 2)
                [6, 6]: (val: 1, lazy: 0)
            [7, 7]: (val: 1, lazy: 0)
        [8, 9]: (val: 2, lazy: 0)
            [8, 8]: (val: 1, lazy: 0)
            [9, 9]: (val: 1, lazy: 0)

[3, 5] = 9
```