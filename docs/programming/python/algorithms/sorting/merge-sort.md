# Sortowanie przez scalanie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/merge-sort.md" %}
[merge-sort.md](../../../../algorithms/sorting/merge-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def merge(array: list, left: int, right: int, division: int):
    merged_length = right - left
    merged = []
    index1 = left
    index2 = division

    for i in range(merged_length):
        if index1 >= division or (index2 < right and array[index1] > array[index2]):
            merged.append(array[index2])
            index2 += 1
        elif index2 >= right or array[index1] <= array[index2]:
            merged.append(array[index1])
            index1 += 1

    for i in range(merged_length):
        array[left + i] = merged[i]


def merge_sort(array: list, left: int, right: int):
    if right - left <= 1:
        return

    division = (left + right) // 2
    
    merge_sort(array, left, division)
    merge_sort(array, division, right)
    
    merge(array, left, right, division)


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

merge_sort(array, 0, len(array))

print(array)
```
{% endcode %}
