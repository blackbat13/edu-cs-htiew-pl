# Zbiór Cantora

## [:link: Opis problemu](../../../../algorithms/fractals/cantor-dust.md)

## Implementacja

```python linenums="1"
import turtle

def cantor_dust(rank, length):
    if rank > 0:
        cantor_dust(rank - 1, length / 3)
        turtle.penup()
        turtle.forward(length / 3)
        turtle.pendown()
        cantor_dust(rank - 1, length / 3)
    else:
        turtle.forward(length)

def cantor(rank, length):
    for i in range(rank + 1):
        cantor_dust(i, length)
        turtle.penup()
        turtle.back(length)
        turtle.right(90)
        turtle.forward(20)
        turtle.left(90)
        turtle.pendown()

turtle.speed(0)
turtle.penup()
turtle.back(250)
turtle.pendown()

cantor(5, 729)

turtle.hideturtle()
turtle.done()
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/Cantor-Dust#main.py](https://replit.com/@damiankurpiewski/Cantor-Dust#main.py)
