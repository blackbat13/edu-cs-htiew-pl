# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* $$n!$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, silnia;
    
    silnia = 1;
    
    cout << "Podaj liczbe:" << endl;
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        silnia *= i;
    }
    
    cout << n << "! = " << silnia << endl;
    
    return 0;
}
```
