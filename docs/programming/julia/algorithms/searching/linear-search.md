# Wyszukiwanie liniowe

## [Opis problemu](../../../../algorithms/searching/linear-search.md)

## Istnienie elementu

### Implementacja

```julia linenums="1"
function linearSearch(array, number)
    for el in array
        if el == number
            return true
        end
    end

    return false
end

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
number = 8

result = linearSearch(array, number)

if result
    println("Poszukiwana wartość jest w liście")
else
    println("Poszukiwanej wartości nie ma w liście")
end
```

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne elementy listy (**linia 2**). Dla każdego elementu sprawdzamy, czy jego wartość jest tą, której szukamy (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w liście (**linia 4**). Po przejściu przez wszystkie elementy listy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w liście (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Pozycja elementu

```julia linenums="1"
function linearSearch(array, number)
    for i in eachindex(array)
        if number == array[i]
            return i
        end
    end

    return -1
end

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
number = 8

index = linearSearch(array, number)

if index == -1
    println("Poszukiwanej wartości nie ma w liście")
else
    println("Poszukiwana wartość znajduje się pod indeksem ", index)
end
```

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście od $1$ do długości listy włącznie (**linia 2**). Rozmiar listy pobieramy za pomocą funkcji `lenght()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks wartości w liście (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość $-1$ informującą, że poszukiwany element nie znajduje się w liście (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Wszystkie pozycje elementu

### Implementacja

```julia linenums="1"
function linearSearch(array, number)
    for i in eachindex(array))
        if number == array[i]
            println(i)
        end
    end
end

array = [8, 2, 8, 4, 5, 6, 7, 8, 9, 8]
number = 8

println("Poszukiwana wartość znajduje się pod następującymi indeksami:")
linearSearch(array, number)
```

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście od $1$ do długości listy włącznie (**linia 2**). Rozmiar listy pobieramy za pomocą funkcji `length()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 10**) oraz wartość poszukiwanego elementu (**linia 11**). Następnie wypisujemy stosowny komunikat (**linia 13**) i wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami (**linia 14**).