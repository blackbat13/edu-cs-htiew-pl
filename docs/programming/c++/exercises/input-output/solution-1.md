# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$imie$$ - ciąg znaków, małych i wielkich liter alfabetu angielskiego

#### Wynik

* Komunikat powitania w formie "_Witaj \[**imie**]!_", np. "_Witaj Damian!_"

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    string imie;
    
    cout << "Podaj swoje imie:" << endl;
    cin >> imie;
    
    cout << "Witaj " << imie << "!" << endl;
    
    return 0;
}
```
