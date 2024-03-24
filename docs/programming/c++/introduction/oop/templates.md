# Szablony

## Wstęp

Szablony pozwalają pisać kod, który jest niezależny od konkretnego typu.
Normalnie, jak tworzymy funkcję, to musimy ustalić typ jej parametrów i typ zwracanej wartości.
Często jednak jest tak, że chcielibyśmy, żeby funkcja działała na różnych typach.
Dla przykładu rozważmy dodawanie do siebie dwóch liczb.
Implementacja ciała takiej funkcji będzie wyglądała tak samo, bez względu na to, czy parametry będą typu `int`, `double`, `float`, czy też innego typu liczbowego.
Różnica będzie tkwić jedynie w typach parametrów i typie zwracanej wartości.
W takim przypadku możemy skorzystać z szablonów, zamiast pisać wiele podobnych funkcji.
Z szablonów możemy korzystać także przy tworzeniu klas.

## Szablony funkcji

Tworzenie szablonu funkcji jest stosunkowo proste.
Wystarczy skorzystać ze słowa kluczowego `template`, a następnie zdefiniować własną nazwę typu szablonu `typename` lub `class`.
Zarówno `typename` jak i `class` działają tak samo.
Zobaczmy jak to wygląda na poniższym przykładzie.

### Przykład

Napiszemy szablon funkcji dodającej do siebie dwie wartości.

#### Funkcja
```cpp
template <typename T>
T sum(T a, T b) {
  return a + b;
}
```

#### Wywołanie
```cpp
double d1 = 9.3, d2 = 1.2;
float f1 = 54.3, f2 = 3.6;
int i1 = 1, i2 = 2;

cout << sum(d1, d2) << endl;
cout << sum(f1, f2) << endl;
cout << sum(i1, i2) << endl;
```

Aby się upewnić, że typy zwracanych wartości są prawidłowe, możemy skorzystać z operatora `typeid` z biblioteki `typeinfo`:

```cpp
cout << typeid(sum(d1, d2)).name() << endl;
cout << typeid(sum(f1, f2)).name() << endl;
cout << typeid(sum(i1, i2)).name() << endl;
```

#### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/SumTemplate#main.cpp" %}
Szablon funkcji
{% endembed %}

## Szablony klas

Szablony klas wyglądają podobnie do szablonów funkcji.

### Przykład

```cpp
#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Point2D {
  T x, y;

  public:
    Point2D() {
      this->x = 0;
      this->y = 0;
    }

    Point2D(T x, T y) {
      this->x = x;
      this->y = y;
    }

    T getX() {
      return this->x;
    }

    void setX(T val) {
      this-> x = val;
    }

    T getY() {
      return this->y;
    }

    void setY(T val) {
      this->y = val;
    }

    void translate(Point2D translation) {
      this->x += translation.x;
      this->y += translation.y;
    }

    void rotate(T angle) {
      T newX = this->x * cos(angle) - this->y * sin(angle);
      T newY = this->x * sin(angle) + this->y * cos(angle);
      this->x = newX;
      this->y = newY;
    }

    void scale(T sc) {
      this->x *= sc;
      this->y *= sc;
    }

    void print() {
      cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};

int main() {
  Point2D<int> pointInt = Point2D<int>(2, 5);
  Point2D<double> pointDouble = Point2D<double>(4.5, 1.3);

  pointInt.print();

  pointDouble.print();

  return 0;
}
```