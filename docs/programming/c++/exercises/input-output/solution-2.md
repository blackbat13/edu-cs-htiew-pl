# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite

#### Wynik

* Suma liczb $$a$$ i $$b$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b, suma;
    
    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> b;
    
    suma = a + b;
    
    cout << a << " + " << b << " = " << suma << endl;
    return 0;
}
```
