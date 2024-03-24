# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite

#### Wynik

* Wynik dzielenia liczb $$a$$ i $$b$$, lub komunikat, że nie można wykonać dzielenia.

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b;
    double wynik;
    
    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> b;
    
    if (b == 0) {
        cout << "Nie mozna dzielic przez 0" << endl;
    } else {
        wynik = (double)a / (double)b;
        cout << a << " / " << b << " = " << wynik << endl;
    }
    
    return 0;
}
```
