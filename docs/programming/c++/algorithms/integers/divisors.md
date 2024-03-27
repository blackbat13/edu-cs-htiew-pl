# Wszystkie dzielniki

## [Opis problemu](../../../../algorithms/integers/divisors.md)

## Rozwiązanie zupełnie naiwne

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void divisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }
}

int main() {
    int n = 12;
    
    divisors(n);
    
    return 0;
}
```

### Opis implementacji

Funkcja `divisors` (**linia 5**) wypisuje wszystkie dzielniki liczby podanej jako parametr. Na początku przechodzimy pętlą przez wszystkie potencjalne dzielniki od $1$ do $n$ włącznie (**linia 6**). W pętli sprawdzamy, czy reszta z dzielenia liczby $n$ przez licznik pętli wynosi $0$ (**linia 7**), czyli czy $n$ jest podzielne przez sprawdzaną wartość. Jeżeli tak jest, to znaleźliśmy dzielnik, więc go wypisujemy (**linia 8**).

W części głównej programu najpierw definiujemy dane wejściowe (**linia 14**), a następnie wywołujemy funkcję `divisors` (**linia 16**) i kończymy działanie programu (**linia 18**).

## Rozwiązanie naiwne

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void divisors(int n) {
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            cout << i << endl;
        }
    }
    
    if (n > 1) {
        cout << n << endl;
    }
}

int main() {
    int n = 12;
    
    divisors(n);
    
    return 0;
}
```

### Opis implementacji

Funkcja `divisors` (**linia 5**) wypisuje wszystkie dzielniki liczby podanej jako parametr. Na początku przechodzimy pętlą przez wszystkie potencjalne dzielniki od $1$ do $\lfloor n/2\rfloor$ włącznie (**linia 6**). W pętli sprawdzamy, czy reszta z dzielenia liczby $n$ przez licznik pętli wynosi $0$ (**linia 7**), czyli czy $n$ jest podzielne przez sprawdzaną wartość. Jeżeli tak jest, to znaleźliśmy dzielnik, więc go wypisujemy (**linia 8**). Po wyjściu z pętli musimy jeszcze sprawdzić, czy $n$ jest większe od $1$ (**linia 12**). Jeżeli tak jest, to musimy wypisać jeszcze jeden dzielnik: $n$ (**linia 13**).

W części głównej programu najpierw definiujemy dane wejściowe (**linia 18**), a następnie wywołujemy funkcję `divisors` (**linia 20**) i kończymy działanie programu (**linia 22**).

## Rozwiązanie optymalne

### Implementacja

```cpp linenums="1"
#include <iostream>
#include <cmath>

using namespace std;

void divisors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << endl;
            if (i != n / i) {
                cout << n / i << endl;
            }
        }
    }
}

int main() {
    int n = 12;
    
    divisors(n);
    
    return 0;
}
```

### Opis implementacji

Funkcja `divisors` (**linia 6**) wypisuje wszystkie dzielniki liczby podanej jako parametr. Na początku przechodzimy pętlą przez wszystkie potencjalne dzielniki od $1$ do $\sqrt{n}$ włącznie (**linia 7**). W pętli sprawdzamy, czy reszta z dzielenia liczby $n$ przez licznik pętli wynosi $0$ (**linia 8**), czyli czy $n$ jest podzielne przez sprawdzaną wartość. Jeżeli tak jest, to znaleźliśmy dzielnik, więc go wypisujemy (**linia 9**). Po znalezieniu dzielnika musimy jeszcze sprawdzić, czy drugi dzielnik z "pary" jest różny od obecnego (**linia 10**). Jeżeli tak, to go też wypisujemy (**linia 11**).

W części głównej programu najpierw definiujemy dane wejściowe (**linia 18**), a następnie wywołujemy funkcję `divisors` (**linia 20**) i kończymy działanie programu (**linia 22**).
