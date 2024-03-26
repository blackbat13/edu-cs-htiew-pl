# Kruskal

## [Opis problemu](../../../../algorithms/graphs/kruskal.md)


## Implementacja

```python linenums="1"
import heapq


class DisjointUnion:
    class Node:
        def __init__(self, parent: int, rank: int):
            self.parent = parent
            self.rank = rank

    def __init__(self, number_of_nodes: int):
        self._subsets = [self.Node(i, 0) for i in range(number_of_nodes)]

    def union(self, el1: int, el2: int):
        x_root = self.find(el1)
        y_root = self.find(el2)

        if self._subsets[x_root].rank < self._subsets[y_root].rank:
            self._subsets[x_root].parent = y_root
        elif self._subsets[x_root].rank > self._subsets[y_root].rank:
            self._subsets[y_root].parent = x_root
        else:
            self._subsets[y_root].parent = x_root
            self._subsets[x_root].rank += 1

    def is_in_union(self, el1: int, el2: int) -> bool:
        return self.find(el1) == self.find(el2)

    def find(self, node_number: int) -> int:
        if self._subsets[node_number].parent != node_number:
            self._subsets[node_number].parent = self.find(self._subsets[node_number].parent)

        return self._subsets[node_number].parent


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


def kruskal(graph: list) -> list:
  edges = []
  connected_nodes = DisjointUnion(len(graph))

  min_spanning_tree = []

  for nodes_list in graph:
    for node in nodes_list:
      edges.append(node)

  heapq.heapify(edges)
  while edges:
    current = heapq.heappop(edges)

    if connected_nodes.is_in_union(current.node_from, current.node_to):
      continue
    

    connected_nodes.union(current.node_from, current.node_to)
    min_spanning_tree.append(current)

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
	
  min_spanning_tree = kruskal(graph)

  print(min_spanning_tree)
```

