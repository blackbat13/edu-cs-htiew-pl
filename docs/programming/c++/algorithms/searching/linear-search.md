# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

bool linearSearch(int array[], int n, int number) {
    for (int i = 0; i < n; i++) {
        if (array[i] == number) {
            return true;
        }
    }

    return false;
}

int main() {
    int array[10] = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0};
    int n = 10;
    int number = 7;
    
    bool result = linearSearch(array, n, number);
    
    if (result) {
        cout << "Liczba jest w tablicy" << endl;
    } else {
        cout << "Liczby nie ma w tablicy" << endl;
    }

    return 0;
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 5**) zwraca jako wynik wartość prawda/fałsz i przyjmuje trzy argumenty: tablicę do przeszukania, rozmiar tablicy oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do $$n-1$$ włącznie (**linia 6**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 7**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w tablicy (**linia 8**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 12**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 16**), jej rozmiar (**linia 17**), oraz wartość poszukiwanego elementu (**linia 18**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 20**). W zależności od wyniku (**linia 22**) wypisujemy odpowiedni komunikat (**linie 23 i 25**).

## Pozycja elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

int linearSearch(int array[], int n, int number) {
    for (int i = 0; i < n; i++) {
        if (array[i] == number) {
            return i;
        }
    }

    return -1;
}

int main() {
    int array[10] = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0};
    int n = 10;
    int number = 7;

    int index = linearSearch(array, n, number);
    
    if (index == -1) {
        cout << "Liczby nie ma w tablicy" << endl;
    } else {
        cout << "Liczba jest pod indeksem " << index << endl;
    }

    return 0;
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 5**) zwraca jako wynik liczbę całkowitą i przyjmuje trzy argumenty: tablicę do przeszukania, rozmiar tablicy oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do $$n-1$$ włącznie (**linia 6**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 7**). Jeżeli tak, to zwracamy indeks tej wartości w tablicy (**linia 8**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość $$-1$$ informującą, że poszukiwany element nie znajduje się w tablicy (**linia 12**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 16**), jej rozmiar (**linia 17**), oraz wartość poszukiwanego elementu (**linia 18**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 20**). W zależności od wyniku (**linia 22**) wypisujemy odpowiedni komunikat (**linie 23 i 25**).

## Wszystkie pozycje elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

void linearSearch(int array[], int n, int number) {
    for (int i = 0; i < n; i++) {
        if (array[i] == number) {
            cout << i << endl;
        }
    }
}

int main() {
    int array[10] = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0};
    int n = 10;
    int number = 7;

    cout << "Indeksy, pod ktorymi znajduje sie poszukiwana liczba:" << endl;
    linearSearch(array, n, number);

    return 0;
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 5**) nie zwraca wyniku i przyjmuje trzy argumenty: tablicę do przeszukania, rozmiar tablicy oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do $$n-1$$ włącznie (**linia 6**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 7**). Jeżeli tak, to wypisujemy ten indeks (**linia 8**). 

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 14**), jej rozmiar (**linia 15**), oraz wartość poszukiwanego elementu (**linia 16**). Następnie wypisujemy stosowny komunikat i wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami.
