# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```go
package main

import "fmt"

type array []int

func (arr array) linearSearch(number int) bool {
	for i := 0; i < len(arr); i++ {
        if arr[i] == number {
            return true
        }
	}

    return false
}

func main() {
	arr := array{8, 2, 9, 10, 5, 4, 2, 7, 18, 0}
    number := 7

	result := arr.linearSearch(number)

    if result {
        fmt.Println("Liczba jest w tablicy")
    } else {
        fmt.Println("Liczby nie ma w tablicy")
    }
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 7**) zwraca jako wynik wartość prawda/fałsz i jest metodą przypisaną do tablicy przyjmującą jeden argumenty: wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do rozmiaru tablicy minus jeden (**linia 8**). Rozmiar tablicy pobieramy za pomocą funkcji `len`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 9**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w tablicy (**linia 10**). Po przejściu przez wszystkie elementy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 14**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 18**) oraz wartość poszukiwanego elementu (**linia 19**). Następnie wywołujemy metodę `linearSearch` na tablicy z wcześniej przygotowanym parametrem i jej wynik zapisujemy w nowej zmiennej `result` (**linia 21**). W zależności od wyniku (**linia 23**) wypisujemy odpowiedni komunikat (**linie 24 i 26**).

## Pozycja elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```go
package main

import "fmt"

type array []int

func (arr array) linearSearch(number int) int {
	for i := 0; i < len(arr); i++ {
        if arr[i] == number {
            return i
        }
	}

    return -1
}

func main() {
	arr := array{8, 2, 9, 10, 5, 4, 2, 7, 18, 0}
    number := 7

	index := arr.linearSearch(number)

    if index == -1 {
        fmt.Println("Liczby nie ma w tablicy")
    } else {
        fmt.Printf("Liczba jest pod indeksem %d\n", index)
    }
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 7**) zwraca jako wynik liczbę całkowitą i jest metodą przypisaną do tablicy przyjmującą jeden argumenty: wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do rozmiaru tablicy minus jeden (**linia 8**). Rozmiar tablicy pobieramy za pomocą funkcji `len`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 9**). Jeżeli tak, to zwracamy indeks tej wartości w tablicy (**linia 10**). Po przejściu przez wszystkie elementy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `-1` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 14**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 18**) oraz wartość poszukiwanego elementu (**linia 19**). Następnie wywołujemy metodę `linearSearch` na tablicy z wcześniej przygotowanym parametrem i jej wynik zapisujemy w nowej zmiennej `index` (**linia 21**). W zależności od wyniku (**linia 23**) wypisujemy odpowiedni komunikat (**linie 24 i 26**).

## Wszystkie pozycje elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```go
package main

import "fmt"

type array []int

func (arr array) linearSearch(number int) {
	for i := 0; i < len(arr); i++ {
        if arr[i] == number {
            fmt.Println(i)
        }
	}
}

func main() {
	arr := array{8, 2, 8, 4, 5, 6, 7, 8, 9, 8}
    number := 8

    fmt.Println("Indeksy, pod którymi znajduje się poszukiwana liczba:")
	arr.linearSearch(number)
}
```
{% endcode %}

### Opis implementacji

Funkcja `linearSearch` (**linia 7**) nie zwraca wyniku i jest metodą przypisaną do tablicy przyjmującą jeden argumenty: wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do rozmiaru tablicy minus jeden (**linia 8**). Rozmiar tablicy pobieramy za pomocą funkcji `len`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 9**). Jeżeli tak, to wypisujemy ten indeks (**linia 10**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 16**) oraz wartość poszukiwanego elementu (**linia 17**). Następnie wypisujemy stosowny komunikat (**linia 19**) i wywołujemy metodę `linearSearch` na tablicy z wcześniej przygotowanym parametrem (**linia 20**). 