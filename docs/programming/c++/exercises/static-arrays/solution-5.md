# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* $$fib[n]$$ - tablica zawierająca $$n$$ kolejnych liczb Fibonacciego

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int fib[n];

  fib[0] = 1;
  fib[1] = 1;

  for(int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  cout << "Kolejne liczby Fibonacciego: ";
  for(int i = 0; i < n; i++) {
    cout << fib[i] << " ";
  }
  
  cout << endl;

  return 0;
}
```