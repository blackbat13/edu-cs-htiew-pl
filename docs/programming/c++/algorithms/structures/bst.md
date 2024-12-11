---
description: BST
---

# Drzewa przeszukiwań binarnych

## [:link: Opis problemu](../../../../algorithms/structures/bst.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

class BST {
    struct node {
        int value;
        node *left;
        node *right;
    };

    node *root;
public:
    BST() {
        root = nullptr;
    }

    node* get_root() {
        return root;
    }

    void insert(int value) {
        node *new_node = new node();
        new_node->value = value;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if(root == nullptr) {
            root = new_node;
            return;
        }

        node *current, *parent;
        current = root;
        while(current != nullptr) {
            parent = current;
            if(value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if(value < parent->value) {
            parent->left = new_node;
        } else {
            parent->right = new_node;
        }
    }

    void inorder(node *current) {
        if(current == nullptr) {
            return;
        }

        inorder(current->left);
        cout << current->value << " ";
        inorder(current->right);
    }

    void preorder(node *current) {
        if(current == nullptr) {
            return;
        }

        cout << current->value << " ";
        preorder(current->left);
        preorder(current->right);
    }

    void postorder(node *current) {
        if(current == nullptr) {
            return;
        }

        postorder(current->left);
        postorder(current->right);
        cout << current->value << " ";
    }

    void clear(node *current) {
        if(current == nullptr) {
            return;
        }

        clear(current->left);
        clear(current->right);
        delete current;
    }

    ~BST() {
        clear(root);
    }
};

int main() {
    int array[7] = {20, 10, 30, 5, 15, 25, 35};
    BST bst = BST();

    for(auto el : array) {
        bst.insert(el);
    }

    cout << "Inorder: ";
    bst.inorder(bst.get_root());
    cout << endl;

    cout << "Preorder: ";
    bst.preorder(bst.get_root());
    cout << endl;

    cout << "Postorder: ";
    bst.postorder(bst.get_root());
    cout << endl;
    
    return 0;
}
```

### Opis implementacji

#### Klasa `BST`

##### Struktura `node`

- Reprezentuje pojedynczy węzeł drzewa.
- Zawiera trzy pola:
  - `int value`: wartość przechowywana w węźle.
  - `node *left`: wskaźnik na lewego potomka.
  - `node *right`: wskaźnik na prawego potomka.

##### Pole `root`

Wskaźnik na korzeń drzewa.

##### Konstruktor `BST()`

Inicjalizuje drzewo, ustawiając `root` na pusty wskaźnik (`nullptr`).

##### Metoda `get_root()`

Zwraca wskaźnik na korzeń drzewa.

##### Metoda `insert(int value)`

- Wstawia nową wartość do drzewa.
- Tworzy nowy węzeł z podaną wartością.
- Jeśli drzewo jest puste, nowy węzeł staje się korzeniem.
- W przeciwnym razie, przeszukuje drzewo, aby znaleźć odpowiednie miejsce dla nowego węzła.

##### Metoda `inorder(node *current)`

Przechodzi przez drzewo w porządku inorder (lewy, korzeń, prawy) i wypisuje wartości węzłów.

##### Metoda `preorder(node *current)`

Przechodzi przez drzewo w porządku preorder (korzeń, lewy, prawy) i wypisuje wartości węzłów.

##### Metoda `postorder(node *current)`

Przechodzi przez drzewo w porządku postorder (lewy, prawy, korzeń) i wypisuje wartości węzłów.

##### Metoda `clear(node *current)`

Rekurencyjnie usuwa wszystkie węzły drzewa, zwalniając pamięć.

##### Destruktor `~BST()`

Wywołuje metodę `clear`, aby usunąć wszystkie węzły i zwolnić pamięć przy niszczeniu obiektu `BST`.

#### Funkcja `main()`

- Tworzy tablicę `array` z wartościami do wstawienia do drzewa.
- Tworzy obiekt `BST`.
- Wstawia wartości z tablicy do drzewa.
- Wypisuje wartości drzewa w trzech różnych porządkach: inorder, preorder i postorder.


#### Przykładowe drzewo wykorzystane w implementacji

![Przykładowe drzewo wykorzystane w implementacji](<../../../../assets/image (10).png>)

[http://graphonline.ru/en/?graph=iTYRccYJVswEnVGe](http://graphonline.ru/en/?graph=iTYRccYJVswEnVGe)
