# Zakupy

W pliku *groceries.txt* znajduje się 1000 linii, które zawierają informacje na temat pewnych zakupów. W każdej linii znajdują się trzy wartości oddzielone spacją:

- nazwa produktu - tekst składający się wyłącznie z małych liter alfabetu angielskiego,
- liczba sztuk - liczba naturalna z przedziału $$[1, 100]$$,
- cena za sztukę - liczba rzeczywista z dokładnością do dwóch miejsc po przecinku, z przedziału $$[0.01, 10.01)$$.

{% file src="../../../../.gitbook/assets/groceries/groceries.txt" %}
groceries.txt
{% endfile %}

W pliku *groceries_test.txt* znajduje się 100 linii w formacie podanym powyżej.

{% file src="../../../../.gitbook/assets/groceries/groceries_test.txt" %}
groceries_test.txt
{% endfile %}

## Zadanie 1

Podaj sumaryczny koszt zakupów, tzn. sumę wszystkich cen przemnożonych przez liczbę sztuk dla każdej linii w pliku. Wynik podaj z dokładnością do dwóch miejsc po przecinku.

Wynik dla pliku *groceries_test.txt*: $$31511.71$$.

## Zadanie 2

Podaj sumaryczny koszt zakupów zakładając, że wszystkie produkty, których długość nazwy jest liczbą pierwszą, mają cenę pomniejszoną o 50%. Wynik podaj z dokładnością do dwóch miejsc po przecinku.

Wynik dla pliku *groceries_test.txt*: $$24897.94$$.

## Zadanie 3

Podaj średnią cenę **zakupów**, tzn. sumaryczny koszt zakupów podzielony przez łączną liczbę produktów. Wynik podaj z dokładnością do dwóch miejsc po przecinku.

Wynik dla pliku *groceries_test.txt*: $$5.78$$.

## Zadanie 4

Dla każdego produktu podaj zakupioną łączną liczbę sztuk. Wynik uporządkuj alfabetycznie po nazwie produktu.

Wynik dla pliku *groceries_test.txt*:

```
apples: 97
avocado: 116
bananas: 78
bread: 159
butter: 350
carrots: 148
cheese: 118
chicken: 112
cucumber: 165
dates: 181
eggs: 49
flour: 263
garlic: 140
honey: 32
iceberg: 363
jam: 141
kale: 236
lemons: 160
milk: 309
nuts: 165
olives: 181
onions: 35
oranges: 255
pasta: 27
peppers: 123
potatoes: 87
quinoa: 321
salmon: 161
spinach: 292
tomatoes: 184
yams: 85
yogurt: 142
zucchini: 176
```

## Zadanie 5

Dla każdego produktu podaj jego średnią cenę za sztukę z dokładnością do dwóch miejsc po przecinku. Pamiętaj o uwzględnieniu liczby zakupionych produktów. Wynik uporządkuj alfabetycznie po nazwie produktu.

Wynik dla pliku *groceries_test.txt*:

```
apples: 2.25
avocado: 4.18
bananas: 6.67
bread: 2.97
butter: 5.19
carrots: 4.19
cheese: 7.31
chicken: 8.09
cucumber: 5.28
dates: 3.16
eggs: 7.27
flour: 7.54
garlic: 7.90
honey: 2.85
iceberg: 3.67
jam: 6.42
kale: 3.08
lemons: 5.80
milk: 7.46
nuts: 7.66
olives: 3.95
onions: 8.53
oranges: 7.72
pasta: 8.42
peppers: 8.82
potatoes: 8.08
quinoa: 3.69
salmon: 6.47
spinach: 7.05
tomatoes: 8.24
yams: 4.94
yogurt: 6.89
zucchini: 5.56
```

## Zadanie 6

Podaj produkt oraz jego najmniejszą i największą cenę za sztukę, którego różnica pomiędzy najmniejszą i największą ceną za sztukę jest największa. Jest tylko jeden taki produkt. Wynik uporządkuj alfabetycznie po nazwie produktu.

Wynik dla pliku *groceries_test.txt*:

```
butter: min: 0.45, max: 9.31
```

## Zadanie 7

Dla każdego produktu wypisz wszystkie jego ceny za sztukę, uporządkowane rosnąco. Wynik uporządkuj alfabetycznie po nazwie produktu.

```
apples: 2.25
avocado: 3.38, 5.7
bananas: 6.34, 8.95
bread: 1.41, 2.76, 3.46, 3.82
butter: 0.45, 2.55, 4.66, 7.81, 9.31
carrots: 4.1, 4.29
cheese: 6.07, 8.04
chicken: 7.61, 8.22
cucumber: 3.71, 4.66, 8.59
dates: 0.02, 0.57, 6.71
eggs: 5.82, 9.56
flour: 4.93, 5.05, 7.2, 7.49, 9.77
garlic: 3.83, 4.11, 9.99
honey: 2.85
iceberg: 2.32, 3.18, 3.62, 5.12, 5.25
jam: 5.01, 7.12, 8.02
kale: 0.73, 1.51, 2.72, 4.24, 5.58
lemons: 5.36, 6.07, 7.81, 8.26
milk: 4.47, 5.04, 8.13, 8.55, 8.82, 9.72
nuts: 2.53, 5.69, 8.67, 9.76
olives: 1.38, 2.65, 7.79
onions: 8.17, 9.99
oranges: 6.51, 7.47, 8.93
pasta: 8.42
peppers: 8.68, 9.01
potatoes: 8.08
quinoa: 0.92, 1.73, 2.19, 4.76, 6.3
salmon: 3.73, 6.15, 7.12
spinach: 5.32, 6.16, 6.5, 9.3
tomatoes: 5.46, 8.46, 8.76, 9.48
yams: 3.79, 4.39, 5.74
yogurt: 4.98, 6.46, 8.52
zucchini: 3.06, 8.42
```

## Zadanie 8

Podaj sumaryczny koszt zakupów zakładając, że każdego produktu zakupiono łącznie co najwyżej 100 sztuk. Oznacza to, że jeżeli kolejny wpis w pliku zawiera transakcję, która przekroczy limit 100 sztuk dla danego produktu, to uwzględniamy z niej tylko tę część zakupu, która nie przekracza limitu, a kolejne transakcje dla tego produktu będziemy ignorować. Wynik podaj z dokładnością do dwóch miejsc po przecinku.

Wynik dla pliku *groceries_test.txt*: $$17484.78$$.
