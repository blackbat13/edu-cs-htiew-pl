# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **min, max**.

### Specyfikacja

#### Dane

* $$a, b, c, d$$ - cztery liczby całkowite

#### Wynik

* Największa z liczb $$a, b, c$$ i $$d$$, lub dowolna gdy są sobie równe

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, maks;
    
    cout << "Podaj cztery liczby:" << endl;
    cin >> a >> b >> c >> d;
    
    if (a >= b && a >= c && a >= d) {
        maks = a;
    } else if (b >= a && b >= c && b >= d) {
        maks = b;
    } else if (c >= a && c >= b && c >= d) {
        maks = c;
    } else {
        maks = d;
    }
    
    cout << "Maksimum: " << maks << endl;
    
    return 0;
}
```
