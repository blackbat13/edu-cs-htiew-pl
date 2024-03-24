# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$t1[n],\ t2[n]$$ - dwie tablice liczb całkowitych

#### Wynik

* Tablica powstała poprzez dodanie do siebie wartości z tablic $$t1$$ i $$t2$$ 

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int t1[n], t2[n], t3[n];

  for(int i = 0; i < n; i++) {
    cout << "Podaj kolejna wartosc z pierwszej tablicy:" << endl;
    cin >> t1[i];
  }

  for(int i = 0; i < n; i++) {
    cout << "Podaj kolejna wartosc z drugiej tablicy:" << endl;
    cin >> t2[i];
  }


  for(int i = 0; i < n; i++) {
    t3[i] = t1[i] + t2[i];
  }

  cout << "Wynikowa tablica: ";
  for(int i = 0; i < n; i++) {
    cout << t3[i] << " ";
  }
  
  cout << endl;

  return 0;
}
```