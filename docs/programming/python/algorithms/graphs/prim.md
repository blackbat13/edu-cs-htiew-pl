# Prim

## Opis problemu

{% content-ref url="../../../../algorithms/graphs/prim.md" %}
[prim.md](../../../../algorithms/graphs/prim.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
import heapq


class Edge:

  def __init__(self, node_from: int, node_to: int, distance: int):
    self.node_from = node_from
    self.node_to = node_to
    self.distance = distance

  def __lt__(self, other) -> bool:
    return self.distance < other.distance

  def __str__(self) -> str:
    return f"{self.node_from} <-({self.distance})-> {self.node_to}"

  def __repr__(self) -> str:
    return self.__str__()


def prim(graph: list, node: int) -> list:
  visited = [False] * len(graph)
  visited[node] = True

  min_spanning_tree = []

  edges = graph[node][:]

  heapq.heapify(edges)

  while edges:
    current = heapq.heappop(edges)

    if visited[current.node_to]:
      continue

    visited[current.node_to] = True
    min_spanning_tree.append(current)

    for next in graph[current.node_to]:
      if not visited[next.node_to]:
        heapq.heappush(edges, next)

  return min_spanning_tree


if __name__ == "__main__":
  graph = [[Edge(0, 1, 5), Edge(0, 6, 5)],
           [Edge(1, 0, 5),
            Edge(1, 6, 5),
            Edge(1, 3, 3),
            Edge(1, 2, 3)], [Edge(2, 1, 3), Edge(2, 3, 1)],
           [
             Edge(3, 2, 1),
             Edge(3, 1, 3),
             Edge(3, 6, 3),
             Edge(3, 4, 5),
             Edge(3, 5, 4)
           ], [Edge(4, 3, 5), Edge(4, 5, 2)],
           [Edge(5, 4, 2), Edge(5, 3, 4),
            Edge(5, 6, 5)],
           [Edge(6, 0, 5),
            Edge(6, 1, 5),
            Edge(6, 3, 3),
            Edge(6, 5, 5)]]

  min_spanning_tree = prim(graph, 0)

  print(min_spanning_tree)
```
{% endcode %}
