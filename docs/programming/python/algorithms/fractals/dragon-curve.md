# Smocza krzywa

## [:link: Opis problemu](../../../../algorithms/fractals/dragon-curve.md)

## Implementacja

```python linenums="1"
import turtle

def dragon_curve(rank, sign, length):
    if rank > 0:
        turtle.left(45 * sign)
        dragon_curve(rank - 1, 1, length)
        turtle.right(90 * sign * -1)
        dragon_curve(rank - 1, -1, length)
        turtle.left(45 * sign)
    else:
        turtle.forward(length)

turtle.speed(0)
turtle.penup()
turtle.back(150)
turtle.left(90)
turtle.forward(150)
turtle.right(90)
turtle.pendown()

dragon_curve(10, 1, 5)

turtle.done()
```

### Link do implementacji

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=hZDbCoMwDIZfJfSqDh0W5oVe7EmE4Ww8oEulVr0Ye_ep84hjC4XS_MmX_H2ylgXCZrGSyAKWPyqlDZhGmxJDCkliAlJHqaJb3OgWuY6osKHOU7KhREpNZgUhQR95AoMIV3CnzBAf1LnExPCLB6ex1Vr1AxwcEPZwJvoBpfM0M9x3J1Z_OeI_0PlB_LocljUefSRKd5GWfEGFNCl1hSi5ay2JCqmp-Pq-R3HBhbepGOf6m8RM31XNfndkqTri4_idX-GOX-dtF5OKcChlrzc)
