# Najdłuższy wspólny podciąg

## Opis problemu

{% content-ref url="../../../../algorithms/text/longest-common-subsequence.md" %}
[longest-common-subsequence.md](../../../../algorithms/text/longest-common-subsequence.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def longest_common_subsequence(a: str, b: str) -> str:
    matrix = [[0] * (len(b) + 1) for _ in range(len(a) + 1)]
    result = ""

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            if a[i - 1] == b[j - 1]:
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            else:
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])

    value = matrix[len(a)][len(b)]
    i, j = len(a), len(b)
    
    while value > 0:
        if matrix[i - 1][j] == value:
            i -= 1
        elif matrix[i][j - 1] == value:
            j -= 1
        else:
            result = a[i - 1] + result
            i -= 1
            j -= 1
            value -= 1

    return result


a = "kitten"
b = "sitting"
    
lcs = longest_common_subsequence(a, b)
    
print(f"Longest common subsequence of words {a} and {b} is {lcs}")
```
{% endcode %}
