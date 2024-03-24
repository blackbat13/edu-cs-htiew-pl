# Spójne składowe

## Opis problemu

{% content-ref url="../../../../algorithms/graphs/connected-components.md" %}
[connected-components.md](../../../../algorithms/graphs/connected-components.md)
{% endcontent-ref %}

## Implementacja

```python
from typing import List


def dfs(graph: List[List[int]], visited: List[bool], node: int):
    if visited[node]:
        return

    visited[node] = True

    for new_node in graph[node]:
        if not visited[new_node]:
            dfs(graph, visited, new_node)


def count_connected_components(graph: List[List[int]]) -> int:
    result = 0
    visited = [False for _ in range(len(graph))]
    
    for i in range(len(graph)):
        if not visited[i]:
            result += 1
            dfs(graph, visited, i)

    return result;
    

graph = [[] for _ in range(7)]
graph[0] = [1, 6]
graph[1] = [0, 6, 3, 2]
graph[2] = [1, 3]
graph[3] = [2, 1, 6, 5]
graph[4] = [3, 5]
graph[5] = [3, 6]
graph[6] = [0, 1, 3, 5]

visited = [False for _ in range(len(graph))]

result = count_connected_components(graph)

print("Number of connected components in the graph:", result)
```

### Link do implementacji

{% embed url="https://ideone.com/68F4l6" %}
Spójne składowe
{% endembed %}

### Opis implementacji

TODO
