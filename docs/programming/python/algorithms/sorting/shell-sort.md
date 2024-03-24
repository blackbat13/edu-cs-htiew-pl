# Sortowanie Shella

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/shell-sort.md" %}
[shell-sort.md](../../../../algorithms/sorting/shell-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def shell_sort(array: list):
    gap = len(array) // 2
    while gap > 0:
        for i in range(0, len(array) - gap):
            if array[i] > array[i + gap]:
                array[i], array[i + gap] = array[i + gap], array[i]

        gap //= 2


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

shell_sort(array)

print(array)
```
{% endcode %}
