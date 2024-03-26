# Python - rozwiązanie

```python linenums="1"
cases = int(input())

for _ in range(cases):
    n = int(input())
    lastIndex = dict()
    maxSnowflakes = 0
    startIndex = 0
    snowflakes = [int(input()) for _ in range(n)]

    for i in range(n):
        if snowflakes[i] in lastIndex:
            index = lastIndex[snowflakes[i]]
            while startIndex <= index:
                lastIndex.pop(snowflakes[startIndex])
                startIndex += 1

        lastIndex[snowflakes[i]] = i
        maxSnowflakes = max(maxSnowflakes, i - startIndex + 1)

    print(maxSnowflakes)
```

