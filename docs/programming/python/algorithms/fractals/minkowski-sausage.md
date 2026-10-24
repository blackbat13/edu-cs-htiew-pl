# Minkowski Sausage

## [:link: Opis problemu](../../../../algorithms/fractals/minkowski-sausage.md)

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

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=rZDNDoIwEIRfZdNTSVDBn4McfBISU-kCDbglbYGD8d2lihqD4aJ763T7dWYurGNJHLJMS2QJU-dGGweuNa7GlFKSmMNZUaV7W6lj1poOuRFUhVAjFa4MkpRgGJWDl-EA0aj4eXCWRhWl45soeN98Y8IC4icXVrAOJqAac8f3v3MehvZ_MvQKhrXFafpcm14YycfCpq1a0VpRfO91eAwKFPl2h5UohG2QzLt-IeZipzRqtkGU3Euj0CC1DX-fTyKreLz73JC6J37HTGNsQoijjz-kJvTb7HoD)
