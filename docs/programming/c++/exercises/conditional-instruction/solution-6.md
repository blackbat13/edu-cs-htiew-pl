# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Zadbaj o czytelność programu.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite
* $$op$$ - znak jednej z dozwolonych operacji: $$+,-,*,/$$ 

#### Wynik

* Wynik działania$$a\ op\ b$$ (np. $$a+b$$), lub komunikat, że nie można wykonać dzielenia.

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int a, b;
    char op;
    
    cout << "Podaj dwie liczby:" << endl;
    cin >> a >> b;
    
    cout << "Podaj znak dzialania:" << endl;
    cin >> op;
    
    if (op == '+') {
        cout << a << " + " << b << " = " << a + b << endl;
    } else if (op == '-') {
        cout << a << " - " << b << " = " << a - b << endl;
    } else if (op == '*') {
        cout << a << " * " << b << " = " << a * b << endl;
    } else {
        cout << a << " / " << b << " = " << (double) a / (double) b << endl;
    }
    
    return 0;
}
```
