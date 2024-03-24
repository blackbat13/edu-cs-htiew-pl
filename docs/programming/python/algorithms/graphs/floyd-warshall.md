---
description: Najkrótsze ścieżki pomiędzy wszystkimi wierzchołkami
---

# Floyd-Warshall

## Opis problemu

{% content-ref url="../../../../algorithms/graphs/floyd-warshall.md" %}
[floyd-warshall.md](../../../../algorithms/graphs/floyd-warshall.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
import math
from typing import List
from pprint import pprint


def floyd_warshall(graph: List[List[int]]):
    for k in range(len(graph)):
        for i in range(len(graph)):
            for j in range(len(graph)):
                if i == j or k == i or k == j:
                    continue

                if graph[i][k] + graph[k][j] < graph[i][j]:
                    graph[i][j] = graph[i][k] + graph[k][j]


f = math.inf
graph = [
    [0, 5, f, f, f, f, 5],
    [5, 0, 3, 3, f, f, 5],
    [f, 3, 0, 1, f, f, f],
    [f, 3, 1, 0, 5, 4, 3],
    [f, f, f, 5, 0, 2, f],
    [f, f, f, 4, 2, 0, 5],
    [5, 5, f, 3, f, 5, 0],
]

floyd_warshall(graph)

pprint(graph)
```
{% endcode %}
