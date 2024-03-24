# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wypisanie komunikatu powinno zostać zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$imie$$ - ciąg znaków, małych i wielkich liter alfabetu angielskiego

#### Wynik

* Komunikat powitania w formie "_Witaj \[**imie**]!_", np. "_Witaj Damian!_"

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

void powitanie(string imie) {
    cout << "Witaj " << imie << "!" << endl;
}

int main() {
    string imie;
    
    cout << "Podaj swoje imie:" << endl;
    cin >> imie;
    
    powitanie(imie);
    
    return 0;
}
```
