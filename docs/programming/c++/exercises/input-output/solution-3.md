# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite, różne od zera

#### Wynik

* Wynik dzielenia liczb $$a$$ i $$b$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b;
    double wynik;
    
    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> b;
    
    wynik = (double)a / (double)b;
    
    cout << a << " / " << b << " = " << wynik << endl;
    
    return 0;
}
```
