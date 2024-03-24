# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **min, max**.

### Specyfikacja

#### Dane

* $$a, b, c$$ - trzy liczby całkowite

#### Wynik

* Największa z liczb $$a$$, $$b$$ i $$c$$ , lub dowolna gdy są sobie równe

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b, c, maks;
    
    cout << "Podaj trzy liczby:" << endl;
    cin >> a >> b >> c;
    
    if (a >= b && a >= c) {
        maks = a;
    } else if (b >= a && b >= c) {
        maks = b;
    } else {
        maks = c;
    }
    
    cout << "Maksimum: " << maks << endl;
    
    return 0;
}
```
