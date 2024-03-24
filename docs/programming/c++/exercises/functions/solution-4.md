# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wczytywanie tablicy oraz wypisywanie tablicy na ekranie zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Wczytana tablica wypisana na ekranie w jednej linii, każdy element oddzielony spacją

## Rozwiązanie

```cpp
#include <iostream>

using namespace std;

void wczytaj(int n, int tab[]) {
    for(int i = 0; i < n; i++) {
        cout << "Podaj kolejna wartosc:" << endl;
        cin >> tab[i];
    }
}

void wypisz(int n, int tab[]) {
    for(int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;
}

int main() {
     int n;

    cout << "Podaj liczbe elementow:" << endl;
    cin >> n;

    int tab[n];

    wczytaj(n, tab);
    
    wypisz(n, tab);

    return 0;
}
```
