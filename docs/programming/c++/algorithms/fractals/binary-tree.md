# Drzewo binarne

## Opis problemu

{% content-ref url="../../../../algorithms/fractals/binary-tree.md" %}
[binary-tree.md](../../../../algorithms/fractals/binary-tree.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include "turtle.hpp"

const int SIZE = 900;

Turtle turtle(SIZE, SIZE);

void binaryTree(int rank, int length) {
    turtle.forward(length);
    
    if (rank > 0) {
        turtle.turnLeft(45);
        binaryTree(rank - 1, length / 2);
        turtle.turnRight(90);
        binaryTree(rank - 1, length / 2);
        turtle.turnLeft(45);
    }
        
    turtle.backward(length);
}

int main() {
    turtle.penUp();
    turtle.goTo(0, -SIZE / 2);
    turtle.turnLeft(90);
    turtle.penDown();

    binaryTree(6, SIZE / 2);
    
    turtle.saveBMP("drzewo_binarne.bmp");

    return 0;
} 
```
{% endcode %}

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/DrzewoBinarne#main.cpp" %}
Drzewo binarne
{% endembed %}

### Opis implementacji

Funkcja `binaryTree` (**linia 7**) przyjmuje dwa argumenty: stopień drzewa i początkową długość gałęzi (pnia). Na początku przemieszczamy żółwia do przodu o zadaną długość (**linia 8**), rysując w ten sposób gałąź. Następnie, jeżeli stopień jest większy od zera (**linia 10**), to znaczy, że musimy narysować kolejne gałęzie. W tym celu obracamy najpierw żółwia w lewo o $$45\degree$$ (**linia 11**) i wywołaniem rekurencyjnym (**linia 12**) rysujemy gałęzie. Podobnie postępujemy z drugim rozgałęzieniem. Najpierw musimy obrócić żółwia w prawo o $$90\degree$$ (**linia 13**), czyli $$2*45\degree$$. Następnie stosujemy wywołanie rekurencyjne (**linia 14**), a potem obracamy żółwia w lewo o $$45\degree$$ (**linia 15**), w ten sposób wracając do początkowego ustawienia.

Na koniec, po ewentualnym narysowaniu rozgałęzień, cofamy żółwia o zadaną długość (**linia 18**), tym samym wracając do ustawienia z początku wywołania funkcji.