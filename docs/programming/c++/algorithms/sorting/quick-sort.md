# Sortowanie szybkie

## [Opis problemu](../../../../algorithms/sorting/quick-sort.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void quickSort(int tab[], int left, int right) {
    if (right <= left) {
        return;
    }

    int pivot = tab[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (tab[i] < pivot) {
            i++;
        }

        while (pivot < tab[j]) {
            j--;
        }

        if (i > j) {
            break;
        }

        swap(tab[i], tab[j]);

        i++;
        j--;
    }

    quickSort(tab, left, j);
    quickSort(tab, i, right);
}

void printArray(int array[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {
    int tab[10] = {7, 2, -2, 7, 7, 293, 1, 5, 94, -5};
    int n = 10;
    
    quickSort(tab, 0, n - 1);
     
    printArray(tab, n);
    
    return 0;
}
```

