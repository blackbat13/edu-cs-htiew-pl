# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$n$$liczb całkowitych

#### Wynik

* Suma podanych $$n$$ liczb

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, suma, liczba;
    
    suma = 0;
    
    cout << "Podaj ilosc liczb:" << endl;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Podaj liczbe nr " << i << endl;
        cin >> liczba;
        
        suma += liczba;
    }
    
    cout << "Suma: " << suma << endl;
    
    return 0;
}
```
