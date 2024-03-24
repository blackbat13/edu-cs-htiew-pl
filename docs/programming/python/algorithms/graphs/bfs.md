---
description: Przeszukiwanie grafu wszerz
---

# BFS

## Opis problemu

{% content-ref url="../../../../algorithms/graphs/bfs.md" %}
[bfs.md](../../../../algorithms/graphs/bfs.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
from typing import List
from queue import Queue


def bfs(graph: List[List[int]], visited: List[bool], node: int):
    q = Queue()
    q.put(node)

    while not q.empty():
        node = q.get()
        
        if visited[node]:
            continue

        visited[node] = True
        print(node)

        for new_node in graph[node]:
            if not visited[new_node]:
                q.put(new_node)


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

bfs(graph, visited, 0)
```
{% endcode %}
