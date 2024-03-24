# STL

## Zadanie 1

Napisz program zgodny z poniższą specyfikacją. W implementacji wykorzystaj klasę `map`.

### Specyfikacja

#### Dane

* $$txt$$ - Wielolinijkowy tekst składający się ze znaków ze standardowej tablicy ASCII, zakończony znakiem końca wyjścia.

#### Wynik

* Dla każdego znaku, jaki pojawił się na wejściu, liczba jego wystąpień. Znaki uporządkowane alfabetycznie, zgodnie z kolejnością w tablicy ASCII.

### Przykład

#### Dane

```
txt := "Ala ma kota"
```

#### Wynik

```
  - 2
A - 1
a - 3
k - 1
l - 1
m - 1
o - 1
t - 1
```

{% hint style="info" %}
Pierwszy znak na powyższej liście to spacja.
{% endhint %}

## Zadanie 2

Napisz program zgodny z poniższą specyfikacją. W implementacji wykorzystaj klasę `stack`.

### Specyfikacja

#### Dane

* $$nawiasy$$ - ciąg składający się jedynie ze znaków reprezentujących nawiasy okrągłe i kwadratowe, tzn.: $$(, ), [, ]$$

#### Wynik

* **TRUE** jeżeli podany na wejściu ciąg jest reprezentacją poprawnego nawiasowania, **FALSE** w przeciwnym przypadku.

### Przykład 1

#### Dane

```
nawiasy := "(([]()))"
```

**Wynik**: TRUE

### Przykład 2

#### Dane

```
nawiasy := "(([(])))"
```

**Wynik**: FALSE

## Zadanie 3

Napisz program zgodny z poniższą specyfikacją. W implementacji wykorzystaj tablicę dynamiczną z STL.

### Specyfikacja

#### Dane

* $$instrukcje$$ - ciąg instrukcji opisany poniżej, zakończony instrukcją **KONIEC**

#### Wynik

* Wartość zadanego elementu wypisana dla każdej instrukcji **WYPISZ**, lub komunikat **BLAD**, jeżeli ciąg instrukcji zawiera błąd

### Instrukcje

Wszystkie wartości są liczbami całkowitymi mieszczącymi się w typie `int`.

* **DODAJ** $$x$$ - dopisz wartość $$x$$ na koniec tablicy
* **USUN** - usuń ostatni element z tablicy
* **WSTAW** $$x$$ **NA** $$i$$ - wstaw wartość $$x$$ na pozycję $$i$$ (numerowane od $$0$$)
* **SORTUJ** $$i$$ $$j$$ - posortuj tablicę rosnąco od elementu pod indeksem $$i$$ do elementu pod indeksem $$j$$ włącznie
* **WYPISZ** $$i$$ - wypisz wartość zapisaną pod indeksem $$i$$
* **KONIEC** - zakończ obliczenia (instrukcja ta występuje tylko raz, na samym końcu ciągu instrukcji)

### Przykład 1

#### Dane

```
DODAJ 3
DODAJ 2
DODAJ 10
WSTAW 1 NA 2
WYPISZ 3
USUN
SORTUJ 0 2
WYPISZ 0
WYPISZ 1
WYPISZ 2
KONIEC
```

#### Wynik

```
10
1
2
3
```

### Przykład 2

#### Dane

```
DODAJ 3
DODAJ 2
DODAJ 10
WSTAW 1 NA 2
WYPISZ 3
USUN
SORTUJ 0 3
WYPISZ 0
WYPISZ 1
WYPISZ 2
KONIEC
```

#### Wynik

```
10
BLAD
```