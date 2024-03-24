# Rozwiązania - Python

## Zadanie 1

```python
from math import inf


def dfs(x, y, maze, length):
    if maze[x][y] == 9:
        return length

    if maze[x][y] == 0:
        return inf

    maze[x][y] = 0

    return min(
        dfs(x - 1, y, maze, length + 1),
        dfs(x + 1, y, maze, length + 1),
        dfs(x, y - 1, maze, length + 1),
        dfs(x, y + 1, maze, length + 1),
    )


with open("maze.txt") as file:
    file.readline()
    maze = [list(map(int, list(line.strip()))) for line in file]

x, y = 1, 1
print(dfs(x, y, maze, 0))
```

## Zadanie 2

```python
from math import inf


def dfs_cost(x, y, maze, cost):
    if maze[x][y] == 9:
        return cost - 1

    if maze[x][y] == 0:
        return inf

    cost += maze[x][y]
    maze[x][y] = 0

    return min(
        dfs_cost(x - 1, y, maze, cost),
        dfs_cost(x + 1, y, maze, cost),
        dfs_cost(x, y - 1, maze, cost),
        dfs_cost(x, y + 1, maze, cost),
    )


with open("maze.txt") as file:
    file.readline()
    maze = [list(map(int, list(line.strip()))) for line in file]

x, y = 1, 1
print(dfs_cost(x, y, maze, 0))
```

## Zadanie 3

```python
from math import inf


def dfs(x, y, maze, length):
    if maze[x][y] == 9:
        return length

    if maze[x][y] == 0:
        return inf

    maze[x][y] = 0

    return min(
        dfs(x - 1, y, maze, length + 1),
        dfs(x + 1, y, maze, length + 1),
        dfs(x, y - 1, maze, length + 1),
        dfs(x, y + 1, maze, length + 1),
    )


with open("maze.txt") as file:
    width, height = map(int, file.readline().split())
    maze_str = file.read().strip()
    fields_count = width * height - maze_str.count("0")
    maze = [list(map(int, list(line.strip()))) for line in maze_str.split("\n")]

x, y = 1, 1
print(fields_count - dfs(x, y, maze, 0) - 1)
```

## Zadanie 4

```python
with open("maze.txt") as file:
    file.readline()
    maze_sum = sum([sum(map(int, list(line.strip()))) for line in file])

print(maze_sum - 10)
```

## Zadanie 5

```python
with open("maze.txt") as file:
    width, height = map(int, file.readline().split())
    maze = [list(map(int, list(line.strip()))) for line in file]

x, y = 1, 1
result = 0
while x != width - 1 and y != height - 1:
    if maze[x + 1][y] > maze[x][y + 1]:
        x += 1
    else:
        y += 1

    result += maze[x][y]

while x != width - 1:
    x += 1
    result += maze[x][y]

while y != height - 1:
    y += 1
    result += maze[x][y]

print(result - 9)
```

## Zadanie 6

```python
with open("maze.txt") as file:
    width, height = map(int, file.readline().split())
    maze = [list(map(int, list(line.strip()))) for line in file]

for x in range(height - 2, 0, -1):
    for y in range(width - 2, 0, -1):
        maze[x][y] += max(maze[x + 1][y], maze[x][y + 1])

print(maze[1][1] - 10)
```
