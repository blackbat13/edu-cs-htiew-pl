# Spójne składowe

## [Opis problemu](../../../../algorithms/graphs/connected-components.md)

## Implementacja

```python linenums="1"
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
    visited = [False] * len(graph)
    
    for node, vis in enumerate(visited):
        if not vis:
            result += 1
            dfs(graph, visited, node)

    return result

graph = [
	[1, 6],
	[0, 6, 3, 2],
	[1, 3],
	[2, 1, 6, 4, 5],
	[3, 5],
	[4, 3, 6],
	[0, 1, 3, 5]
]

result = count_connected_components(graph)

print("Number of connected components in the graph:", result)
```
