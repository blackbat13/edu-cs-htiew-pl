# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.&#x20;

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych

#### Wynik

* $$a_n,a_{n-1},\dots,a_2,a_1$$ - podane liczby w odwrotnej kolejności

## Rozwiązanie

```cpp
#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Podaj liczbe elementow:" << endl;
  cin >> n;

  int tab[n];

  for(int i = 0; i < n; i++) {
    cout << "Podaj kolejna wartosc:" << endl;
    cin >> tab[i];
  }

  for(int i = n - 1; i >= 0; i--) {
    cout << tab[i] << endl;
  }

  return 0;
}
```

### Opis rozwiązania

Na początku tworzymy zmienną $$n$$ (**linia 5**), w której będziemy przechowywać liczbę elementów, którą następnie wczytujemy od użytkownika (**linia 8**).

Gdy już znamy liczbę elementów, możemy utworzyć tablicę o odpowiednim rozmiarze. Tworzymy więc tablicę o rozmiarze $$n$$ (**linia 10**).

W kolejnym kroku, w pętli wczytujemy kolejne wartości od użytkownika i zapisujemy je w tablicy. Pętlą przechodzimy przez kolejne indeksy w naszej tablicy, tzn. od $$0$$ do $$n$$ (**linia 12**). Licznik pętli, zmienna `i`, określa indeks w tablicy, pod którym zapisujemy wczytaną wartość (**linia 14**).

Ostatnim etapem rozwiązania jest ponowne przejście po wszystkich indeksach elementów, tylko w kolejności malejącej: od ostatniego indeksu ($$n - 1$$) do pierwszego indeksu ($$0$$) (**linia 17**). W pętli wypisujemy wartości kolejnych elementów tablicy (**linia 18**).
