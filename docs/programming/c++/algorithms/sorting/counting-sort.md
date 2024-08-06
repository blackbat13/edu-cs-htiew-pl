# Sortowanie przez zliczanie

## [:link: Opis problemu](../../../../algorithms/sorting/counting-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void countingSort(int array[], int n, int m) {
    int occurrences[m + 1] = {};
    int k = 0;

    for (int i = 0; i < n; i++) {
        occurrences[array[i]]++;
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < occurrences[i]; j++) {
            array[k] = i;
            k++;
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
    int m = 20;
    
    countingSort(array, n, m);

    printArray(array, n);

    return 0;
}
```
