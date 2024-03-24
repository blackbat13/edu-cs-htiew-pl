# Instrukcja warunkowa

## Zadanie 1

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **abs, fabs**

### Specyfikacja

#### Dane

* $$a$$ - liczba całkowita

#### Wynik

* Wartość bezwzględna z $$a$$

### Przykład

#### Dane

```
a := -2
```

**Wynik**: $$2$$ 

## Zadanie 2

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a$$ - liczba całkowita

#### Wynik

* Znak liczby $$a$$, tzn. $$1$$ gdy $$a$$ jest dodatnie, $$-1$$ gdy $$a$$ jest ujemne, $$0$$ gdy $$a$$ wynosi $$0$$ 

### Przykład 1

#### Dane

```
a := 5
```

**Wynik**: $$1$$ 

### Przykład 2

#### Dane

```
a := -5
```

**Wynik**: $$-1$$ 

### Przykład 3

#### Dane

```
a := 0
```

**Wynik**: $$0$$ 

## Zadanie 3

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite

#### Wynik

* Wynik dzielenia liczb $$a$$ i $$b$$, lub komunikat, że nie można wykonać dzielenia.

### Przykład

#### Dane

```
a := 1
b := 2
```

**Wynik**: $$0.5$$ 

## Zadanie 4

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **min, max**.

### Specyfikacja

#### Dane

* $$a, b, c$$ - trzy liczby całkowite

#### Wynik

* Największa z liczb $$a$$, $$b$$ i $$c$$ , lub dowolna gdy są sobie równe

### Przykład

#### Dane

```
a := 4
b := 1
c := 3
```

**Wynik**: $$4$$ 

## Zadanie 5

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **min, max**.

### Specyfikacja

#### Dane

* $$a, b, c, d$$ - cztery liczby całkowite

#### Wynik

* Największa z liczb $$a, b, c$$ i $$d$$, lub dowolna gdy są sobie równe

### Przykład

#### Dane

```
a := 3
b := 1
c := 3
d := 5
```

**Wynik**: $$5$$ 

## Zadanie 6

Napisz program zgodny z poniższą specyfikacją. Zadbaj o czytelność programu.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite
* $$op$$ - znak jednej z dozwolonych operacji: $$+,-,*,/$$ 

#### Wynik

* Wynik działania$$a\ op\ b$$ (np. $$a+b$$), lub komunikat, że nie można wykonać dzielenia.

### Przykład

#### Dane

```
a := 3
b := 1
op := '+'
```

**Wynik**: $$4$$ 

## Zadanie 7

Napisz program zgodny z poniższą specyfikacją.

{% hint style="info" %}
**Rok przestępny** to taki, który:

* jest podzielny przez 4, ale nie jest podzielny przez 100, lub
* jest podzielny przez 400
{% endhint %}

### Specyfikacja

#### Dane

* $$rok$$ - liczba naturalna

#### Wynik

* Komunikat określający, czy podany rok jest przestępny czy też nie

### Przykład

#### Dane

```
rok := 2021
```

**Wynik**:  "Rok 2021 nie jest przestępny"

## Powiązane zadania algorytmiczne

{% content-ref url="../../../../algorytmika-zadania/poziom-1/porownywanie-liczb/" %}
[porownywanie-liczb](../../../../algorytmika-zadania/poziom-1/porownywanie-liczb/)
{% endcontent-ref %}

{% content-ref url="../../../../algorytmika-zadania/poziom-1/ciecie-kosztow.md" %}
[ciecie-kosztow.md](../../../../algorytmika-zadania/poziom-1/ciecie-kosztow.md)
{% endcontent-ref %}

{% content-ref url="../../../../algorytmika-zadania/poziom-1/pakowanie-na-wakacje.md" %}
[pakowanie-na-wakacje.md](../../../../algorytmika-zadania/poziom-1/pakowanie-na-wakacje.md)
{% endcontent-ref %}
