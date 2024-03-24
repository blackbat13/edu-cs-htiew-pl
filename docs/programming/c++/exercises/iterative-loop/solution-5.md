# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n, k$$ - liczby naturalne, większe od zera
* $$n$$liczb naturalnych

#### Wynik

* Ilość liczb podzielnych przez $$k$$ z podanych $$n$$ liczb

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, k, podzielne, liczba;
    
    podzielne = 0;
    
    cout << "Podaj ilosc liczb:" << endl;
    cin >> n;
    
    cout << "Podaj dzielnik:" << endl;
    cin >> k;
    
    for (int i = 1; i <= n; i++) {
        cout << "Podaj liczbe nr " << i << endl;
        cin >> liczba;
        
        if (liczba % k == 0) {
            podzielne += 1;
        }
    }
    
    cout << "Podzielne: " << podzielne << endl;
    
    return 0;
}
```
