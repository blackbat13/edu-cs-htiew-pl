# Krzywa Kocha

## [:link: Opis problemu](../../../../algorithms/fractals/koch-curve.md)

## Implementacja

```python linenums="1"
import turtle

def koch_curve(rank, length):
    if rank > 0:
        koch_curve(rank - 1, length / 2)
        turtle.left(60)
        koch_curve(rank - 1, length / 2)
        turtle.right(120)
        koch_curve(rank - 1, length / 2)
        turtle.left(60)
        koch_curve(rank - 1, length / 2)
    else:
        turtle.forward(length)

turtle.speed(0)
turtle.penup()
turtle.back(350)
turtle.pendown()

koch_curve(3, 200)

turtle.done()
```

### Link do implementacji

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=pZDLDoIwEEV_ZdLVkKDyiC668EtIDLbDI9SWlAIL479rFQPqTmY3d-6cO5krGxiPQyaMJMZZfWmNdeB66xRlOtOSCmiMqE6itwOhzXUTgiJduirgmYZH1QV4GY4QTYqvryXYQPxehB0kwex8hW0VFQ4PUbACYeuychgnqyD_3kGqI_5DK4wdcytxepl_6TTpWiKJPmcSWtJ9i3N_zkWD6f7TIc2o8YlZXJWGkETREi6NJm9jtzs)
