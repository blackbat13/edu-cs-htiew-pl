# Sortowanie wolne

## [Opis problemu](../../../../algorithms/sorting/slow-sort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void slow_sort(int array[], int start_index, int end_index)
{
    if (start_index >= end_index)
    {
        return;
    }

    int middle_index = (start_index + end_index) / 2;
    slow_sort(array, start_index, middle_index);
    slow_sort(array, middle_index + 1, end_index);
    if (array[end_index] < array[middle_index])
    {
        swap(array[end_index], array[middle_index]);
    }

    slow_sort(array, start_index, end_index - 1);
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

    slow_sort(array, 0, n - 1);

    print_array(array, n);

    return 0;
}
```
