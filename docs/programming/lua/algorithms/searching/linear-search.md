# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```lua
function linearSearch(array, number)
    for i = 1, #(array) do
        if array[i] == number then
            return true
        end
    end
    
    return false
end


array = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0}
number = 7

result = linearSearch(array, number)

if result then
    print("Liczba jest w tablicy")
else
    print("Liczby nie ma w tablicy")
end
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$1$$ do rozmiaru tablicy włącznie (**linia 2**). Rozmiar tablicy pobieramy za pomocą operatora `#()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w tablicy (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Pozycja elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```lua
function linearSearch(array, number)
    for i = 1, #(array) do
        if array[i] == number then
            return i
        end
    end
    
    return -1
end


array = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0}
number = 7

index = linearSearch(array, number)

if index == -1 then
    print("Liczby nie ma w tablicy")
else
    print("Liczba jest pod indeksem:", index)
end
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$1$$ do rozmiaru tablicy włącznie (**linia 2**). Rozmiar tablicy pobieramy za pomocą operatora `#()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks tej wartości w tablicy (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `-1` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Wszystkie pozycje elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```lua
function linearSearch(array, number)
    for i = 1, #(array) do
        if array[i] == number then
            print(i)
        end
    end
end


array = {8, 2, 8, 4, 5, 6, 7, 8, 9, 8}
number = 8

print("Indeksy, pod którymi znajduje się poszukiwana liczba:")
linearSearch(array, number)
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$1$$ do rozmiaru tablicy włącznie (**linia 2**). Rozmiar tablicy pobieramy za pomocą operatora `#()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 10**) oraz wartość poszukiwanego elementu (**linia 11**). Następnie wypisujemy stosowny komunikat (**linia 13**) wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami (**linia 14**).