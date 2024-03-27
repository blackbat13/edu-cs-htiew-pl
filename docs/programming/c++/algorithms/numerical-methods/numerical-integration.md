# Całkowanie numeryczne

## [Opis problemu](../../../../algorithms/numerical-methods/numerical-integration.md)

## Metoda prostokątów

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

double f(double x) {
    return x * x + 2 * x;
}

double rectanglesMethod(int a, int b, int n) {
    double width = (b - a) / (double)n;
    double area = 0;
    double currentPoint = a;
    double height;

    for(int i = 0; i < n; i++) {
        currentPoint += width;
        height = f(currentPoint);
        area += height * width;
    }

    return area;
}

int main() {
    int a = 1;
    int b = 5;
    int n = 100;

    double area = rectanglesMethod(a, b, n);

    cout << area << endl;

    return 0;
}
```

### Opis implementacji

Funkcja `f` (**linia 5**) przyjmuje jeden parametr rzeczywisty i jako wynik zwraca liczbę rzeczywistą. Funkcja ta symuluje funkcję matematyczną, której pole pod wykresem chcemy policzyć. 

Funkcja `rectanglesMethod` (**linia 9**) realizuje algorytm całkowania numerycznego metodą prostokątów i przyjmuje trzy parametry: początek przedziału (`a`), koniec przedziału (`b`) oraz liczbę prostokątów (`n`). Funkcja jako wynik zwraca liczbę rzeczywistą reprezentującą przybliżenie pola pod wykresem funkcji $f(x)=x^2+2x$ na przedziale $<a, b>$. Wewnątrz funkcji zaczynamy od policzenia szerokości jednego prostokąta, dzieląc długość przedziału przez liczbę prostokątów (**linia 10**). Następnie tworzymy zmienną do zapamiętania obliczanego pola (**linia 11**) oraz zmienną do zapamiętania obecnej pozycji na osi $x$ (**linia 12**), a także zmienną do zapamiętywania obliczanych wysokości prostokątów (**linia 13**). W następnej kolejności przechodzimy pętlą $n$ razy (**linia 15**). Wewnątrz pętli przesuwamy obecną pozycję na osi $x$ w prawo o szerokość jednego prostokąta (**linia 16**). Następnie obliczamy wysokość prostokąta w obecnym punkcie poprzez obliczenie wartości funkcji w tym miejscu (**linia 17**). Obliczoną wysokość wykorzystujemy do policzenia pola obecnego prostokąta i dodania go do zliczanego pola pod wykresem funkcji (**linia 18**). Na koniec funkcji, po wyjściu z pętli, zwracamy obliczone pole pod wykresem funkcji (**linia 21**).

W części głównej programu przygotowujemy dane do naszego algorytmu: początek przedziału (**linia 25**), koniec przedziału (**linia 26**) oraz liczbę prostokątów (**linia 27**). Następnie wywołujemy funkcję `rectanglesMethod` z przygotowanymi danymi, a jej wynik zapisujemy w zmiennej `area` (**linia 29**). Na koniec wypisujemy wynik na ekranie (**linia 31**) oraz kończymy działanie programu (**linia 33**).

## Metoda trapezów

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

double f(double x) {
    return x * x + 2 * x;
}

double trapezesMethod(int a, int b, int n) {
    double height = (b - a)/(double)n;
    double area = 0;
    double currentPoint = a;
    double side1, side2;

    for(int i = 0; i < n; i++) {
        side1 = f(currentPoint);
        currentPoint += height;
        side2 = f(currentPoint);
        area += ((side1 + side2) * height) / 2.0;
    }

    return area;
}

int main() {
    int a = 1;
    int b = 5;
    int n = 100;

    double area = trapezesMethod(a, b, n);

    cout << area << endl;

    return 0;
}
```

### Opis implementacji

Funkcja `f` (**linia 5**) przyjmuje jeden parametr rzeczywisty i jako wynik zwraca liczbę rzeczywistą. Funkcja ta symuluje funkcję matematyczną, której pole pod wykresem chcemy policzyć. 

Funkcja `trapezesMethod` (**linia 9**) realizuje algorytm całkowania numerycznego metodą trapezów i przyjmuje trzy parametry: początek przedziału (`a`), koniec przedziału (`b`) oraz liczbę trapezów (`n`). Funkcja jako wynik zwraca liczbę rzeczywistą reprezentującą przybliżenie pola pod wykresem funkcji $f(x)=x^2+2x$ na przedziale $<a, b>$. Wewnątrz funkcji zaczynamy od policzenia wysokości jednego trapezu, dzieląc długość przedziału przez liczbę trapezów (**linia 10**). Następnie tworzymy zmienną do zapamiętania obliczanego pola (**linia 11**) oraz zmienną do zapamiętania obecnej pozycji na osi $x$ (**linia 12**), a także zmienne do pamiętania długości podstaw tworzonych trapezów (**linia 13**). W następnej kolejności przechodzimy pętlą $n$ razy (**linia 15**). Wewnątrz pętli obliczamy długość pierwszej podstawy trapezu (**linia 16**), a następnie przesuwamy obecną pozycję na osi $x$ w prawo o wysokość jednego trapezu (**linia 17**). Następnie obliczamy długość drugiej podstawy trapezu w obecnym punkcie poprzez obliczenie wartości funkcji w tym miejscu (**linia 18**). Obliczone długości podstaw wykorzystujemy do policzenia pola obecnego trapezu i dodania go do zliczanego pola pod wykresem funkcji (**linia 19**). Na koniec funkcji, po wyjściu z pętli, zwracamy obliczone pole pod wykresem funkcji (**linia 22**).

W części głównej programu przygotowujemy dane do naszego algorytmu: początek przedziału (**linia 26**), koniec przedziału (**linia 27**) oraz liczbę prostokątów (**linia 28**). Następnie wywołujemy funkcję `trapezesMethod` z przygotowanymi danymi, a jej wynik zapisujemy w zmiennej `area` (**linia 30**). Na koniec wypisujemy wynik na ekranie (**linia 32**) oraz kończymy działanie programu (**linia 34**).
