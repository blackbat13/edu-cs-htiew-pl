# Sortowanie przez wybieranie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/selection-sort.md" %}
[selection-sort.md](../../../../algorithms/sorting/selection-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

int findMin(int array[], int from, int to) {
    int minValue = array[from], minIndex = from;
    for (int i = from + 1; i < to; i++) {
        if (array[i] < min_value) {
            minValue = array[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void selectionSort(int array[], int n) {
    for(int i = 0; i < n; i++) {
        int minIndex = findMin(array, i, n);

        swap(array[i], array[minIndex]);
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
    
    selectionSort(array, 10);

    printArray(array, n);

    return 0;
}
```
{% endcode %}
