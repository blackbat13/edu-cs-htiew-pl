# Krzywa Kocha

## Opis problemu

{% content-ref url="../../../../algorithms/fractals/koch-curve.md" %}
[koch-curve.md](../../../../algorithms/fractals/koch-curve.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
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
{% endcode %}

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/KochCurve#main.cpp" %}
