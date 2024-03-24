# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna, większa od $$0$$ 
* $$n$$liczb naturalnych

#### Wynik

* Największa z podanych $$n$$ liczb

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, maks, liczba;
    
    maks = -1;
    
    cout << "Podaj ilosc liczb:" << endl;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cout << "Podaj liczbe nr " << i << endl;
        cin >> liczba;
        
        if (liczba > maks) {
            maks = liczba;
        }
    }
    
    cout << "Maksimum: " << maks << endl;
    
    return 0;
}
```
