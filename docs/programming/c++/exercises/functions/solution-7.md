# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wczytywanie tablicy, a także obliczanie każdej ze statystyk zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Statystyki tablicy $$tab$$: minimum, maksimum, suma, średnia

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

void wczytaj(int n, int tab[]) {
  for(int i = 0; i < n; i++) {
    cout << "Podaj wartosc pod indeksem " << i << endl;
    cin >> tab[i];
  }
}

int minimum(int n, int tab[]) {
  int minimum = tab[0];
  for(int i = 1; i < n; i++) {
    if(tab[i] < minimum) {
      minimum = tab[i];
    }
  }

  return minimum;
}

int maksimum(int n, int tab[]) {
  int maksimum = tab[0];
  for(int i = 1; i < n; i++) {
    if(tab[i] > maksimum) {
      maksimum = tab[i];
    }
  }

  return maksimum;
}

int suma(int n, int tab[]) {
  int wynik = 0;
  for(int i = 0; i < n; i++) {
    wynik += tab[i];
  }

  return wynik;
}

double srednia(int n, int tab[]) {
  double wynik;

  wynik = (double) suma(n, tab) / (double) n;

  return wynik;
}

int main() {
  int n;

  cout << "Podaj rozmiar tablicy:" << endl;
  cin >> n;

  int tab[n];

  wczytaj(n, tab);

  cout << "Minimum: " << minimum(n, tab) << endl;
  cout << "Maksimum: " << maksimum(n, tab) << endl;
  cout << "Suma: " << suma(n, tab) << endl;
  cout << "Srednia: " << srednia(n, tab) << endl;

  return 0;
} 
```
