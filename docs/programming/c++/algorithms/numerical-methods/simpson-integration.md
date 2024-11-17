# Metoda Simpsona

## [:link: Opis problemu](../../../../algorithms/numerical-methods/simpson-integration.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

double f(double x) {
    return x * x + 2 * x;
}

double simpsonMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * f(a + i * h);
    }

    return (h / 3) * sum;
}

int main() {
    double a = 1;
    double b = 5;
    int n = 100;

    double area = simpsonMethod(a, b, n);

    cout << area << endl;

    return 0;
}
```

### Opis implementacji

Funkcja `f` (**linia 5**) przyjmuje jeden parametr rzeczywisty i jako wynik zwraca liczbę rzeczywistą. Funkcja ta symuluje funkcję matematyczną, której pole pod wykresem chcemy policzyć. 

Funkcja `simpsonMethod` (**linia 9**) realizuje algorytm całkowania numerycznego metodą Simpsona i przyjmuje trzy parametry: początek przedziału (`a`), koniec przedziału (`b`) oraz liczbę podziałów (`n`). Funkcja jako wynik zwraca liczbę rzeczywistą reprezentującą przybliżenie pola pod wykresem funkcji $f(x)=x^2+2x$ na przedziale $[a, b]$.

W części głównej programu przygotowujemy dane do naszego algorytmu: początek przedziału (**linia 25**), koniec przedziału (**linia 26**) oraz liczbę podziałów (**linia 27**). Następnie wywołujemy funkcję `simpsonMethod` z przygotowanymi danymi, a jej wynik zapisujemy w zmiennej `area` (**linia 29**). Na koniec wypisujemy wynik na ekranie (**linia 31**) oraz kończymy działanie programu (**linia 33**).
