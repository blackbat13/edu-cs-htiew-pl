# Krzywa Peano

## Opis problemu

{% content-ref url="../../../../algorithms/fractals/peano-curve.md" %}
[peano-curve.md](../../../../algorithms/fractals/peano-curve.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
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
{% endcode %}

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Peano-Curve#main.py" %}
