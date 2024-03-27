# Sortowanie grzebieniowe

## [Opis problemu](../../../../algorithms/sorting/comb-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void combSort(int array[], int n) {
    int i, gap = n;
    double shrink = 1.3;
    bool sorted = false;
    while (!sorted) {
        gap = gap / shrink;
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        i = 0;

        while(i + gap < n) {
            if (array[i] > array[i + gap]) {
                swap(array[i], array[i + gap]);
                sorted = false;
            }

            i++;
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
    
    combSort(array, n);

    printArray(array, n);

    return 0;
}
```
