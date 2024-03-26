# Imiona

W pliku *names.txt* znajduje się $100$ imion złożonych wyłącznie z liter alfabetu angielskiego, każde zapisane w osobnym wierszu. Imiona mogą się powtarzać.

[:material-note-text: names.txt](../../../../assets/names/names.txt)

W pliku *names_test.txt* znajduje się $10$ wierszy, jak opisano powyżej.

[:material-note-text: names_test.txt](../../../../assets/names/names_test.txt)

Napisz program/programy rozwiązujące poniższe zadania.

## Zadanie 1

Podaj, ile imion z pliku *names.txt* **zaczyna** się na literę **B**. Dla danych z pliku *names_test.txt* wynik to $1$.

## Zadanie 2

Podaj, ile imion w pliku *names.txt* **kończy** się na literę **a**. Dla danych z pliku *names_test.txt* wynik to $3$.

## Zadanie 3

Podaj, ile imion w pliku *names.txt* **zaczyna** się samogłoską. Dla danych z pliku *names_test.txt* wynik to $1$.

## Zadanie 4

Podaj, ile imion w pliku *names.txt* **zaczyna** się spółgłoską i **jednocześnie** **kończy** się samogłoską. Dla danych z pliku *names_test.txt* wynik to $4$.

## Zadanie 5

Podaj, ile imion w pliku *names.txt* zawiera w **środku** (pomijamy pierwszą i ostatnią literę) literę **e**. Dla danych z pliku *names_test.txt* wynik to $3$.

## Zadanie 6

Podaj wszystkie imiona z pliku *names.txt*, które zawierają więcej niż jedną literę **a** lub **A**. Dla danych z pliku *names_test.txt* wynik to:

```
Laura
Anna
```

## Zadanie 7

Podaj wszystkie imiona z pliku *names.txt*, które **nie** zawierają liter **a**, **A**. Dla danych z pliku *names_test.txt* wynik to:

```
Bob
Jeffrey
```

## Zadanie 8

Podaj wszystkie imiona z pliku *names.txt*, które zawierają dwie identyczne (także ze względu na wielkość) litery występujące obok siebie. Dla danych z pliku *names_test.txt* wynik to:

```
Jessica
Jeffrey
Anna
```

## Zadanie 9

Wypisz wszystkie imiona z pliku *names.txt*, które zawierają najwięcej samogłosek. Wynik podaj w kolejności alfabetycznej. Dla danych z pliku *names_test.txt* wynik to:

```
Jeffrey
Jessica
Laura
```

## Zadanie 10

Podaj długość najkrótszego i najdłuższego imienia w pliku *names.txt*. Podaj wszystkie imiona o tych długościach. Dla danych z pliku *names_test.txt* wynik to:

```
Najkrótsze imiona
Długość: 3
Imiona: Bob

Najdłuższe imiona
Długość: 7
Imiona: Crystal, Jessica, Jeffrey
```
 
## Zadanie 11

Podaj liczbę imion z pliku *names.txt* po usunięciu duplikatów. Dla danych z pliku *names_test.txt* wynik to $9$

## Zadanie 12

Podaj wszystkie imiona z pliku *names.txt*, które występują w pliku **dokładnie raz**. Wynik uporządkuj alfabetycznie. Dla danych z pliku *names_test.txt* wynik to:

```
Anna
Bob
Crystal
Dave
Jeffrey
Jessica
Laura
Megan
```

## Zadanie 13

Podaj imię/imiona z pliku *names.txt*, które występuje/ą najczęściej. Dla danych z pliku *names_test.txt* wynik to:

```
Marvin
```

## Zadanie 14

Podaj wszystkie imiona z pliku *names.txt*, w których zapisie litery się **nie powtarzają**, ignorując przy tym wielkość liter. Wynik uporządkuj alfabetycznie. Dla danych z pliku *names_test.txt* wynik to:

```
Crystal
Dave
Marvin
Marvin
Megan
```

## Zadanie 15

Dla każdego imienia z pliku *names.txt* policz sumę kodów ASCII jego liter. Podaj najmniejszą i największą sumę, a także wszystkie imiona z pliku, które mają taką sumę. Dla danych z pliku *names_test.txt* wynik to:

```
Najmniejsza suma ascii: 275
Imiona: Bob

Największa suma ascii: 738
Imiona: Crystal
```

## Zadanie 16

Podaj najdłuższy wspólny podciąg rosnący z pliku *names.txt*, składający się z sąsiednich imion, które są uporządkowane alfabetycznie ściśle rosnąco. Podaj także długość tego podciągu, a także numery imion, na których się ten podciąg zaczyna i kończy. Jeżeli jest kilka takich podciągów, podaj pierwszy z nich. Dla danych z pliku *names_test.txt* wynik to:

```
Liczba imion: 4
Początek sekwencji: 5
Koniec sekwencji: 8
Najdłuższa sekwencja rosnących imion:
Dave
Jeffrey
Laura
Marvin
```
