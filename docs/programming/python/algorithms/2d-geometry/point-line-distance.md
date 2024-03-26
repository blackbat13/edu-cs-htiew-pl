# Odległość punktu od prostej

## [Opis problemu](../../../../algorithms/2d-geometry/point-line-distance.md)


## Implementacja

```python linenums="1"
from math import abs, sqrt


def point_line_distance(line_point1: dict, line_point2: dict, point: dict) -> float:
    a = line_point2["y"] - line_point1["y"]
    b = line_point2["x"] - line_point1["x"]
    
    return abs(a * (line_point1["x"] - point["x"]) + b * (point["y"] - line_point1["y"])) / sqrt(a * a + b * b)


line_point1 = {"x": -3, "y": -4}
line_point2 = {"x": 7, "y": 6}
point = {"x": -5, "y": -8}

distance = point_line_distance(line_point1, line_point2, point)
    
print(distance)
```


### Opis implementacji

Funkcja `point_line_distance` przyjmuje jako argumenty współrzędne dwóch punktów (`line_point1`, `line_point2`) określających prostą oraz współrzędne punktu (`point`), dla którego obliczana jest odległość. Na początku obliczane są różnice między współrzędnymi drugiego punktu a pierwszego punktu prostej. Wartość `a` to różnica współrzędnymi $y$, a `b` to różnica pomiędzy współrzędnymi $x$.

Następnie obliczana jest odległość między punktem a prostą przy użyciu wzoru `abs(a * (line_point1["x"] - point["x"]) + b * (point["y"] - line_point1["y"])) / sqrt(a * a + b * b)`, gdzie:

- `a * (line_point1["x"] - point["x"]) + b * (point["y"] - line_point1["y"])` oblicza numeryczną wartość iloczynu skalarnego między wektorem normalnym do prostej a wektorem od pierwszego punktu prostej do badanego punktu,
- `abs(...)` oblicza wartość bezwzględną tego iloczynu skalarnego,
- `sqrt(a * a + b * b)` oblicza długość wektora normalnego do prostej.

Wynik obliczeń jest zwracany jako wartość odległości.

W przykładzie podane są konkretne wartości dla punktu `point` i prostych `(line_point1, line_point2)`. Funkcja `point_line_distance` jest wywoływana z tymi wartościami, a obliczona odległość jest wyświetlana przy użyciu funkcji `print`.

W wyniku wykonania tego kodu, zostanie wyświetlona odległość między punktem $(-5, -8)$ a prostą przechodzącą przez punkty $(-3, -4)$ i $(7, 6)$.
