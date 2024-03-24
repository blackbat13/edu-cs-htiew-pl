# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **abs, fabs**

### Specyfikacja

#### Dane

* $$a$$ - liczba całkowita

#### Wynik

* Wartość bezwzględna z $$a$$

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a;
    
    cout << "Podaj liczbe:" << endl;
    cin >> a;
    
    if(a < 0) {
        cout << "|" << a << "| = " << -a << endl;
    } else {
        cout << "|" << a << "| = " << a << endl;
    }
    
    return 0;
}
```
