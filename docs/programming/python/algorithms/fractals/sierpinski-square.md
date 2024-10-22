# Kwadrat Sierpińskiego

## [:link: Opis problemu](../../../../algorithms/fractals/sierpinski-square.md)

## Implementacja

```python linenums="1"
import turtle

def sierpinski_square(rank, length):
    if rank == 0:
        turtle.begin_fill()
        for _ in range(4):
            turtle.forward(length)
            turtle.left(90)
        turtle.end_fill()
        return

    for _ in range(4):
        for _ in range(2):
            turtle.forward(length / 3)
            sierpinski_square(rank - 1, length / 3)
        turtle.forward(length / 3)
        turtle.left(90)

turtle.color('blue')
turtle.speed(0)
turtle.penup()
turtle.back(200)
turtle.pendown()

sierpinski_square(3, 300)

turtle.done()
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/Sierpinski-Square#main.py](https://replit.com/@damiankurpiewski/Sierpinski-Square#main.py)
