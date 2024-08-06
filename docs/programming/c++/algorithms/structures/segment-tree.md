# Drzewo przedziałowe

## [:link: Opis problemu](../../../../algorithms/structures/segment-trees.md)

## Implementacja

```cpp linenums="1"
#include <cstdio>
#include <iostream>
using namespace std;

class SumSegmentTree {
  struct node {
    int value, from, to, lazy;
    node *left, *right;

    node(int from, int to) {
      this->from = from;
      this->to = to;
      this->value = 0;
      this->lazy = 0;
      this->left = nullptr;
      this->right = nullptr;
    }

    void print(string tabulation = "") {
      printf("%s[%d, %d]: (val: %d, lazy: %d)\n", tabulation.c_str(),
             this->from, this->to, this->value, this->lazy);
      if (this->from != this->to) {
        this->left->print(tabulation + "\t");
        this->right->print(tabulation + "\t");
      }
    }

    void applyLazy() {
      if (this->from == this->to) {
        this->value += this->lazy;
        this->lazy = 0;
        return;
      }

      this->value += this->lazy * (this->to - this->from + 1);
      this->left->lazy += this->lazy;
      this->right->lazy += this->lazy;
      this->lazy = 0;
    }

    void change(int from, int to, int value) {
      if (this->from == from && this->to == to) {
        this->lazy += value;
        return;
      }

      int middle = (this->from + this->to) / 2;

      this->applyLazy();

      this->value += value * (to - from + 1);

      if (from <= middle) {
        if (to <= middle) {
          this->left->change(from, to, value);
        } else {
          this->left->change(from, middle, value);
          this->right->change(middle + 1, to, value);
        }
      } else {
        this->right->change(from, to, value);
      }
    }

    int getValue(int from, int to) {
      if (this->from == from && this->to == to) {
        return this->value + this->lazy * (this->to - this->from + 1);
      }

      int middle = (this->from + this->to) / 2;

      this->applyLazy();

      if (from <= middle) {
        if (to <= middle) {
          return this->left->getValue(from, to);
        } else {
          return this->left->getValue(from, middle) +
                 this->right->getValue(middle + 1, to);
        }
      } else {
        return this->right->getValue(from, to);
      }
    }
  };

  node *root;

  node *build(int from, int to, int tab[]) {
    node *current = new node(from, to);
    if (from == to) {
      current->value = tab[from];
      return current;
    }

    current->left = build(from, (from + to) / 2, tab);
    current->right = build(((from + to) / 2) + 1, to, tab);
    current->value = current->left->value + current->right->value;
    return current;
  }

public:
  SumSegmentTree(int length, int tab[]) {
    this->root = build(0, length - 1, tab);
  }

  void print() { this->root->print(); }

  void change(int from, int to, int value) {
    this->root->change(from, to, value);
  }

  int getValue(int from, int to) { return this->root->getValue(from, to); }
};

int main() {
  int tab[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  SumSegmentTree sumSegmentTree = SumSegmentTree(10, tab);

  sumSegmentTree.print();

  printf("\n\n[3, 5] = %d\n", sumSegmentTree.getValue(3, 5));

  sumSegmentTree.change(3, 5, 2);

  printf("\n\n[3, 5] + 2\n");

  sumSegmentTree.print();

  printf("\n\n[3, 5] = %d\n", sumSegmentTree.getValue(3, 5));

  return 0;
}
```

### Opis implementacji

Klasa **SumSegmentTree** definiuje drzewo przedziałowe do liczenia sum na przedziałach. Struktura **node** opisuje strukturę wewnętrznego węzła drzewa segmentowego.
Węzeł przechowuje informacje o wartości, przedziale, leniwej aktualizacji (lazy update) oraz wskaźniki na lewe i prawe poddrzewo.
Węzeł posiada metody do drukowania informacji o sobie, leniwej aktualizacji, zmiany wartości na danym przedziale oraz pobrania sumy wartości na danym przedziale.

Klasa **SumSegmentTree** posiada pole root, które jest wskaźnikiem na korzeń drzewa segmentowego.
Metoda **build** rekurencyjnie tworzy drzewo segmentowe na podstawie tablicy **tab**.
Konstruktor klasy **SumSegmentTree** tworzy drzewo segmentowe na podstawie podanej długości i tablicy.
Metoda **print** wywołuje metodę **print** na korzeniu drzewa segmentowego, co powoduje wypisanie informacji o strukturze drzewa.
Metoda **change** wykonuje operację zmiany wartości na danym przedziale, korzystając z leniwych aktualizacji, natomiast metoda **getValue** zwraca sumę wartości na danym przedziale.

W funkcji **main** tworzona jest instancja klasy **SumSegmentTree** na podstawie przykładowej tablicy.
Następnie wywoływana jest metoda **print** dla wyświetlenia struktury drzewa przed wykonaniem operacji.
Wywoływana jest operacja **getValue** na przedziale $[3, 5]$ i wynik zostaje wyświetlony.
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