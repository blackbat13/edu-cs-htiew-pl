# Przeciążanie operatorów

## Wstęp

Na nowo zdefiniowanych własnych typach przeprowadzamy różne operacje.
Często są to także standardowe operacje arytmetyczne, jak np. dodanie do siebie współrzędnych dwóch punktów.
W takich sytuacjach wygodniej jest korzystać z predefiniowanych operatorów, takich jak operator dodawania $$+$$ zamiast z metod typu ``add``.

Wyobraźmy sobie, że mamy dwie zmienne (obiekty) reprezentujące punkty: ``p1`` oraz ``p2``. 
Chcemy dodać współrzędne jednego punktu do drugiego i wynik zapisać w zmiennej ``p1``.
Zazwyczaj zapisalibyśmy coś w stylu ``p1.Add(p2)``.
Używając jednak **przeciążenia operatorów** możemy zapisać ``p1 = p1 + p2``.

### Dokumentacja

{% embed url="https://en.cppreference.com/w/cpp/language/operators" %}
operatory - dokumentacja
{% endembed %}

## Przykład: dodawanie punktów

Operator dodawania $$+$$ jest jednym ze standardowych operatorów **dwuargumentowych**.
Oznacza to, że działa na dwóch argumentach, a jego wynikiem jest nowa wartość.
**Przeciążając ten operator nie powinniśmy modyfikować obecnego obiektu, ale utworzyć nowy i zwrócić go jako wynik.**

### Point2D

```cpp
Point2D operator+(const Point2D &other) {
  return Point2D(this->x + other.x, this->y + other.y);
}
```

### main

```cpp
Point2D p1 = Point2D(3, 4);
Point2D p2 = Point2D(1, 9);

auto p3 = p1 + p2;

p3.print();
```

## Przykład: wypisanie punktu

Możemy przeciążać nie tylko operatory arytmetyczne, ale także operatory strumieniowe.
W ten sposób możemy sami zdefiniować, w jaki sposób nasz obiekt ma zostać wypisany, lub wczytany.

W przeciwieństwie do operatorów arytmetycznych, ten nie jest definiowany jako część implementacji klasy, ale jako funkcja **zaprzyjaźniona** (ang. __friend__).

### Point2D

```cpp
std::ostream& operator<<(std::ostream &out, const Point2D &point)
{
    out << "(" << point.x << "," << point.y << ")";
    return out;
}
```

### main
```cpp
std::cout << p3 << std::endl;
```

## Przykład: wczytanie punktu

Przeciążanie operatora strumieniowego wejścia wygląda podobnie, jak przy operatorze wejścia.

### Point2D

```cpp
std::istream& operator>>(std::istream &in, Point2D &point)
{
    in >> point.x >> point.y;
    return in;
}
```

### main
```cpp
std::cin >> p3;
```

## Przykład: operator indeksowania

Możemy także przeciążyć operator indeksowania, czy też operator nawiasów kwadratowych **[]**.
Jest to szczególnie przydatne, gdy tworzymy własną implementację jakiegoś zbioru.

### Point2D

```cpp
double Point2D::operator[](int index) {
  if(index == 0) {
    return this->x;
  } else if(index == 1) {
    return this->y;
  } else {
    throw std::out_of_range("Index should be 0 or 1");
  }
}
```

### main

```cpp
  std::cout << point3[0] << std::endl;

  std::cout << point3[2] << std::endl;
```

Próba wypisania wartości pod indeksem $$2$$ zakończy się błędem.