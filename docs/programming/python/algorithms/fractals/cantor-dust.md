# Zbiór Cantora

## Opis problemu

{% content-ref url="../../../../algorithms/fractals/cantor-dust.md" %}
[cantor-dust.md](../../../../algorithms/fractals/cantor-dust.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
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
{% endcode %}

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Cantor-Dust#main.py" %}
