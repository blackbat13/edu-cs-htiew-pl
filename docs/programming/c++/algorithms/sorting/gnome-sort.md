# Sortowanie gnoma

## Opis implementacji


[gnome-sort.md](../../../../algorithms/sorting/gnome-sort.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void gnomeSort(int array[], int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || array[i] >= array[i - 1]) {
            i++;
        } else {
            swap(array[i], array[i - 1]);
            i--;
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
    
    gnomeSort(array, n);

    printArray(array, n);

    return 0;
}
```

