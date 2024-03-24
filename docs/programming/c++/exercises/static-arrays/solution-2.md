# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych
* $$k$$ - liczba naturalna, $$1<=k<=n$$

#### Wynik

* $$a_k$$ - $$k$$-ta podana liczba

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n, k;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int tab[n];

  for(int i = 0; i < n; i++) {
    cout << "Podaj kolejna wartosc:" << endl;
    cin >> tab[i];
  }

  cout << "Podaj numer elementu:" << endl;
  cin >> k;

  cout << "Element numer " << k << " = " << tab[k - 1] << endl;

  return 0;
}
```

### Opis rozwiązania

Na początku tworzymy zmienną $$n$$ (**linia 5**), w której będziemy przechowywać liczbę elementów, którą następnie wczytujemy od użytkownika (**linia 8**).

Gdy już znamy liczbę elementów, możemy utworzyć tablicę o odpowiednim rozmiarze. Tworzymy więc tablicę o rozmiarze $$n$$ (**linia 10**).

W kolejnym kroku, w pętli wczytujemy kolejne wartości od użytkownika i zapisujemy je w tablicy. Pętlą przechodzimy przez kolejne indeksy w naszej tablicy, tzn. od $$0$$ do $$n$$ (**linia 12**). Licznik pętli, zmienna `i`, określa indeks w tablicy, pod którym zapisujemy wczytaną wartość (**linia 14**).

Następnie wczytujemy od użytkownika numer elementu, który należy wypisać (**linia 18**).

Teraz pozostało wypisać właściwy element. Ponieważ tablica jest numerowana (indeksowana) od zera, należy wypisać element pod indeksem $$k - 1$$ (**linia 20**).