# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```dart
bool linearSearch(List<int> array, int number) {
    for(int element in array) {
      if (element == number) {
          return true;
      }
    }

    return false;
}

void main() {
    List<int> array = [4, 8, 1, 3, 8, 0, 2, 5, 2];
    int number = 0;

    bool result = linearSearch(array, number);

    if (result) {
        print("Liczba jest w tablicy");
    } else {
        print("Liczby nie ma w tablicy");
    }
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne elementy w liście (**linia 2**). Dla każdego elementu sprawdzamy, czy jest to poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w liście (**linia 4**). Po przejściu przez wszystkie elementy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w liście (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Pozycja elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```dart
int linearSearch(List<int> array, int number) {
    for(int i = 0; i < array.length; i++) {
      if (array[i] == number) {
          return i;
      }
    }

    return -1;
}

void main() {
    List<int> array = [4, 8, 1, 3, 8, 0, 2, 5, 2];
    int number = 0;

    int index = linearSearch(array, number);

    if (index == -1) {
        print("Liczby nie ma w tablicy");
    } else {
        print("Liczba jest pod indeksem $index");
    }
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście od $$0$$ do rozmiaru listy minus jeden (**linia 2**). Rozmiar listy pobieramy za pomocą własności `length`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks tej wartości w liście (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `-1` informującą, że poszukiwany element nie znajduje się w liście (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Wszystkie pozycje elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```dart
void linearSearch(List<int> array, int number) {
    for(int i = 0; i < array.length; i++) {
      if (array[i] == number) {
          print(i);
      }
    }
}

void main() {
    List<int> array = [4, 8, 1, 3, 8, 0, 2, 5, 8];
    int number = 8;

    print("Indeksy, pod którymi znajduje się szukana liczba:");

    linearSearch(array, number);
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście od $$0$$ do rozmiaru listy minus jeden (**linia 2**). Rozmiar listy pobieramy za pomocą własności `length`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 10**) oraz wartość poszukiwanego elementu (**linia 11**). Następnie wypisujemy stosowny komunikat (**linia 13**) i wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami (**linia 14**).