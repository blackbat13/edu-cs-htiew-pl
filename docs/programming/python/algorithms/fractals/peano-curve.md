# Krzywa Peano

## [:link: Opis problemu](../../../../algorithms/fractals/peano-curve.md)

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

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=rZDNDoIwEIRfZdNTSYoBowc4-CQkptLlJ-C2qQUOxndXfhRQEy_urTPTr7O9spbFoWCpVshiVp6Ntg5cY12NCSWkMAODkvQxbWyL3EqqBEjKaxRQI-Wu8OKE4DFlBr0LBwgmpZ8RtbFlXjg-3PNm850MPoQC_DX-g5Vp20mr-If_Hfdf2q9yNWbznglN6sUgKh54L8EgNYbP55NMKx7uF4kBFC2EZ9FVavzXaE1WuiM-PL_cYScgCgRsg2UxpQn7KLvdAQ)
