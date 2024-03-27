# Sortowanie topologiczne

## [Opis problemu](../../../../algorithms/graphs/topological-sort.md)

## Implementacja

```python linenums="1"
def topological_sort(graph: list) -> list:
  in_ranks = [0] * len(graph)
  removed = [False] * len(graph)
  result = []
    
  for neighbours_list in graph:
    for node in neighbours_list:
        in_ranks[node] += 1

  change = True

  while change and len(result) < len(graph):
    change = False
        
    for i, neighbours_list in enumerate(graph):
      if removed[i] or in_ranks[i] > 0:
        continue

      change = True
      result.append(i)
      removed[i] = True
            
      for node in neighbours_list:
          in_ranks[node] -= 1

  return result

graph = [
		[2],
		[0, 2],
		[],
		[1, 0, 4],
		[2, 1],
		[0, 4],
]

result = topological_sort(graph)
    
if len(result) < len(graph):
  print("Graph has a cycle")
else:
  print(" ".join(map(str, result)))
```
