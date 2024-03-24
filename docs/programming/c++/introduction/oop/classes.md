# Klasy

## Wstęp

W języku C++ definicję klasy zaczynamy od słowa kluczowego ``class``.
W klasach, w przeciwieństwie do struktur, domyślnym modyfikatorem dostępu jest ``private``.
Jak i w innych językach klasy mogą mieć swoje atrybuty i metody.
Omówimy działanie klas na konkretnym przykładzie.

## Przykład 1: Punkt2D

Stwórzmy klasę reprezentującą dwuwymiarowy punkt.
Nazwiemy ją **Point2D**.
Nasza klasa będzie miała dwa atrybuty: współrzędne $$x$$ i $$y$$.

### Implementacja

```cpp
#include <iostream>
#include <cmath>

using namespace std;

class Point2D {
  double x, y;

  public:
    Point2D() {
      this->x = 0;
      this->y = 0;
    }

    Point2D(double x, double y) {
      this->x = x;
      this->y = y;
    }

    double getX() {
      return this->x;
    }

    void setX(double val) {
      this-> x = val;
    }

    double getY() {
      return this->y;
    }

    void setY(double val) {
      this->y = val;
    }

    void translate(Point2D translation) {
      this->x += translation.x;
      this->y += translation.y;
    }

    void rotate(double angle) {
      double newX = this->x * cos(angle) - this->y * sin(angle);
      double newY = this->x * sin(angle) + this->y * cos(angle);
      this->x = newX;
      this->y = newY;
    }

    void scale(double sc) {
      this->x *= sc;
      this->y *= sc;
    }

    void print() {
      cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};

int main() {
  Point2D point = Point2D(3, 4);

  point.print();

  point.translate(Point2D(1, 1));

  point.print();

  point.scale(2);

  point.print();

  point.rotate(M_PI / 2);

  point.print();

  return 0;
}
```

## Przykład 2: podział na pliki

Gdy nasza klasa będzie obrastać w nowe funkcjonalności i metody, z czasem może stać się mało czytelna.
Dlatego dobrym pomysłem jest oddzielić deklarację klasy od jej implementacji.
W ten sposób uzyskujemy dwa pliki: plik nagłówkowy z rozszerzeniem **.h** oraz plik z implementacją z rozszerzeniem **.cpp**.
W pliku nagłówkowym zawieramy jedynie deklaracje atrybutów i metod klasy, unikamy dodawania ich implementacji.
Na implementację metod naszej klasy przeznaczony jest osobny plik.

### Point2D.h

```cpp
#ifndef POINT2D_H
#define POINT2D_H

#include <cmath>
#include <iostream>

class Point2D {
  double x, y;

  public:
    Point2D();

    Point2D(double x, double y);

    double getX();

    void setX(double val);

    double getY();

    void setY(double val);

    void translate(Point2D translation);

    void rotate(double angle);

    void scale(double sc);

    void print();
};

#endif //POINT2D_H
```

### Point2D.cpp

```cpp
#include "Point2D.h"


Point2D::Point2D() {
  this->x = 0;
  this->y = 0;
}

Point2D::Point2D(double x, double y) {
  this->x = x;
  this->y = y;
}

double Point2D::getX() {
  return this->x;
}

void Point2D::setX(double val) {
  this-> x = val;
}

double Point2D::getY() {
  return this->y;
}

void Point2D::setY(double val) {
  this->y = val;
}

void Point2D::translate(Point2D translation) {
  this->x += translation.x;
  this->y += translation.y;
}

void Point2D::rotate(double angle) {
  double newX = this->x * cos(angle) - this->y * sin(angle);
  double newY = this->x * sin(angle) + this->y * cos(angle);
  this->x = newX;
  this->y = newY;
}

void Point2D::scale(double sc) {
  this->x *= sc;
  this->y *= sc;
}

void Point2D::print() {
  std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
}

```

### main.cpp

```cpp
#include "Point2D.h"

int main() {
  Point2D point = Point2D(3, 4);

  point.print();

  point.translate(Point2D(1, 1));

  point.print();

  point.scale(2);

  point.print();

  point.rotate(M_PI / 2);

  point.print();

  return 0;
}
```

### Kompilacja

```
g++ -o main Point2D.cpp main.cpp
```