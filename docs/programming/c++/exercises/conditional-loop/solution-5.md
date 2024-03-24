# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Zapis binarny liczby $$n$$

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, cyfra;
    string binarna = "";
    
    cout << "Podaj liczbe:" << endl;
    cin >> n;
    
    while (n > 0) {
        cyfra = n % 2;
        
        binarna = (char)(cyfra + '0') + binarna;
        
        n = n / 2;
    }
    
    cout << "Wartosc binarna: " << binarna << endl;
    
    return 0;
}
```
