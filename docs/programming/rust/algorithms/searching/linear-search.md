# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```rust
fn linear_search(array: &[i32], number: i32) -> bool {
    for el in array.iter() {
        if *el == number {
            return true;
        }
    }

    return false;
}

fn main() {
    let array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0];
    let number = 10;

    let result = linear_search(&array, number);

    if result {
        println!("Liczba jest w tablicy")
    } else {
        println!("Liczby nie ma w tablicy")
    }
}
```
{% endcode %}

### Opis implementacji

Funkcja `linear_search` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne elementy tablicy (**linia 2**). Dla każdego elementu sprawdzamy, czy jest równy poszukiwanej wartości (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w tablicy (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w tablicy (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Pozycja elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```rust
fn linear_search(array: &[i32], number: i32) -> i32 {
    for i in 0..array.len() {
        if array[i] == number {
            return i as i32;
        }
    }

    return -1;
}

fn main() {
    let array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0];
    let number = 10;

    let index = linear_search(&array, number);

    if index == -1 {
        println!("Liczby nie ma w tablicy")
    } else {
        println!("Liczba jest pod indeksem {}", index)
    }
}
```
{% endcode %}

### Opis implementacji

Funkcja `linear_search` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do rozmiaru tablicy minus 1 włącznie (**linia 2**). Rozmiar tablicy pobieramy za pomocą metody `len()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks tej wartości w tablicy (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość $$-1$$ informującą, że poszukiwany element nie znajduje się w tablicy (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Wszystkie pozycje elementu

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```rust
fn linear_search(array: &[i32], number: i32) {
    for i in 0..array.len() {
        if array[i] == number {
            println!("{}", i);
        }
    }
}

fn main() {
    let array = [8, 2, 8, 4, 5, 6, 7, 8, 9, 8];
    let number = 8;

    println!("Indeksy, pod którymi znajduje się poszukiwana liczba:");
    linear_search(&array, number);
}
```
{% endcode %}

### Opis implementacji

Funkcja `linear_search` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$0$$ do rozmiaru tablicy minus 1 włącznie (**linia 2**). Rozmiar tablicy pobieramy za pomocą metody `len()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**). 

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wypisujemy stosowny komunikat i wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami (**linia 14**).
