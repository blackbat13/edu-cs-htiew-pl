# Klasy abstrakcyjne

## Wstęp

Klasy abstrakcyjne to konstrukcje, które są przydatne przy tworzeniu zaawansowanych struktur relacji dziedziczenia.
Klasa abstrakcyjna może posłużyć za klasę bazową, która agreguje funkcjonalności spójne dla kas pochodnych.

## Klasy abstrakcyjne

Cechy charakterystyczne klas abstrakcyjnych:

- Nie można tworzyć instancji klas abstrakcyjnych.
- Klasa posiadająca przynajmniej jedną metodę w pełni wirtualną jest klasą abstrakcyjną.

## Metody w pełni wirtualne

Metoda w pełni wirualne definiujemy za pomocą modyfikatora **virtual** oraz przypisana do funkcji wartości 0;

### Przykład

```cpp
virtual void translate(int k) = 0;
```

## Przykład

```cpp
#include <iostream>
using namespace std;

class Point {
    public:

    Point(){};
    virtual void translate(int k) = 0;
};

class Point2D: public Point {
    int x, y;
    public:
    Point2D(int x, int y): x(x), y(y) {}

    void translate(int k) {
        x += k;
        y += k;
    }
};

int main() {
    // Point point; // error
    Point2D point2D(5, 8); // OK
    Point *point; // OK
    // point = new Point(); // error
    point = new Point2D(5, 8); // OK
    point->translate(10);

    return 0;
} 
```