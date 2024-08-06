# Sortowanie wolne

## [:link: Opis problemu](../../../../algorithms/sorting/slow-sort.md)

## Implementacja

```python linenums="1"
def slow_sort(array: list, start_index: int, end_index: int):
    if start_index >= end_index:
        return

    middle_index = (start_index + end_index) // 2
    slow_sort(array, start_index, middle_index)
    slow_sort(array, middle_index + 1, end_index)
    if array[end_index] < array[middle_index]:
        array[middle_index], array[end_index] = array[end_index], array[middle_index]

    slow_sort(array, start_index, end_index - 1)

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

slow_sort(array, 0, len(array) - 1)

print(array)
```
