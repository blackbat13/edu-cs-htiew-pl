# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji `pow`.

### Specyfikacja

#### Dane

* $$a, n$$ - dwie liczby naturalne

#### Wynik

* $$a^n$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, n, wynik;
    
    wynik = 1;
    
    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> n;
    
    for(int i = 1; i <= n; i++) {
        wynik *= a;
    }
    
    cout << a << "^" << n << " = " << wynik << endl;
    
    return 0;
}
```
