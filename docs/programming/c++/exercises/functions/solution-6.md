# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wczytywanie tablicy, przemnażanie tablicy oraz wypisywanie tablicy na ekranie zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$k$$ - liczba całkowita
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Tablica powstała poprzez przemnożenie każdego elementu tablicy $$tab$$ przez liczbę $$k$$ 

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

void przemnoz(int n, int tab[], int k) {
    for(int i = 0; i < n; i++) {
        tab[i] *= k;
    }
}

int main() {
     int n, k;

    cout << "Podaj liczbe elementow:" << endl;
    cin >> n;

    cout << "Podaj mnoznik:" << endl;
    cin >> k;

    int tab[n];

    wczytaj(n, tab);

    przemnoz(n, tab, k);
    
    wypisz(n, tab);

    return 0;
}
```
