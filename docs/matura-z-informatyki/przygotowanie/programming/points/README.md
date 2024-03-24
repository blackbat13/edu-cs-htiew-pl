# Punkty

W pliku *points.txt* znajduje się tysiąc linii. Każda linia zawiera dwie liczby naturalne z przedziału $$[1, 100]$$ oddzielone spacją. Każda para wartości oznacza współrzędne pola w tablicy o wymiarach $$100\times100$$ (pierwsza liczba to numer wiersza, druga to numer kolumny). 

{% file src="../../../../.gitbook/assets/points/points.txt" %}
points.txt
{% endfile %}

Plik *points_test.txt* zawiera sto linii, a w każdej znajduje się jedna para liczb naturalnych z przedziału $$[1, 10]$$ oddzielona spacją. Wartości oznaczają współrzędne pola w tablicy o wymiarach $$10\times10$$ (pierwsza liczba to numer wiersza, druga to numer kolumny).

{% file src="../../../../.gitbook/assets/points/points_test.txt" %}
points_test.txt
{% endfile %}

Do każdego pola w tablicy przypisana jest wartość liczbowa. Zakładamy, że początkowo wszystkie pola w tablicy mają wartość zero. Jeżeli współrzędne pola znajdują się w pliku, to znaczy, że to pole zyskuje jeden punkt. Jeżeli współrzędne danego pola pojawiają się wielokrotnie, to znaczy, że to pole zyskuje tyle samo punktów, ile razy jego współrzędne się pojawiły.

## Zadanie 1

Ile jest w tablicy pól, które mają wartość większą od zera? 

Dla pliku *points_test.txt* wynik to 60.

## Zadanie 2

Ile jest w tablicy wierszy, które mają sumę wartości swoich pól większą od zera? Ile jest takich kolumn? 

Dla pliku *points_test.txt* wynik to:

```
Wiersze: 10
Kolumny: 10
```

## Zadanie 3

Ile jest w tablicy pól, które mają wartość większą od jeden? 

Dla pliku *points_test.txt* wynik to 26.

## Zadanie 4

Jaka jest największa wartość pola w tablicy? Podaj wartość i współrzędne tego pola. Jeżeli jest kilka takich pól, podaj współrzędne ich wszystkich. 

Dla pliku *points_test.txt* wynik to:

```
Wartość: 4
Współrzędne:
1 6
2 10
7 4
7 10
```

## Zadanie 5

Ile jest takich pól w tablicy, które przylegają w pionie i poziomie wyłącznie do pól o wartości zero? 

Dla pliku *points_test.txt* wynik to 2.

## Zadanie 6

Policz, ile jest pól o wartości zero, ile o wartości jeden itd. aż do maksymalnej wartości w tablicy. 

Dla pliku *points_test.txt* wynik to:

```
Wartość 0: 40
Wartość 1: 34
Wartość 2: 16
Wartość 3: 6
Wartość 4: 4
```

## Zadanie 7

Policz sumę wartości:

- na głównej przekątnej (lewo góra -> prawo dół)
- na drugiej przekątnej (lewo dół -> prawo góra)
- pod główną przekątną (nie licząc elementów na przekątnej)
- nad główną przekątną (nie licząc elementów na przekątnej)

Dla pliku *points_test.txt* wynik to:

```
Główna przekątna: 10
Druga przekątna: 11
Pod główną przekątną: 33
Nad główną przekątną: 46
```

## Zadanie 8

Policz, ile jest w tablicy takich poddtablic o wymiarach $$2\times2$$, w których wartości pól się nie powtarzają.

Dla pliku *points_test.txt* wynik to 6.
