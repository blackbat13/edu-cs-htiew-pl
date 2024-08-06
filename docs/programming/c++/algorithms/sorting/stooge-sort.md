# Sortowanie stooge

## [:link: Opis problemu](../../../../algorithms/sorting/stooge-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void stooge_sort(int array[], int i, int j)
{
    if (array[i] > array[j])
    {
        swap(array[i], array[j]);
    }

    if (j - i > 1)
    {
        int t = (j - i + 1) / 3;
        stooge_sort(array, i, j - t);
        stooge_sort(array, i + t, j);
        stooge_sort(array, i, j - t);
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

    stooge_sort(array, 0, n - 1);

    print_array(array, n);

    return 0;
}
```
