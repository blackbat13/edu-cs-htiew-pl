# Kwadrat Sierpińskiego

## [:link: Opis problemu](../../../../algorithms/fractals/sierpinski-square.md)

## Implementacja

```cpp linenums="1"
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void sierpinskiSquare(int rank, int length) {
    if (rank == 0) {
        turtle.beginFill();
        for(int i = 0; i < 4; i++) {
            turtle.forward(length);
            turtle.turnLeft(90);
        }

        turtle.endFill();
        return;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            turtle.forward(length / 3);
            sierpinskiSquare(rank - 1, length / 3);
        }

        turtle.forward(length / 3);
        turtle.turnLeft(90);
    }
}

int main() {
    turtle.penUp();
    turtle.goTo(-SIZE / 2, -SIZE / 2);
    turtle.penDown();

    sierpinskiSquare(5, SIZE);
    
    turtle.saveBMP("kwadrat_sierpinskiego.bmp");

    return 0;
} 
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/SierpinskiSquare#main.cpp](https://replit.com/@damiankurpiewski/SierpinskiSquare#main.cpp)
