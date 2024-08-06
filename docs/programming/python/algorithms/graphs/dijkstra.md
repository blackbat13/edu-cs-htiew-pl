---
description: Najkrótsze ścieżki z zadanego wierzchołka
---

# Dijkstra

## [:link: Opis problemu](../../../../algorithms/graphs/dijkstra.md)

## Implementacja

```python linenums="1"
from math import inf
from typing import List
from queue import Queue
from collections import namedtuple

Edge = namedtuple('Edge', ['start', 'end', 'cost'])

def dijkstra(graph: List[List[Edge]], node: int) -> List[int]:
    q = Queue()
    distances = [inf] * len(graph)
        
    distances[node] = 0

    for edge in graph[node]:
        q.put(edge)

    while not q.empty():
        current_edge = q.get()
        new_distance = distances[current_edge.start] + current_edge.cost
        
        if new_distance < distances[current_edge.end]:
            distances[current_edge.end] = new_distance
            
            for edge in graph[current_edge.end]:
                q.put(edge)

    return distances

graph = [
    [Edge(0, 1, 5), Edge(0, 6, 5)],
    [Edge(1, 0, 5), Edge(1, 6, 5), Edge(1, 3, 3), Edge(1, 2, 3)],
    [Edge(2, 1, 3), Edge(2, 3, 1)],
    [Edge(3, 2, 1), Edge(3, 1, 3), Edge(3, 6, 3), Edge(3, 4, 5), Edge(3, 5, 4)],
    [Edge(4, 3, 5), Edge(4, 5, 2)],
    [Edge(5, 4, 2), Edge(5, 3, 4), Edge(5, 6, 5)],
    [Edge(6, 0, 5), Edge(6, 1, 5), Edge(6, 3, 3), Edge(6, 5, 5)],
]

distances = dijkstra(graph, 0)

print(distances)
```
