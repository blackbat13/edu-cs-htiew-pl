# Minkowski Sausage

## [Opis problemu](../../../../algorithms/fractals/minkowski-sausage.md)

## Implementacja

```python linenums="1"
import turtle

def minkowski_curve(rank, length):
    if rank > 0:
        turtle.right(30)
        minkowski_curve(rank - 1, length / 2)
        turtle.left(90)
        minkowski_curve(rank - 1, length / 2)
        turtle.right(90)
        minkowski_curve(rank - 1, length / 2)
        turtle.left(30)
    else:
        turtle.forward(length)

def minkowski_sausage(rank, length):
    for i in range(0, 4):
        minkowski_curve(rank, length)
        turtle.right(90)

turtle.speed(0)
turtle.penup()
turtle.back(150)
turtle.pendown()

minkowski_sausage(3, 100)

turtle.done()
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/Minkowski-Sausage#main.py](https://replit.com/@damiankurpiewski/Minkowski-Sausage#main.py)
