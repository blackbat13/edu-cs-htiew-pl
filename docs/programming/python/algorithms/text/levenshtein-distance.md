# Odległość Levenshteina (edycyjna)

## Opis problemu

{% content-ref url="../../../../algorithms/text/levenshtein-distance.md" %}
[levenshtein-distance.md](../../../../algorithms/text/levenshtein-distance.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def levenshtein_distance(a: str, b: str) -> int:
    matrix = [[i + j for j in range(len(b) + 1)] for i in range(len(a) + 1)]

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            if a[i - 1] == b[j - 1]:
                cost = 0
            else:
                cost = 1
                
            matrix[i][j] = min(matrix[i - 1][j - 1] + cost, min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1))

    return matrix[len(a)][len(b)]



a = "kitten"
b = "sitting"
    
distance = levenshtein_distance(a, b)

print(f"Odległość Levenshteina pomiędzy wyrazami {a} i {b} wynosi {distance}")
```
{% endcode %}
