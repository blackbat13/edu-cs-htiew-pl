# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$k$$ - liczba naturalna z zakresu $$[0,9]$$

#### Wynik

* Liczba powstała poprzez zastąpienie każdej cyfry liczby $$n$$ przez wartość bezwzględną różnicy liczby $$k$$ i danej cyfry

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

int main() {
    int n, cyfra, nowa, k, pot;
    
    nowa = 0;
    pot = 1;
    
    cout << "Podaj dwie liczby:" << endl;
    cin >> n >> k;
    
    while (n > 0) {
        cyfra = n % 10;
        cyfra = abs(k - cyfra);
        
        nowa += cyfra * pot;
        pot *= 10;
        
        n = n / 10;
    }
    
    cout << "Nowa liczba: " << nowa << endl;
    
    return 0;
}
```
