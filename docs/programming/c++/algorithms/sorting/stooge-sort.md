# Sortowanie stooge

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/stooge-sort.md" %}
[stooge-sort.md](../../../../algorithms/sorting/stooge-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
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
{% endcode %}
