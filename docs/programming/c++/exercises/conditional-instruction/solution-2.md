# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a$$ - liczba całkowita

#### Wynik

* Znak liczby $$a$$, tzn. $$1$$ gdy $$a$$ jest dodatnie, $$-1$$ gdy $$a$$ jest ujemne, $$0$$ gdy $$a$$ wynosi $$0$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a;
    
    cout << "Podaj liczbe:" << endl;
    cin >> a;
    
    cout << "Znak podanej liczby: ";
    if (a < 0) {
        cout << -1 << endl;
    } else if (a > 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}
```
