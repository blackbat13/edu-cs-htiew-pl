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

[https://coddy.tech/playground/pl/turtle](https://coddy.tech/playground/pl/turtle#code=jVDRboMwDPwVKy9NJLalZS9D6p8gISAOi8icNIT1Ydq_j2xstFBp9ZvPd76zP9g7K_YZa51CVjDz5l2IEMcQLZZUkkINg8HgDQ29qYbTWAfkoaY-A4vUxVdRlARTGQ0JhuMR5Ayl-ln12GBnqNLGWi6WoXYBKjCUlB3yZ3EhvBBPtHMdFJ8Nb3Is6shfpNg4I6mNb8BpSOm-_1KsZoe7EsIT5KuUt38ID7D__eNKdM_izeklzVDrrAt819gRd-IPHTyi4nIBPNLo-dI3ddvzg7xmKHcm_r18e0SeQS6vnJUjTGz2-QU)
