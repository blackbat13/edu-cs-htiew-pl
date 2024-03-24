# Obsługa wejścia/wyjścia

## Zadanie 1

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$imie$$ - ciąg znaków, małych i wielkich liter alfabetu angielskiego

#### Wynik

* Komunikat powitania w formie "_Witaj \[**imie**]!_"

### Przykład

#### Dane

```
imie := "Damian"
```

**Wynik**: "Witaj Damian!"

## Zadanie 2

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite

#### Wynik

* Suma liczb $$a$$ i $$b$$ 

### Przykład

#### Dane

```
a := 2
b := 3
```

**Wynik**: $$5$$ 

## Zadanie 3

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite, różne od zera

#### Wynik

* Wynik dzielenia liczb $$a$$ i $$b$$ 

### Przykład

#### Dane

```
a := 1
b := 2
```

**Wynik**: $$0.5$$ 

## Zadanie 4

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby naturalne, większe od zera

#### Wynik

* Wynik dzielenia całkowitego oraz reszta z dzielenia liczb $$a$$ i $$b$$ 

### Przykład

#### Dane

```
a := 7
b := 3
```

**Wynik**: $$2$$, reszty $$1$$ 

## Zadanie 5

Napisz program zgodny z poniższą specyfikacją.

{% hint style="info" %}
**Podpowiedź**

Skorzystaj z funkcji **`sqrt`** z biblioteki **`cmath`**.
{% endhint %}

### Specyfikacja

#### Dane

* $$a$$ - liczba naturalna

#### Wynik

* Pierwiastek z $$a$$

### Przykład

#### Dane

```
a := 4
```

**Wynik**: $$2$$ 

## Zadanie 6

Napisz program zgodny z poniższą specyfikacją. Wykorzystaj funkcję **min**.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite

#### Wynik

* Mniejsza z liczb $$a$$ i $$b$$, lub dowolna gdy są sobie równe

### Przykład

#### Dane

```
a := 5
b := 3
```

**Wynik**: $$3$$ 

## Zadanie 7

Napisz program zgodny z poniższą specyfikacją. Wykorzystaj funkcję **max**.

### Specyfikacja

#### Dane

* $$a, b, c$$ - trzy liczby całkowite

#### Wynik

* Największa z liczb $$a$$, $$b$$ i $$c$$ , lub dowolna gdy są sobie równe

### Przykład

#### Dane

```
a := 3
b := 1
c := 3
```

**Wynik**: $$3$$ 

## Zadanie 8

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$sekundy$$ - liczba naturalna

#### Wynik

* Czas podany w czytelnej formie **$$H:M:S$$** ($$H$$ - godziny, $$M$$ - minuty, $$S$$ - sekundy)

### Przykład

#### Dane

```
sekundy := 9179
```

**Wynik**: $$2:32:59$$ 

{% hint style="info" %}
**Wyjaśnienie**

$$2H=7200S$$ 

$$32M=1920S$$ 

$$2H+32M+59S=7200S+1920S+59S=9179S$$ 
{% endhint %}
