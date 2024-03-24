# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych
* $$p, k$$ - dwie liczby naturalna, $$1<=p,k<=n$$, $$p <= k$$

#### Wynik

* $$a_p+a_{p+1}+a_{p+2}+...+a_{k}$$ - suma wartości na pozycjach od $$p$$ do $$k$$

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n, p, k, suma;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int tab[n];

  for(int i = 0; i < n; i++) {
    cout << "Podaj kolejna wartosc:" << endl;
    cin >> tab[i];
  }

  cout << "Podaj pozycje pierwszego i ostatniego elementu:" << endl;
  cin >> p >> k;

  suma = 0;

  for(int i = p; i <= k; i++) {
      suma += tab[i];
  }

  cout << "Suma elementow z podanego zakresu wynosi: " << suma << endl;

  return 0;
}
```