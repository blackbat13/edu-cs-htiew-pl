# Metoda Monte Carlo

## [Opis problemu](../../../../algorithms/numerical-methods/monte-carlo.md)

## Obliczanie wartości liczby PI

```python linenums="1"
from random import random

def monte_carlo_pi(points_count: int) -> float:
    num_points_in_circle = 0
    center_x = center_y = radius = 1
    
    for _ in range(points_count):
        x = random() * 2.0
        y = random() * 2.0
        distance = ((x - center_x) ** 2) + ((y - center_y) ** 2)
        
        if distance <= radius ** 2:
            num_points_in_circle += 1

    return (4 * num_points_in_circle) / points_count

points_count = 1000

estimated_pi = monte_carlo_pi(points_count)

print(f"PI ~= {estimated_pi}")
```

## Obliczanie wartości PI wraz z rysowaniem wykresu

```python linenums="1"
from random import random

import matplotlib.pyplot as plt

def monte_carlo_pi(points_count: int) -> float:
    num_points_in_circle = 0
    center_x = center_y = radius = 1
    plot_values = []

    for i in range(1, points_count + 1):
        x = random() * 2.0
        y = random() * 2.0
        distance = ((x - center_x) ** 2) + ((y - center_y) ** 2)

        if distance <= radius ** 2:
            num_points_in_circle += 1

        plot_values.append((4 * num_points_in_circle) / i)

    plt.plot(plot_values)
    plt.xlabel("Number of points")
    plt.ylabel("Estimated PI value")
    plt.title("Monte Carlo method for computing PI value")

    return (4 * num_points_in_circle) / points_count

points_count = 1000

estimated_pi = monte_carlo_pi(points_count)

print(f"PI ~= {estimated_pi}")

plt.show()
```
