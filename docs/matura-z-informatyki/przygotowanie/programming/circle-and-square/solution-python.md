# Rozwiązania

## Zadanie 1

{% code overflow="wrap" lineNumbers="true" %}
```python
def zadanie1():
    path = "input/kik.txt"
    with open(path, "r") as file:
        punkty = [list(map(float, str.split(" "))) for str in file.read().split("\n")]
        inside = 0
        outside = 0
        for punkt in punkty:
            x = punkt[0]
            y = punkt[1]
            dist = x * x + y * y
            if dist <= 1:
                inside += 1
            else:
                outside += 1

        print(f"inside: {inside}, outside: {outside}")
```
{% endcode %}

## Zadanie 2

{% code overflow="wrap" lineNumbers="true" %}
```python
def zadanie2():
    path = "input/kik.txt"
    with open(path, "r") as file:
        punkty = [list(map(float, str.split(" "))) for str in file.read().split("\n")]

        max_length = 0
        current_length = 0
        for punkt in punkty:
            x = punkt[0]
            y = punkt[1]
            dist = x * x + y * y
            if dist <= 1:
                current_length += 1
                if current_length > max_length:
                    max_length = current_length
            else:
                current_length = 0

        print()
        print(f"{max_length}")
```
{% endcode %}

## Zadanie 3

{% code overflow="wrap" lineNumbers="true" %}
```python
def zadanie3():
    path = "input/kik.txt"
    with open(path, "r") as file:
        punkty = [list(map(float, str.split(" "))) for str in file.read().split("\n")]
        xs = [punkt[0] for punkt in punkty]
        xs.sort()
        print()
        print(((xs[len(xs) // 2] - xs[len(xs) // 2 - 1]) / 2) + xs[len(xs) // 2 - 1])
```
{% endcode %}

## Zadanie 4

{% code overflow="wrap" lineNumbers="true" %}
```python
def zadanie4():
    path = "input/kik.txt"
    with open(path, "r") as file:
        punkty = [list(map(float, str.split(" "))) for str in file.read().split("\n")]
        punkty = punkty[:100]
        punkty = [[int(punkt[0] * 1000), int(punkt[1] * 1000)] for punkt in punkty]
        for i in range(len(punkty)):
            for j in range(1, len(punkty) - i):
                x1 = punkty[j][0]
                y1 = punkty[j][1]
                x2 = punkty[j - 1][0]
                y2 = punkty[j - 1][1]
                if x1 < x2 or (x1 == x2 and y1 < y2):
                    punkty[j - 1][0], punkty[j][0] = punkty[j][0], punkty[j - 1][0]
                    punkty[j - 1][1], punkty[j][1] = punkty[j][1], punkty[j - 1][1]

        with open("kik_posortowane.txt", "w") as out_file:
            for punkt in punkty:
                print(f"{punkt[0]} {punkt[1]}", file=out_file)
```
{% endcode %}
