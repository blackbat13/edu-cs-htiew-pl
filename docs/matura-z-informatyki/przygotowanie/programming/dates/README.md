# Daty

W pliku *dates.txt* znajduje się 1000 linii, każda zawierająca trzy liczby naturalne oddzielone spacją. Liczby te reprezentują daty. Rok jest liczbą naturalną z przedziału od 100 do 3000, miesiąc jest liczbą naturalną z przedziału od 1 do 12, a dzień jest liczbą naturalną z przedziału od 1 do 31. Daty podane są w losowej kolejności, tzn. nie wiadomo, na którym miejscu występuje dzień, miesiąc i rok.

[:material-note-text: dates.txt](../../../../assets/dates/dates.txt)

Plik *dates_test.txt* zawiera 100 linii tak jak opisano powyżej.

[:material-note-text: dates_test.txt](../../../../assets/dates/dates_test.txt)

## Zadanie 1

Oblicz ile dat z pliku zawiera rok przestępny. Rok przestępny to taki, który dzieli się przez 4, ale nie dzieli się przez 100, chyba że również dzieli się przez 400.

Dla pliku *dates_test.txt* odpowiedź to 18.

## Zadanie 2

W podanych w pliku datach możemy łatwo stwierdzić, która z wartości reprezentuje rok, jednak która z pozostałych dwóch liczb reprezentuje miesiąc, a która dzień, nie zawsze jest możliwe do stwierdzenia. Jeżeli jedna z tych dwóch liczb jest wartością większą nież 12, to wiemy, że musi reprezentować dzień. Powiemy wówczas, że interpretacja takiej daty jest **jednoznaczna**. Oblicz, ile dat z pliku ma jednoznaczną interpretację.

Dla pliku *dates_test.txt* odpowiedź to 52.

## Zadanie 3

Dla każdej daty przyjmij następującą interpretację: największa liczba to rok, najmniejsza to miesiąc, a środkowa to dzień. Podaj najstarszą i najmłodszą datę.

Dla pliku *dates_test.txt* odpowiedź to:

- najstarsza data: 03-03-105
- najmłodsza data: 25-12-3000

## Zadanie 4

Przyjmując interpretację dat z zadania 3, podaj miesiąc, który najczęściej występuje w zestawieniu. Jeżeli jest takich kilka, podaj wszystkie. Podaj także, ile razy wystąpił.

Dla pliku *dates_test.txt* odpowiedź to:

- miesiąc, który najczęściej występuje: 1
- liczba wystąpień: 13

## Zadanie 5

Spójnym podciągiem rosnącym nazwiemy ciąg występujących bezpośrednio po sobie kolejnych elementów, taki że każdy kolejny element jest **większy** pod poprzedniego. 

Patrząc wyłącznie na lata, podaj długość najdłuższego spójnego podciągu rosnącego, który tworzą kolejne lata. Podaj pierwszy i ostatni rok w takim podciągu. Jeżeli jest kilka takich podciągów, podaj pierwszy z nich, zgodnie z kolejnością w pliku.

Dla pliku *dates_test.txt* odpowiedź to:

- długość najdłuższego spójnego podciągu rosnącego: 4
- pierwszy rok: 372
- ostatni rok: 2834

## Zadanie 6

Przyjmując interpretację dat z zadania 3, podaj ile jest **par** dat, że jak zsumujemy ich miesiące i zsumujemy ich dni to dostaniemy wartości mieszczące się w zakresach odpowiednio $[1,12]$ oraz $[1,31]$.

Dla pliku *dates_test.txt* odpowiedź to 1909.