---
description: Przeszukiwanie grafu w głąb
---

# DFS

## [:link: Opis problemu](../../../../algorithms/graphs/dfs.md)

## Implementacja

```python linenums="1"
from typing import List

def dfs(graph: List[List[int]], visited: List[bool], node: int):
    if visited[node]:
        return

    visited[node] = True
    print(node)

    for new_node in graph[node]:
        if not visited[new_node]:
            dfs(graph, visited, new_node)

graph = [
	[1, 6],
	[0, 6, 3, 2],
	[1, 3],
	[2, 1, 6, 4, 5],
	[3, 5],
	[4, 3, 6],
	[0, 1, 3, 5],
]

visited = [False] * len(graph)

dfs(graph, visited, 0)
```
