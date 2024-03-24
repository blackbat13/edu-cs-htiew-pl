# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$rok$$ - liczba naturalna

#### Wynik

* Komunikat określający, czy podany rok jest przestępny czy też nie

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int rok;
    
    cout << "Podaj rok:" << endl;
    cin >> rok;
    
    if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) {
        cout << rok << " jest przestepny" << endl;
    } else {
        cout << rok << " nie jest przestepny" << endl;
    }
    
    return 0;
}
```
