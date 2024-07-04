# Sortowanie przez scalanie

## [Opis problemu](../../../../algorithms/sorting/merge-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void merge(int array[], int left, int right, int division) {
    int mergedLength = right - left;
    int merged[mergedLength];
    int index1 = left;
    int index2 = division;

    for(int i = 0; i < mergedLength ; i++) {
        if(index1 >= division) {
            merged[i] = array[index2];
            index2++;
        } else if(index2 >= right) {
            merged[i] = array[index1];
            index1++;
        } else if(array[index1] <= array[index2]) {
            merged[i] = array[index1];
            index1++;
        } else {
            merged[i] = array[index2];
            index2++;
        }
    }

    for(int i = left; i < right; i++) {
        array[i] = merged[i-left];
    }
}

void mergeSort(int array[], int left, int right) {
    if(right - left <= 1) {
        return;
    }

    int division = (left + right)/2;
    mergeSort(array, left, division);
    mergeSort(array, division, right);

    merge(array, left, right, division);
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
    
    mergeSort(array, 0, n);

    printArray(array, n);

    return 0;
}
```
