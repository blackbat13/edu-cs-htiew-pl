# Krzywa Kocha

## [:link: Opis problemu](../../../../algorithms/fractals/koch-curve.md)

## Implementacja

```cpp linenums="1"
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void kochCurve(int rank, int length){
    if (rank > 0) {
        kochCurve(rank - 1, length);
        turtle.turnLeft(60);
        kochCurve(rank - 1, length);
        turtle.turnRight(120);
        kochCurve(rank - 1, length);
        turtle.turnLeft(60);
        kochCurve(rank - 1, length);
    }
    else {
        turtle.forward(length);
    }
}

int main() {
    turtle.penUp();
    turtle.goTo(-SIZE / 2, -SIZE / 2);
    turtle.penDown();

    kochCurve(6, 1);
    
    turtle.saveBMP("krzywa_kocha.bmp");

    return 0;
} 
```

### Link do implementacji

[https://replit.com/@damiankurpiewski/KochCurve#main.cpp](https://replit.com/@damiankurpiewski/KochCurve#main.cpp)
