# Sortowanie koktajlowe

## [Opis problemu](../../../../algorithms/sorting/cocktail-shaker-sort.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void cocktailShakerSort(int array[], int n) {
    for (int i = 0; i <= n / 2; i++) {
        for (int j = i; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }

        for (int j = n - 1 - i; j > i; j--) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
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
    
    cocktailShakerSort(array, n);
    
    printArray(array, n);

    return 0;
}
```

