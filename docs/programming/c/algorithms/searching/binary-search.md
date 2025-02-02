# Wyszukiwanie binarne

## [:link: Opis problemu](../../../../algorithms/searching/binary-search.md)

## Wersja iteracyjna

### Implementacja

```c linenums="1"
#include <stdio.h>

int binarySearchIterative(int array[], int length, int number) {
    int left = 0;
    int right = length - 1;
    int middle;

    while (left < right) {
        middle = (left + right) / 2;
        if (number <= array[middle]) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    if (array[left] == number) {
        return left;
    }

    return -1;
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number = 8;
    
    int index = binarySearchIterative(array, 10, number);
    
    if (index == -1) {
      printf("Number not found in array\n");
    } else {
      printf("Index of given number is %d\n", index);
    }

    return 0;
}
```

### Opis implementacji

Funkcja `binarySearchIterative` przyjmuje jako argumenty tablicę liczb, jej długość i liczbę do znalezienia. Początkowo ustawia wskaźniki na skrajne elementy tablicy - `left` na początek, `right` na koniec.

Następnie, w pętli `while`, oblicza środek tablicy (`middle`). Jeżeli szukana liczba jest mniejsza lub równa elementowi środkowemu, `right` zostaje przesunięty na pozycję środka. W przeciwnym razie, `left` przesuwa się na pozycję po środkowym elemencie.

Pętla `while` kontynuuje działanie, dopóki `left` jest mniejszy od `right`, dzieląc tablicę na pół z każdą iteracją. To jest kluczowy aspekt wyszukiwania binarnego - za każdym razem odrzucamy połowę tablicy, co sprawia, że algorytm jest bardzo efektywny (ma złożoność $O(log n)$).

Gdy pętla `while` kończy działanie, sprawdzamy, czy element na pozycji `left` jest równy szukanej liczbie. Jeśli tak, zwracamy jego indeks. Jeśli nie, zwracamy $-1$, co oznacza, że szukana liczba nie znajduje się w tablicy.

Funkcja `main` tworzy tablicę $10$ elementów od $1$ do $10$, następnie wywołuje funkcję `binarySearchIterative` szukając liczby $8$. Jeżeli wynikiem funkcji jest $-1$, wypisywana jest na ekran informacja, że liczba nie została znaleziona. W przeciwnym razie wypisywany jest indeks znalezionej liczby w tablicy.

## Wersja rekurencyjna

### Implementacja

```c linenums="1"
#include <stdio.h>

int binarySearchRecursive(int array[], int number, int left, int right) {
  int middle;

  if (left < right) {
    middle = (left + right) / 2;
    if (number <= array[middle]) {
      return binarySearchRecursive(array, number, left, middle);
    } else {
      return binarySearchRecursive(array, number, middle + 1, right);
    }
  } else if (array[left] == number) {
    return left;
  }

  return -1;
}

int main() {
  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int number = 8;

  int index = binarySearchRecursive(array, number, 0, 10);

  if (index == -1) {
    printf("Number not found in array\n");
  } else {
    printf("Index of given number is %d\n", index);
  }

  return 0;
}
```
