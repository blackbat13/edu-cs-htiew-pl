# Rozwiązania - Python

## Zadanie 1

```python linenums="1"
with open("rectangles.txt") as file:
    rectangles = [
        list(map(int, line.split())) for line in file.read().strip().split("\n")
    ]

result = 0
for rect in rectangles:
    x1, y1, x2, y2 = rect
    width = x2 - x1
    height = y1 - y2
    result += width * height

print(result)
```

## Zadanie 2

```python linenums="1"
def do_rectangles_intersect(rect1, rect2):
    x1, y1, x2, y2 = rect1
    x3, y3, x4, y4 = rect2

    if x2 <= x3 or x4 <= x1:
        return False

    if y1 <= y4 or y3 <= y2:
        return False

    return True


with open("rectangles.txt") as file:
    rectangles = [
        list(map(int, line.split())) for line in file.read().strip().split("\n")
    ]

result = 0
for i, rect1 in enumerate(rectangles):
    for rect2 in rectangles[i + 1 :]:
        if do_rectangles_intersect(rect1, rect2):
            result += 1

print(result)
```

## Zadanie 3

```python linenums="1"
def intersection_area(rect1, rect2):
    x1, y1, x2, y2 = rect1
    x3, y3, x4, y4 = rect2

    intersect_x1 = max(x1, x3)
    intersect_y1 = min(y1, y3)
    intersect_x2 = min(x2, x4)
    intersect_y2 = max(y2, y4)

    width = intersect_x2 - intersect_x1
    height = intersect_y1 - intersect_y2

    if width > 0 and height > 0:
        return width * height
    else:
        return 0


with open("rectangles.txt") as file:
    rectangles = [
        list(map(int, line.split())) for line in file.read().strip().split("\n")
    ]

result = 0
for i, rect1 in enumerate(rectangles):
    for rect2 in rectangles[i + 1 :]:
        result += intersection_area(rect1, rect2)

print(result)
```

## Zadanie 4

```python linenums="1"
def is_inside(rect, xp, yp):
    x1, y1, x2, y2 = rect
    return x1 < xp < x2 and y2 < yp < y1


with open("rectangles.txt") as file:
    rectangles = [
        list(map(int, line.split())) for line in file.read().strip().split("\n")
    ]

result = 0
for rect in rectangles:
    if is_inside(rect, 0, 0):
        print(*rect)
        result += 1

print("Łącznie prostokątów:", result)
```

## Zadanie 5

```python linenums="1"
def is_inside(rect, xp, yp):
    x1, y1, x2, y2 = rect
    return x1 < xp < x2 and y2 < yp < y1


with open("rectangles.txt") as file:
    rectangles = [
        list(map(int, line.split())) for line in file.read().strip().split("\n")
    ]

result = 0
for i, rect1 in enumerate(rectangles):
    for rect2 in rectangles[i + 1 :]:
        x1, y1, x2, y2 = rect1
        x3, y3, x4, y4 = rect2
        if is_inside(rect1, x3, y4) and is_inside(rect1, x4, y4):
            result += 1
        elif is_inside(rect2, x1, y1) and is_inside(rect2, x2, y2):
            result += 1

print(result)
```

## Zadanie 6

```python linenums="1"
with open("rectangles.txt") as file:
    rectangles = [
        list(map(int, line.split())) for line in file.read().strip().split("\n")
    ]

points = [(rect[0], rect[1]) for rect in rectangles]
points += [(rect[2], rect[3]) for rect in rectangles]
max_dist = 0
for i, point1 in enumerate(points):
    for point2 in points[i + 1:]:
        dist_sqr = ((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)
        if dist_sqr > max_dist:
            max_dist = dist_sqr

for i, point1 in enumerate(points):
    for point2 in points[i + 1:]:
        dist_sqr = ((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2)
        if dist_sqr == max_dist:
            print(point1, point2)

print(f"Odległość: {max_dist**0.5:0.2f}")
```
