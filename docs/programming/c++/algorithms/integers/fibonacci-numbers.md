# Liczby Fibonacciego

## [Opis problemu](../../../../algorithms/integers/fibonacci-numbers.md)

## Podejście rekurencyjne

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 10;

    int result = fib(n);

    cout << "fib(" << n << ") = " << result << endl;

    return 0;
}
```

### Opis implementacji

Funkcja `fib` (**linia 5**) przyjmuje jeden parametr: liczbę całkowitą oznaczającą numer wartości ciągu Fibonacciego do policzenia. Na początku funkcji sprawdzamy warunek stopu rekurencji (**linia 6**). Jeżeli jest spełniony to jako wynik zwracamy wartość $1$ (**linia 7**). Jeżeli warunek stopu nie był spełniony to jako wynik zwracamy sumę wyników wywołań rekurencyjnych funkcji `fib` dla dwóch poprzednich elementów ciągu (**linia 10**).

W części głównej najpierw przygotowujemy dane wejściowe, czyli numer wartości ciągu Fibonacciego do obliczenia (**linia 14**). Następnie obliczamy ustalony element ciągu za pomocą funkcji `fib` (**linia 16**), a na koniec wypisujemy wynik na ekranie (**linia 18**) i kończymy działanie programu (**linia 20**).

## Podejście iteracyjne

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int fib(int n) {
    if (n <= 2) {
        return 1;
    }

    int f1 = 1, f2 = 1;
    
    for (int i = 3; i <= n; i++) {
        int f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    return f2;
}

int main() {
    int n = 10;

    int result = fib(n);

    cout << "fib(" << n << ") = " << result << endl;

    return 0;
}
```
