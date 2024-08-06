# Sortowanie Shella

## [:link: Opis problemu](../../../../algorithms/sorting/shell-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void shell_sort(int array[], int n)
{
    int gap = n / 2;

    while(gap > 0) {
        for(int i = 0; i < n - gap; i++) {
            if (array[i] > array[i + gap]) {
                swap(array[i], array[i + gap]);
            }
        }

        gap /= 2;
    }
}

void print_array(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

int main()
{
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    int n = 10;

    shell_sort(array, n);

    print_array(array, n);

    return 0;
}
```
