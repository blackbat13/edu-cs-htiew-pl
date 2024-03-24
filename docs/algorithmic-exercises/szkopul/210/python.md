# Python

## Implementacja

```python
n = int(input())

binary = format(n, "b")

digits = list(map(int, list(binary)))

digits_sum = sum(digits)

binary_sum = format(digits_sum, "b")

print(binary, binary_sum)
```