# Rozwiązanie 8

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Wszystkie trójki liczb naturalnych, których suma wynosi $$n$$

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    
    cout << "Podaj liczbe:" << endl;
    cin >> n;
    
    for (int i = 0; i <= n / 3; i++) {
        for (int j = i; j <= (n - i) / 2; j++) {
            cout << "(" << i << ", " << j << ", " << n - i - j << ")" << endl;
        }
    }
    
    return 0;
}
```
