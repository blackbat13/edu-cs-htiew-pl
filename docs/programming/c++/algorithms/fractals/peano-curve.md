# Krzywa Peano

## [:link: Opis problemu](../../../../algorithms/fractals/peano-curve.md)

## Implementacja

```cpp linenums="1"
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void peanoCurve(int rank, int angle, int length) {
    if (rank > 0) {
        turtle.turnRight(angle);
        peanoCurve(rank - 1, -angle, length);
        turtle.forward(length);
        peanoCurve(rank - 1, angle, length);
        turtle.forward(length);
        peanoCurve(rank - 1, -angle, length);
        turtle.turnLeft(angle);
    }
}

int main() {
    peanoCurve(5, 90, 10);
    
    turtle.saveBMP("krzywa_peano.bmp");

    return 0;
} 
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/PeanoCurve#main.cpp](https://replit.com/@damiankurpiewski/PeanoCurve#main.cpp)
