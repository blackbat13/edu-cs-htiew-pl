# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Implementacja

```kotlin
fun linearSearch(array: List<Int>, number: Int): Boolean {
  for (el in array) {
    if (el == number) {
      return true
    }
  }

  return false
}

fun main() {
  val array = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  val number = 8

  val result = linearSearch(array, number)

  if (result) {
    println("Poszukiwana wartosc jest w liscie")
  } else {
    println("Poszukiwanej wartosci nie ma w liscie")
  }
}
```

### Link do implementacji

{% embed url="https://ideone.com/ShpM4v" %}
Wyszukiwanie liniowe - istnienie elementu
{% endembed %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne elementy listy (**linia 2**). Dla każdego elementu sprawdzamy, czy jego wartość jest tą, której szukamy (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w liście (**linia 4**). Po przejściu przez wszystkie elementy listy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `false` informującą, że poszukiwany element nie znajduje się w liście (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Pozycja elementu

```kotlin
fun linearSearch(array: List<Int>, number: Int): Int {
  for (i in array.indices) {
    if (array[i] == number) {
      return i
    }
  }

  return -1
}

fun main() {
  val array = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  val number = 8

  val index = linearSearch(array, number)

  if (index == -1) {
    println("Poszukiwanej wartosci nie ma w liscie")
  } else {
    println("Poszukiwana wartosc znajduje sie pod indeksem $index")
  }
}
```

### Link do implementacji

{% embed url="https://ideone.com/KeI9lc" %}
Wyszukiwanie liniowe - pozycja elementu
{% endembed %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście (**linia 2**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks wartości w liście (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość $$-1$$ informującą, że poszukiwany element nie znajduje się w liście (**linia 8**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 12**) oraz wartość poszukiwanego elementu (**linia 13**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 15**). W zależności od wyniku (**linia 17**) wypisujemy odpowiedni komunikat (**linie 18 i 20**).

## Wszystkie pozycje elementu

### Implementacja

```kotlin
fun linearSearch(array: List<Int>, number: Int) {
  for (i in array.indices) {
    if (array[i] == number) {
      println(i)
    }
  }
}

fun main() {
  val array = listOf(8, 2, 8, 4, 5, 6, 7, 8, 9, 8)
  val number = 8

  println("Poszukiwana wartosc znajduje sie pod następujacymi indeksami:")
  linearSearch(array, number)
}
```

### Link do implementacji

{% embed url="https://ideone.com/G8jeS5" %}
Wyszukiwanie liniowe - wszystkie pozycje elementu
{% endembed %}

### Opis implementacji

Funkcja `linearSearch` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście (**linia 2**). Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 10**) oraz wartość poszukiwanego elementu (**linia 11**). Następnie wypisujemy stosowny komunikat (**linia 13**) i wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami (**linia 14**).
