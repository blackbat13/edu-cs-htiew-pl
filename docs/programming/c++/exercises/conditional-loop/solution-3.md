# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Liczba powstała poprzez odwrócenie cyfr liczby $$n$$

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, cyfra, odwrocona;
    
    odwrocona = 0;
    
    cout << "Podaj liczbe:" << endl;
    cin >> n;
    
    while (n > 0) {
        cyfra = n % 10;
        
        odwrocona *= 10;
        odwrocona += cyfra;
        
        n = n / 10;
    }
    
    cout << "Odwrocona liczba: " << odwrocona << endl;
    
    return 0;
}
```
