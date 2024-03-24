# Python

## Implementacja

```python
n = int(input())
numbers = list(map(int, input().split()))

sum = 0
oddCount = 0
evenCount = 0
result = 0

for num in numbers:
    sum += num
    if sum % 2 == 0:
        evenCount += 1
        result += evenCount
    else:
        result += oddCount
        oddCount += 1

print(result)
```