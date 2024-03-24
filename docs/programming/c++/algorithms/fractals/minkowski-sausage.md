# Minkowski Sausage

## Opis problemu

{% content-ref url="../../../../algorithms/fractals/minkowski-sausage.md" %}
[minkowski-sausage.md](../../../../algorithms/fractals/minkowski-sausage.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
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
{% endcode %}

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/MinkowskiCurve#main.cpp" %}
