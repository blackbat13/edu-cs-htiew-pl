# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Losowanie tablicy oraz wypisywanie tablicy na ekranie zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$p, k$$ - liczby całkowite, $$p < k$$

#### Wynik

* $$n$$-elementowa tablica losowych liczb całkowitych z przedziału $$[p,k)$$

## Rozwiązanie

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

void losuj(int n, int tab[], int p, int k) {
  srand(time(NULL));

  for(int i = 0; i < n; i++) {
    tab[i] = (rand() % (p - k)) + p;
  }
}

void wypisz(int n, int tab[]) {
  for(int i = 0; i < n; i++) {
    cout << tab[i] << " ";
  }

  cout << endl;
}

int main() {
  int n, p, k;

  cout << "Podaj rozmiar tablicy:" << endl;
  cin >> n;

  int tab[n];

  cout << "Podaj zakres elementow:" << endl;
  cin >> p >> k;

  losuj(n, tab, p, k);

  cout << "Wylosowana tablica:" << endl;
  wypisz(n, tab);
  return 0;
} 
```
