# Flood fill

## [:link: Opis problemu](../../../../algorithms/graphs/flood-fill.md)

## Implementacja

```python linenums="1"
from pprint import pprint

def flood_fill(image, row, column, symbol="*"):
    if image[row][column] != " ":
        return
    
    image[row][column] = symbol
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

    for direct in directions:
        r, c = direct
        flood_fill(image, row + r, column + c)

image = [
    list("########"),
    list("#  #   #"),
    list("#  #   #"),
    list("#  #   #"),
    list("### ####"),
    list("#  #   #"),
    list("#  #   #"),
    list("########")
]

pprint(image)
print()

flood_fill(image, 1, 1)

pprint(image)
```
