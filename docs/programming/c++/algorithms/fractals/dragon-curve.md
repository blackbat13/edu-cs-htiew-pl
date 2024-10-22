# Smocza krzywa

## [:link: Opis problemu](../../../../algorithms/fractals/dragon-curve.md)

## Implementacja

```cpp linenums="1"
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void dragonCurve(int rank, int sign, int length) {
    if (rank > 0) {
        turtle.turnLeft(45 * sign);
        dragonCurve(rank - 1, 1, length);
        turtle.turnRight(90 * sign * -1);
        dragonCurve(rank - 1, -1, length);
        turtle.turnLeft(45 * sign);
    }
    else {
        turtle.forward(length);
    }
}

int main() {
    dragonCurve(12, 1, 5);
    
    turtle.saveBMP("smocza_krzywa.bmp");

    return 0;
} 
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/DragonCurve#main.cpp](https://replit.com/@damiankurpiewski/DragonCurve#main.cpp)
