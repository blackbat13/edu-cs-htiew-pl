# Problem n królowych

## [Opis problemu](../../../../algorithms/backtracking/n-queens.md)


## Implementacja

```python linenums="1"
from pprint import pprint


def find_solution(n: int, queen_id: int, positions: list) -> bool:
    if queen_id == n:
        return True

    for i in range(n):
        if not check_new_position(queen_id, i, positions):
            continue

        positions[queen_id] = i
        
        if find_solution(n, queen_id + 1, positions):
            return True

    return False


def check_new_position(x: int, y: int, positions: list) -> bool:
    for i in range(x):
        if positions[i] == y:
            return False
            
        if y - positions[i] == x - i:
            return False

    return True


def print_checkboard(n: int, positions: list):
    board = [[0] * n for _ in range(n)]
    
    for i in range(n):
        board[positions[i]][i] = 1
        
    pprint(board)
    

n = 5
positions = [0] * n

result = find_solution(n, 0, positions)

if result:
    print(f"Positions: {positions}")
    print("Checkboard:")
    print_checkboard(n, positions)
else:
    print("No result exists")
```

