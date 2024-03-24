# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Komunikat "niemalejaco" jeżeli elementy tablicy posortowane są niemalejąco
* Komunikat "nierosnaco" jeżeli elementy tablicy posortowane są nierosnąco
* Komunikat "nieposortowane" jeżeli elementy tablicy nie są posortowane

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;
  bool niemalejaco = true;
  bool nierosnaco = true;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int tab[n];

  for(int i = 0; i < n; i++) {
    cout << "Podaj kolejna wartosc:" << endl;
    cin >> tab[i];
  }

  for(int i = 1; i < n; i++) {
    if(tab[i] > tab[i - 1]) {
      nierosnaco = false;
    }

    if(tab[i] < tab[i - 1]) {
      niemalejaco = false;
    }
  }

  if(nierosnaco) {
    cout << "nierosnaco" << endl;
  } else if(niemalejaco) {
    cout << "niemalejaco" << endl;
  } else {
    cout << "nieposortowane" << endl;
  }

  return 0;
}
```