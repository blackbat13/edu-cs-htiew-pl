# Płatek Kocha

## [:link: Opis problemu](../../../../algorithms/fractals/koch-snowflake.md)

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

def koch_snowflake(rank, length):
    for i in range(0, 3):
        koch_curve(rank, length)
        turtle.right(120)

turtle.speed(0)
turtle.penup()
turtle.back(350)
turtle.pendown()

koch_snowflake(3, 100)

turtle.done()
```

### Link do implementacji

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=pZBBj4IwEIX_yqSnIcEVJO6Bg7-ExCCdQkN3SkqRg_G_axU1uKuHdW7z8t6byXcQe5GnsaisJJEL_dNZ58EPzhsquGBJClpbNdtqcHtCV3IbgyGufRPlBcN5tIIgwwaSSQnzFIIFpLcgLGEVPZzXY1-GlMfvJPqgwum68ZiuPir57x9kesp_tSnrxtJJnJDNkPZsR2XK9m-s5yRo0Bzg1oRJDFn0mu89_RZKwZPYd0QSgzQJHfHQ4WPflVWL2XrukHZkvNQ8_Z_FkCazA9IyBas4ngA)
