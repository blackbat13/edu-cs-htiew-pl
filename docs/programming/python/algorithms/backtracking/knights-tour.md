# Problem skoczka

## [:link: Opis problemu](../../../../algorithms/backtracking/knights-tour.md)

## Implementacja

```python linenums="1"
from pprint import pprint

moves_list = [(-1, -2), (1, -2), (2, -1), (2, 1), (-2, -1), (-1, 2), (1, 2)]

def kinght_tour(n: int, chessboard: list, visited_count: int, row: int, column: int) -> tuple:
    chessboard[row][column] = visited_count - 1
    
    if visited_count == n * n:
        return True, chessboard

    for move_row, move_column in moves_list:
        new_row = row + move_row
        new_column = column + move_column
        if 0 <= new_row < n and 0 <= new_column < n and chessboard[new_row][new_column] == -1:
            result_value, result_chessboard = kinght_tour(n, chessboard, visited_count + 1, new_row, new_column)
            if result_value:
                return True, result_chessboard

    chessboard[row][column] = -1
    return False, None

n = 5
chessboard = [[-1] * n for _ in range(n)]

result_value, result_chessboard = kinght_tour(n, chessboard, 1, 0, 0)

if result_value:
    print("Result found:")
    pprint(result_chessboard)
else:
    print("No result")
```
