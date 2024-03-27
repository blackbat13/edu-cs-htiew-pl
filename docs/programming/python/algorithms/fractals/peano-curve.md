# Krzywa Peano

## [Opis problemu](../../../../algorithms/fractals/peano-curve.md)

## Implementacja

```python linenums="1"
import turtle

def peano_curve(rank, angle, length):
    if rank > 0:
        turtle.right(angle)
        peano_curve(rank - 1, -angle, length)
        turtle.forward(length)
        peano_curve(rank - 1, angle, length)
        turtle.forward(length)
        peano_curve(rank - 1, -angle, length)
        turtle.left(angle)

turtle.speed(0)
turtle.penup()
turtle.back(150)
turtle.left(90)
turtle.forward(150)
turtle.right(90)
turtle.pendown()

peano_curve(4, 90, 20)

turtle.done()
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/Peano-Curve#main.py](https://replit.com/@damiankurpiewski/Peano-Curve#main.py)
