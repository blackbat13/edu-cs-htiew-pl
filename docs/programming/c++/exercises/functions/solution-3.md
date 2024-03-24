# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Obliczenie i wypisywanie dzielników powinno być zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Wszystkie dzielniki liczby $$n$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

void dzielniki(int n) {
    cout << "Dzielniki liczby " << n << endl;

    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    int n;
    
    cout << "Podaj liczbe naturalna:" << endl;
    cin >> n;
    
    dzielniki(n);
    
    return 0;
}
```
