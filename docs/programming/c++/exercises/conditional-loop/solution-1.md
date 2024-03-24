# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Kolejne cyfry liczby $$n$$, wypisane od końca, tzn. zaczynając od cyfry jedności

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, cyfra;
    
    cout << "Podaj liczbe:" << endl;
    cin >> n;
    
    while (n > 0) {
        cyfra = n % 10;
        cout << cyfra << endl;
        n = n / 10;
    }
    
    return 0;
}
```
