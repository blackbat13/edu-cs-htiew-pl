# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$p$$ - liczba naturalna z zakresu $$[2,9]$$

#### Wynik

* Zapis liczby $$n$$ w systemie o podstawie $$p$$ 

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, p, cyfra;
    string nowa = "";
    
    cout << "Podaj liczbe dziesietna:" << endl;
    cin >> n;
    
    cout << "Podaj nowa podstawe:" << endl;
    cin >> p;
    
    while (n > 0) {
        cyfra = n % p;
        
        nowa = (char)(cyfra + '0') + nowa;
        
        n = n / p;
    }
    
    cout << "Po zamianie: " << nowa << endl;
    
    return 0;
}
```
