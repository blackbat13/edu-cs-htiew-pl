# Wyszukiwanie liniowe

## [Opis problemu](../../../../algorithms/searching/linear-search.md)

## Istnienie elementu

### Implementacja

```javascript linenums="1"
function linearSearch(array, value) {
    for (let i = 0; i < array.length; i++) {
        if (array[i] == value) {
            return true;
        }
    }

    return false;
}

let array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0];
let value = 7;

let result = linearSearch(array, value);

if (result) {
    console.log("Liczba jest w tablicy");
} else {
    console.log("Liczby nie ma w tablicy");
}
```

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $0$ do rozmiaru tablicy minus jeden (**linia 2**). Rozmiar tablicy pobieramy za pomocą własności `length`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w tablicy (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Pozycja elementu

### Implementacja

```javascript linenums="1"
function linearSearch(array, value) {
    for (let i = 0; i < array.length; i++) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

let array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0];
let value = 7;

let index = linearSearch(array, value);

if (index == -1) {
    console.log("Liczby nie ma w tablicy");
} else {
    console.log("Liczba jest pod indeksem ", index);
}
```

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $0$ do rozmiaru tablicy minus jeden (**linia 2**). Rozmiar tablicy pobieramy za pomocą własności `length`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks tej wartości w tablicy (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `-1` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Wszystkie pozycje elementu

### Implementacja

```javascript linenums="1"
function linearSearch(array, value) {
    for (let i = 0; i < array.length; i++) {
        if (array[i] == value) {
            console.log(i);
        }
    }
}

let array = [8, 2, 8, 4, 5, 6, 7, 8, 9, 8];
let value = 8;

console.log("Indeksy, pod którymi znajduje się poszukiwana liczba:")
linearSearch(array, value);
```

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $0$ do rozmiaru tablicy minus jeden (**linia 2**). Rozmiar tablicy pobieramy za pomocą własności `length`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 10**) oraz wartość poszukiwanego elementu (**linia 11**). Następnie wypisujemy stosowny komunikat (**linia 13**) wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami (**linia 14**).