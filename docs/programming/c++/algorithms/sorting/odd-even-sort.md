# Sortowanie odd-even

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/odd-even-sort.md" %}
[odd-even-sort.md](../../../../algorithms/sorting/odd-even-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

void oddEvenSort(int array[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i % 2 + 1; j < n; j += 2) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
}

void printArray(int array[], int n) {
    for(int i = 0; i < 10; ++i) {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    int n = 10;
    
    oddEvenSort(array, n);
    
    printArray(array, n);

    return 0;
}
```
{% endcode %}
