# Wyszukiwanie liniowe

## [Opis problemu](../../../../algorithms/searching/linear-search.md)


## Istnienie elementu

### Implementacja

```c linenums="1"
#include <stdio.h>
#include <stdbool.h>

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
        printf("Liczba jest w tablicy\n");
    } else {
        printf("Liczby nie ma w tablicy\n");
    }

    return 0;
}
```


### Opis implementacji

Funkcja `linearSearch` (**linia 4**) zwraca jako wynik wartość prawda/fałsz i przyjmuje trzy argumenty: tablicę do przeszukania, rozmiar tablicy oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $0$ do $n-1$ włącznie (**linia 5**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 6**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w tablicy (**linia 7**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 11**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 15**), jej rozmiar (**linia 16**), oraz wartość poszukiwanego elementu (**linia 17**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 19**). W zależności od wyniku (**linia 21**) wypisujemy odpowiedni komunikat (**linie 22 i 24**).

## Pozycja elementu

### Implementacja

```c linenums="1"
#include <stdio.h>

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
        printf("Liczby nie ma w tablicy\n");
    } else {
        printf("Liczba jest pod indeksem %d\n", index);
    }

    return 0;
}
```


### Opis implementacji

Funkcja `linearSearch` (**linia 3**) zwraca jako wynik liczbę całkowitą i przyjmuje trzy argumenty: tablicę do przeszukania, rozmiar tablicy oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $0$ do $n-1$ włącznie (**linia 4**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 5**). Jeżeli tak, to zwracamy indeks tej wartości w tablicy (**linia 6**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość $-1$ informującą, że poszukiwany element nie znajduje się w tablicy (**linia 10**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 14**), jej rozmiar (**linia 15**), oraz wartość poszukiwanego elementu (**linia 16**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 18**). W zależności od wyniku (**linia 20**) wypisujemy odpowiedni komunikat (**linie 21 i 23**).

## Wszystkie pozycje elementu

### Implementacja

```c linenums="1"
#include <stdio.h>

void linearSearch(int array[], int n, int number) {
    for (int i = 0; i < n; i++) {
        if (array[i] == number) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int array[10] = {8, 2, 8, 4, 5, 6, 7, 8, 9, 8};
    int n = 10;
    int number = 8;

    printf("Indeksy, pod ktorymi znajduje sie poszukiwana liczba:\n");
    linearSearch(array, n, number);

    return 0;
}
```


### Opis implementacji

Funkcja `linearSearch` (**linia 3**) nie zwraca wyniku i przyjmuje trzy argumenty: tablicę do przeszukania, rozmiar tablicy oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $0$ do $n-1$ włącznie (**linia 4**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 5**). Jeżeli tak, to wypisujemy ten indeks (**linia 6**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**), jej rozmiar (**linia 13**), oraz wartość poszukiwanego elementu (**linia 14**). Następnie wypisujemy stosowny komunikat (**linia 16**) i wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami (**linia 17**).