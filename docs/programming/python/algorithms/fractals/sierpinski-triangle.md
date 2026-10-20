# Trójkąt Sierpińskiego

## [:link: Opis problemu](../../../../algorithms/fractals/sierpinski-triangle.md)

## Implementacja

```python linenums="1"
import turtle

def sierpinski_triangle(rank, length):
    if rank == 0:
        turtle.begin_fill()
        for _ in range(3):
            turtle.forward(length)
            turtle.left(120)
        turtle.end_fill()
        return

    for _ in range(3):
        sierpinski_triangle(rank - 1, length / 2)
        turtle.forward(length)
        turtle.left(120)

turtle.speed(0)
turtle.penup()
turtle.back(200)
turtle.pendown()

sierpinski_triangle(4, 300)

turtle.done()
```

### Link do implementacji

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=hVBBjsIwDPyKlZMrlaUtnCrxk0pVIU7XataJ0gAHxN9p2K4AFbS-eTzjGfuiTqouc3VwmlSt-Me7ECEeQ7TUSCOaDIxMwbOMA7cxcCe9JQydDDlYkj5-Z3UjMBUbSDDsdlDMUKrfZV976llaw9Zi9hgaF6AFlqTsCTfZk_BJPNHOXdA4G77lWDIRy6rIFtYkemEcaBpKOvG_GJ_OhxWUfy-ANVRL34-pl4kbmbHRE2lM0Ax4kqPHR7_vDgNWxStDu7Pgfc27tNscNsWLi3ZCia-uNw)
