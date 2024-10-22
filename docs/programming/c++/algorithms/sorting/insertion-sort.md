# Sortowanie przez wstawianie

## [:link: Opis problemu](../../../../algorithms/sorting/insertion-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && array[j] < array[j - 1]) {
            swap(array[j], array[j - 1]);
            j--;
        }
    }
}

void printArray(int array[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
 
    cout << endl;
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    int n = 10;
    
    insertionSort(array, n);

    printArray(array, n);

    return 0;
}
```
