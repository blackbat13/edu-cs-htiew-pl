# Wyszukiwanie binarne

## Opis problemu

{% content-ref url="../../../../algorithms/searching/binary-search.md" %}
[binary-search.md](../../../../algorithms/searching/binary-search.md)
{% endcontent-ref %}

## Wersja iteracyjna

### Implementacja

```kotlin
fun binarySearch(array: List<Int>, number: Int): Int {
  var left = 0
  var right = array.count() - 1

  while (left < right) {
    val middle = (left + right) / 2

    if (number < array[middle]) {
      right = middle
    } else if (number > array[middle]) {
      left = middle + 1
    } else {
      return middle
    }
  }

  if (left < array.count() && array[left] == number) {
    return left
  }

  return -1
}

fun main() {
  val array = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  val number = 8

  val index = binarySearch(array, number)

  if (index == -1) {
    println("Szukanej liczby nie ma na liscie")
  } else {
    println("Szukana liczba znajduje sie pod indeksem $index")
  }
}
```

### Link do implementacji

{% embed url="https://ideone.com/n8oV0L" %}
Wyszukiwanie binarne - wersja iteracyjna
{% endembed %}

### Opis implementacji

Funkcja `binarySearch` (**linia 1**) przyjmuje dwa argumenty: uporządkowaną rosnąco listę liczb całkowitych (`array`) oraz poszukiwaną liczbę całkowitą (`number`). Wynikiem zwracanym przez funkcję będzie liczba całkowita reprezentująca pozycję (indeks) szukanej wartości na liście `array`, lub $$-1$$, gdy elementu nie znaleziono.

Zaczynamy od określenia przeszukiwanego zakresu (w postaci indeksów elementów listy). Początek zakresu (`left`) ustalamy na pierwszą pozycję na liście, czyli $$0$$ (**linia 2**). Koniec zakresu (`right`) ustalamy na ostatnią pozycję na liście, którą obliczamy odejmując $$1$$ od rozmiaru listy (**linia 3**). Rozmiar listy pobieramy za pomocą metody `count()`.

Po ustaleniu zakresu przechodzimy do przeszukiwania. Przeszukiwanie wykonujemy w pętli, tak długo jak zakres pozostaje poprawny, a w zakresie znajdują się co najmniej dwie wartości (**linia 5**). Wewnątrz pętli obliczamy środek obecnego zakresu i zapisujemy w zmiennej `middle` (**linia 6**). Następnie sprawdzamy relację poszukiwanej liczby z wartością znajdującą się pod środkowym indeksem. Jeżeli poszukiwana wartość jest mniejsza (**linia 8**), to zmieniamy koniec przeszukiwanego przedziału (**linia 9**). W przeciwnym przypadku, jeżeli poszukiwana liczba jest większa od wartości znajdującej się w środku przedziału (**linia 10**), to zmieniamy początek przedziału (**linia 11**). W przeciwnym przypadku, tzn., gdy poszukiwana liczba nie jest ani mniejsza ani większa od wartości znajdującej się pod indeksem `middle`, oznacza to, że znaleźliśmy poszukiwaną wartość, więc zwracamy jej indeks, czyli wartość zmiennej `middle` (**linia 13**).

Po wyjściu z pętli, to znaczy gdy nie znaleźliśmy jeszcze poszukiwanej wartości, sprawdzamy, czy początek przeszukiwanego zakresu nie przekroczył rozmiaru tablicy. Jeżeli początek zakresu jest nadal poprawny, to sprawdzamy, czy pod tym indeksem znajduje się poszukiwana liczba (**linia 17**). Jeżeli tak jest, to zwracamy indeks znalezionej liczby, czyli indeks początku przeszukiwanego zakresu (**linia 18**).

Na koniec, gdy nie zwróciliśmy wcześniej żadnej wartości, tzn., gdy nie znaleźliśmy poszukiwanej liczby w podanej liście, zwracamy stosowną informację, czyli wartość $$-1$$ (**linia 21**).

W kodzie głównym, czyli funkcji `main` (**linia 24**) na początku tworzymy przykładowe dane testowe: uporządkowaną rosnąco listę liczb (**linia 25**) oraz poszukiwaną wartość (**linia 26**). Następnie wywołujemy wyszukiwanie binarne ze wspomnianymi danymi, a wynik zapisujemy w zmiennej `index` (**linia 28**).

Na koniec programu wypisujemy stosowny komunikat w zależności od wyniku (**linie 30-34**).

## Wersja rekurencyjna

### Implementacja

```kotlin
fun binarySearch(array: List<Int>, number: Int, left: Int, right: Int): Int {
  if(left == right && array[left] == number) {
    return left
  }
  else if (left >= right) {
    return -1
  }

  val middle = (left + right) / 2

  if (number < array[middle]) {
    return binarySearch(array, number, left, middle)
  } else if (number > array[middle]) {
    return binarySearch(array, number, middle + 1, right)
  } else {
    return middle
  }
}

fun main() {
  val array = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  val number = 8

  val index = binarySearch(array, number, 0, array.count())

  if (index == -1) {
    println("Szukanej liczby nie ma na liscie")
  } else {
    println("Szukana liczba znajduje sie pod indeksem $index")
  }
}
```

### Link do implementacji

{% embed url="https://ideone.com/F0QMN2" %}
Wyszukiwanie binarne - wersja rekurencyjna
{% endembed %}

### Opis implementacji

Funkcja `binarySearch` (**linia 1**) przyjmuje cztery argumenty: uporządkowaną rosnąco listę liczb całkowitych (`array`), poszukiwaną liczbę całkowitą (`number`) oraz początek (`left`) oraz koniec (`right`) aktualnie przeszukiwanego przedziału (podanego jako indeksy elementów przeszukiwanej listy). Wynikiem zwracanym przez funkcję będzie liczba całkowita reprezentująca pozycję (indeks) szukanej wartości na liście `array` w podanym przedziale, lub $$-1$$, gdy elementu nie znaleziono.

Zaczynamy od warunku stopu funkcji rekurencyjnej. Sprawdzamy, czy sprawdzany przedział zawiera dokładnie jeden element i czy tym elementem jest poszukiwana wartość (**linia 2**). Jeżeli tak jest, to zwracamy indeks tego elementu (początek lub koniec przeszukiwanego przedziału), jako wynik (**linia 3**). Jeżeli tak nie jest, to sprawdzamy, czy przedział zawiera dokładnie jeden element, lub czy też jest niepoprawny (**linia 5**). W takim przypadku w przeszukiwanym przedziale nie ma szukanego elementu, więc zwracamy $$-1$$ (**linia 6**).

Po sprawdzeniu warunku stopu obliczamy środek obecnego zakresu i zapisujemy w zmiennej `middle` (**linia 9**). Następnie sprawdzamy relację poszukiwanej liczby z wartością znajdującą się pod środkowym indeksem. Jeżeli poszukiwana wartość jest mniejsza (**linia 11**), to rekurencyjnie przeszukujemy lewą część listy, zmieniając koniec przeszukiwanego przedziału (**linia 12**). W przeciwnym przypadku, jeżeli poszukiwana liczba jest większa od wartości znajdującej się w środku przedziału (**linia 13**), to rekurencyjnie przeszukujemy prawą część listy, zmieniając koniec przedziału (**linia 14**). W przeciwnym przypadku, tzn., gdy poszukiwana liczba nie jest ani mniejsza ani większa od wartości znajdującej się pod indeksem `middle`, oznacza to, że znaleźliśmy poszukiwaną wartość, więc zwracamy jej indeks, czyli wartość zmiennej `middle` (**linia 16**).

W kodzie głównym, czyli funkcji `main` (**linia 20**) na początku tworzymy przykładowe dane testowe: uporządkowaną rosnąco listę liczb (**linia 21**) oraz poszukiwaną wartość (**linia 22**). Następnie wywołujemy wyszukiwanie binarne ze wspomnianymi danymi, jako przedział podając początek i liczbę elementów listy, a wynik zapisujemy w zmiennej `index` (**linia 24**).

Na koniec programu wypisujemy stosowny komunikat w zależności od wyniku (**linie 26-30**).
