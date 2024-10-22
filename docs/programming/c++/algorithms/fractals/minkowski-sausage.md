# Minkowski Sausage

## [:link: Opis problemu](../../../../algorithms/fractals/minkowski-sausage.md)

## Implementacja

```cpp linenums="1"
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void minkowskiCurve(int rank, int length) {
    if (rank > 0) {
        turtle.turnRight(30);
        minkowskiCurve(rank - 1, length / 2);
        turtle.turnLeft(90);
        minkowskiCurve(rank - 1, length / 2);
        turtle.turnRight(90);
        minkowskiCurve(rank - 1, length / 2);
        turtle.turnLeft(30);
    }
    else {
        turtle.forward(length);
    }
}

void minkowskiSausage(int rank, int length) {
    for(int i = 0; i < 4; i++) {
        minkowskiCurve(rank, length);
        turtle.turnRight(90);
    }
}

int main() {
    minkowskiSausage(5, 200);
    
    turtle.saveBMP("minkowski_sausage.bmp");

    return 0;
} 
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/MinkowskiCurve#main.cpp](https://replit.com/@damiankurpiewski/MinkowskiCurve#main.cpp)
