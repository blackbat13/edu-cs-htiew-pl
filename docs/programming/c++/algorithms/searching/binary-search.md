# Wyszukiwanie binarne

## Opis problemu

{% content-ref url="../../../../algorithms/searching/binary-search.md" %}
[binary-search.md](../../../../algorithms/searching/binary-search.md)
{% endcontent-ref %}

## Wersja iteracyjna

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

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
        cout << "Number not found in array" << endl;
    } else {
        cout << "Index of given number is " << index << endl;
    }

    return 0;
}
```
{% endcode %}

### Opis implementacji

Funkcja `binarySearchIterative` przyjmuje jako argumenty tablicę liczb, jej długość i liczbę do znalezienia. Początkowo ustawia wskaźniki na skrajne elementy tablicy - `left` na początek, `right` na koniec.

Następnie, w pętli `while`, oblicza środek tablicy (`middle`). Jeżeli szukana liczba jest mniejsza lub równa elementowi środkowemu, `right` zostaje przesunięty na pozycję środka. W przeciwnym razie, `left` przesuwa się na pozycję po środkowym elemencie.

Pętla `while` kontynuuje działanie, dopóki `left` jest mniejszy od `right`, dzieląc tablicę na pół z każdą iteracją. To jest kluczowy aspekt wyszukiwania binarnego - za każdym razem odrzucamy połowę tablicy, co sprawia, że algorytm jest bardzo efektywny (ma złożoność $$O(log n)$$).

Gdy pętla `while` kończy działanie, sprawdzamy, czy element na pozycji `left` jest równy szukanej liczbie. Jeśli tak, zwracamy jego indeks. Jeśli nie, zwracamy $$-1$$, co oznacza, że szukana liczba nie znajduje się w tablicy.

Funkcja `main` tworzy tablicę $$10$$ elementów od $$1$$ do $$10$$, następnie wywołuje funkcję `binarySearchIterative` szukając liczby $$8$$. Jeżeli wynikiem funkcji jest $$-1$$, wypisywana jest na ekran informacja, że liczba nie została znaleziona. W przeciwnym razie wypisywany jest indeks znalezionej liczby w tablicy.

## Wersja rekurencyjna

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

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
        cout << "Number not found in array" << endl;
    } else {
        cout << "Index of given number is " << index << endl;
    }

    return 0;
}
```
{% endcode %}

### Opis implementacji

Funkcja `binarySearchRecursive` przyjmuje cztery argumenty: tablicę `array[]`, liczbę `number`, którą chcemy znaleźć, oraz lewy `left` i prawy `right` indeks określający zakres wyszukiwania. Oto, jak działa ta funkcja:

1. Jeżeli lewy indeks jest mniejszy od prawego, wyznacza indeks środkowy `middle` jako średnią indeksów lewego i prawego.
2. Jeżeli szukana liczba `number` jest mniejsza lub równa liczbie w środku tablicy, to wywołuje funkcję `binarySearchRecursive` z zakresem od lewego indeksu do środkowego. W przeciwnym przypadku wywołuje funkcję `binarySearchRecursive` z zakresem od środkowego indeksu plus jeden do prawego indeksu.
3. Jeżeli lewy indeks jest równy prawemu i liczba w tym indeksie jest równa szukanej liczbie, zwraca ten indeks.
4. Jeżeli liczba nie została znaleziona, zwraca $$-1$$.

W głównej funkcji `main`:

1. Definiuje tablicę `array[]` oraz szukaną liczbę `number`.
2. Wywołuje funkcję `binarySearchRecursive` z tablicą, szukaną liczbą oraz indeksami początkowym i końcowym.

Jeżeli zwrócony indeks jest równy $$-1$$, wyświetla informację, że liczba nie została znaleziona. W przeciwnym przypadku wyświetla indeks, pod którym znajduje się szukana liczba.
