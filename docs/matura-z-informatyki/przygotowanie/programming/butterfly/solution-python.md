# Rozwiązania

## Zadanie 1

```python linenums="1"
movement = {"L": (-1, 0, 0),
            "R": (1, 0, 0),
            "U": (0, 1, 0),
            "D": (0, -1, 0),
            "F": (0, 0, 1),
            "B": (0, 0, -1)}
side = 8
with open("motylek.txt", "r") as file:
    x, y, z = (0, 0, 0)
    moves = file.read().split()
    for num, move in enumerate(moves):
        xm, ym, zm = movement[move]
        x += xm
        y += ym
        z += zm
        if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
            print(num + 1)
            print(x - xm, y - ym, z - zm)
            break
```

## Zadanie 2

```python linenums="1"
movement = {"L": (-1, 0, 0),
            "R": (1, 0, 0),
            "U": (0, 1, 0),
            "D": (0, -1, 0),
            "F": (0, 0, 1),
            "B": (0, 0, -1)}
side = 8
result = 0
with open("motylek.txt") as file:
    x, y, z = (0, 0, 0)
    moves = file.read().split()
    for num, move in enumerate(moves):
        xm, ym, zm = movement[move]
        x += xm
        y += ym
        z += zm
        if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
            x -= xm
            y -= ym
            z -= zm
        else:
            result += 1

    print()
    print(result)
    print(x, y, z)
```

## Zadanie 3

```python linenums="1"
movement = {"L": (-1, 0, 0),
            "R": (1, 0, 0),
            "U": (0, 1, 0),
            "D": (0, -1, 0),
            "F": (0, 0, 1),
            "B": (0, 0, -1)}
side = 8
min_num = 0
max_num = 0
current_length = 1
max_length = 1
with open("motylek.txt") as file:
    x, y, z = (0, 0, 0)
    moves = file.read().split()
    for num, move in enumerate(moves):
        xm, ym, zm = movement[move]
        x += xm
        y += ym
        z += zm
        if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
            x -= xm
            y -= ym
            z -= zm
            if current_length > max_length:
                max_length = current_length
                max_num = num + 1
                min_num = max_num - max_length + 1

            current_length = 1
        else:
            current_length += 1

    print()
    print(max_length)
    print(min_num, max_num)
```

## Zadanie 4

```python linenums="1"
movement = {"L": (-1, 0, 0),
            "R": (1, 0, 0),
            "U": (0, 1, 0),
            "D": (0, -1, 0),
            "F": (0, 0, 1),
            "B": (0, 0, -1)}
side = 8
result = 0
with open("motylek.txt") as file:
    x, y, z = (0, 0, 0)
    moves = file.read().split()
    for num, move in enumerate(moves):
        xm, ym, zm = movement[move]
        x += xm
        y += ym
        z += zm
        if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
            x = xm
            y = ym
            z = zm
            result += 1

    print()
    print(result)
```

## Zadanie 5

```python linenums="1"
movement = {"L": (-1, 0, 0),
            "R": (1, 0, 0),
            "U": (0, 1, 0),
            "D": (0, -1, 0),
            "F": (0, 0, 1),
            "B": (0, 0, -1)}
positions = [(0, 0, 0)]
with open("motylek.txt") as file:
    x, y, z = (0, 0, 0)
    moves = file.read().split()
    for num, move in enumerate(moves):
        xm, ym, zm = movement[move]
        x += xm
        y += ym
        z += zm

    positions.append((x, y, z))

max_dist = 0
p1 = (0,0,0)
p2 = (0,0,0)
for i in range(len(positions)):
    for j in range(i + 1, len(positions)):
        x1, y1, z1 = positions[i]
        x2, y2, z2 = positions[j]
        dist = (x1-x2)**2 + (y1-y2)**2 + (z1-z2)**2
        if dist > max_dist:
            max_dist = dist
            p1 = positions[i]
            p2 = positions[j]

print()
print(p1, p2)
print(f"{(max_dist**0.5):.2f}")
```
