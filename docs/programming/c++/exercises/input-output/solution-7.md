# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wykorzystaj funkcję **max**.

### Specyfikacja

#### Dane

* $$a, b, c$$ - trzy liczby całkowite

#### Wynik

* Największa z liczb $$a$$, $$b$$ i $$c$$ , lub dowolna gdy są sobie równe

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b, c, wynik;
    
    cout << "Podaj trzy liczby:" << endl;
    cin >> a >> b >> c;
    
    wynik = max(a, b);
    wynik = max(wynik, c);
    
    cout << "Maksimum: " << wynik << endl;
    
    return 0;
}
```
