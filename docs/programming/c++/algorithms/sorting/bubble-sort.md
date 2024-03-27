# Sortowanie bąbelkowe

## [Opis problemu](../../../../algorithms/sorting/bubble-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void bubbleSort(int array[], int n) {
	bool sorted = false;
	int i = 0;
    while (!sorted) {
    	sorted = true;
        for(int j = n - 1; j > i; j--) {
            if(array[j] < array[j-1]) {
                swap(array[j], array[j-1]);
                sorted = false;
            }
        }
        
        i++;
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
    
    bubbleSort(array, n);

    printArray(array, n);

    return 0;
}
```
