# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* $$mno[n][n]$$ - dwuwymiarowa tablica reprezentująca tabliczkę mnożenia liczb z zakresu $$[0,n-1]$$, gdzie $$mno[i][j]=i*j$$

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int mno[n][n];

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      mno[i][j] = i * j;
    }
  }

  cout << "Tabliczka mnozenia: ";
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << mno[i][j] << " ";
    }
    
    cout << endl;
  }

  return 0;
}
```