# Zbiór Cantora

## [:link: Opis problemu](../../../../algorithms/fractals/cantor-dust.md)

## Implementacja

```cpp linenums="1"
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void cantorDust(int rank, int length) {
    if (rank > 0) {
        cantorDust(rank - 1, length / 3);
        turtle.penUp();
        turtle.forward(length / 3);
        turtle.penDown();
        cantorDust(rank - 1, length / 3);
    } else {
        turtle.forward(length);
    }
}

void cantor(int rank, int length){
    for (int i = 0; i <= rank; i++) {
        cantorDust(i, length);
        turtle.penUp();
        turtle.backward(length);
        turtle.turnRight(90);
        turtle.forward(20);
        turtle.turnLeft(90);
        turtle.penDown();
    }
}

int main() {
    turtle.penUp();
    turtle.goTo(-SIZE / 2, 0);
    turtle.penDown();

    cantor(5, 729);
    
    turtle.saveBMP("zbior_cantora.bmp");

    return 0;
} 
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/CantorDust#main.cpp](https://replit.com/@damiankurpiewski/CantorDust#main.cpp)
