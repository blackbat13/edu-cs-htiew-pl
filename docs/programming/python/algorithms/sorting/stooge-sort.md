# Sortowanie stooge

## [Opis problemu](../../../../algorithms/sorting/stooge-sort.md)

## Implementacja

```python linenums="1"
def stooge_sort(array: list, i: int, j: int):
    if array[i] > array[j]:
        array[i], array[j] = array[j], array[i]

    if j - i > 1:
        t = (j - i + 1) // 3
        stooge_sort(array, i, j - t)
        stooge_sort(array, i + t, j)
        stooge_sort(array, i, j - t)

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

stooge_sort(array, 0, len(array) - 1)

print(array)
```
