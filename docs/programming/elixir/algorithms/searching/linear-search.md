# Wyszukiwanie liniowe

## [Opis problemu](../../../../algorithms/searching/linear-search.md)


## Istnienie elementu

### Implementacja

```elixir linenums="1"
defmodule Search do
    def linear(array, number) do
        if (length array) == 0 do
            false
        else 
            if hd(array) == number do
                true
            else
                linear(tl(array), number)
            end
        end
    end
end


array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
number = 7

result = Search.linear(array, number)

if result do
    IO.puts "Liczba jest w tablicy"
else
    IO.puts "Liczby nie ma w tablicy"
end
```


### Opis implementacji

Funkcja `linear` w module `Search` (**linie 1 i 2**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Jeżeli lista jest pusta to funkcja zwraca wartość `false` informującą o tym, że poszukiwanego elementu nie znaleziono na liście (**linie 3 i 4**). Jest to tzw. warunek stopu rekurencji. Jeżeli w liście pozostały jeszcze jakieś elementy do sprawdzenia, to sprawdzamy, czy pierwszy element listy (pobrany za pomocą funkcji `hd`) jest poszukiwaną wartością (**linia 6**). Jeżeli tak, to funkcja zwraca wynik `true` (**linia 7**). W przeciwnym przypadku wywołujemy rekurencyjnie funkcję `linear`, jako argumenty przekazując listę bez pierwszego elementu (do tego używamy funkcji `tl`), oraz wartość poszukiwanego elementu.

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 16**) oraz wartość poszukiwanego elementu (**linia 17**). Następnie wywołujemy funkcję `linear` z modułu `Search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 19**). W zależności od wyniku (**linia 21**) wypisujemy odpowiedni komunikat (**linie 22 i 24**).

## Pozycja elementu

### Implementacja

```elixir linenums="1"
defmodule Search do
    def linear(array, number, index) do
        if (length array) == 0 do
            -1
        else 
            if hd(array) == number do
                index
            else
                linear(tl(array), number, index + 1)
            end
        end
    end
end


array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
number = 10

index = Search.linear(array, number, 0)

if index == -1 do
    IO.puts "Liczby nie ma w tablicy"
else
    IO.puts "Liczba jest pod indeksem #{index}"
end
```


### Opis implementacji

Funkcja `linear` w module `Search` (**linie 1 i 2**) zwraca jako wynik liczbę całkowitą i przyjmuje trzy argumenty: listę do przeszukania, wartość poszukiwanego elementu oraz numer obecnie sprawdzanego indeksu. Jeżeli lista jest pusta to funkcja zwraca wartość `-1` informującą o tym, że poszukiwanego elementu nie znaleziono na liście (**linie 3 i 4**). Jest to tzw. warunek stopu rekurencji. Jeżeli w liście pozostały jeszcze jakieś elementy do sprawdzenia, to sprawdzamy, czy pierwszy element listy (pobrany za pomocą funkcji `hd`) jest poszukiwaną wartością (**linia 6**). Jeżeli tak, to funkcja zwraca jako wynik wartość `index` (**linia 7**). W przeciwnym przypadku wywołujemy rekurencyjnie funkcję `linear`, jako argumenty przekazując listę bez pierwszego elementu (do tego używamy funkcji `tl`), wartość poszukiwanego elementu oraz indeks zwiększony o jeden.

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 16**) oraz wartość poszukiwanego elementu (**linia 17**). Następnie wywołujemy funkcję `linear` z modułu `Search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 19**). W zależności od wyniku (**linia 21**) wypisujemy odpowiedni komunikat (**linie 22 i 24**).