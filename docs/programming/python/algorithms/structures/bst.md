---
description: BST
---

# Drzewo przeszukiwań binarnych

## [Opis problemu](../../../../algorithms/structures/bst.md)

## Implementacja

```python linenums="1"
class BinarySearchTree:
    def __init__(self):
        self._value = None
        self._left = None
        self._right = None

    def insert(self, value):
        if self._value is None:
            self._value = value
            return

        if value < self._value:
            if self._left is None:
                self._left = BinarySearchTree()

            self._left.insert(value)
        else:
            if self._right is None:
                self._right = BinarySearchTree()

            self._right.insert(value)

    def inorder(self):
        if self._left is not None:
            self._left.inorder()
        print(self._value)
        if self._right is not None:
            self._right.inorder()

    def preorder(self):
        print(self._value)
        if self._left is not None:
            self._left.preorder()
        if self._right is not None:
            self._right.preorder()

    def postorder(self):
        if self._left is not None:
            self._left.postorder()
        if self._right is not None:
            self._right.postorder()
        print(self._value)

    def clear(self):
        self._value = None
        if self._left is not None:
            self._left.clear()
            self._left = None
        if self._right is not None:
            self._right.clear()
            self._right = None

if __name__ == "__main__":
    values = [20, 10, 30, 5, 15, 25, 35]
    bst = BinarySearchTree()

    for val in values:
        bst.insert(val)

    print("Inorder:")
    bst.inorder()

    print("Preorder:")
    bst.preorder()

    print("Postorder:")
    bst.postorder()

    bst.clear()
```

### Opis implementacji

![Przykładowe drzewo wykorzystane w implementacji](<../../../../assets/image (10).png>)

[http://graphonline.ru/en/?graph=iTYRccYJVswEnVGe](http://graphonline.ru/en/?graph=iTYRccYJVswEnVGe)