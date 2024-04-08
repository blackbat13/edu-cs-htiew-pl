# Sklep

Dana jest baza danych dotycząca sklepu, jego klientów i prowadzonej sprzedaży, zgodnie z opisem podanym poniżej.

## Opis plików

### Artykuły

[:material-note-text: artykuly.txt](../../../../assets/shop/artykuly.txt)

Plik **artykuly.txt** zawiera dane sprzedawanych towarów – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny produktu,
- *nazwa* - nazwa produktu,
- *cena* - liczba rzeczywista z dwoma miejscami po przecinku, cena za kg.

Pierwszy wiersz zawiera nagłówki kolumn.

### Klienci

[:material-note-text: klienci.txt](../../../../assets/shop/klienci.txt)

Plik **klienci.txt** zawiera dane klientów sklepu – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny klienta,
- *Imie* - imię klienta,
- *Nazwisko* - nazwisko klienta,
- *Miasto* - miasto zamieszkania klienta,
- *Ulica* - ulica zamieszkania klienta,
- *Kod pocztowy* - kod pocztowy.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Zamówienia

[:material-note-text: zamowienia.txt](../../../../assets/shop/zamowienia.txt)

Plik **zamowienia.txt** zawiera dane złożonych przez klientów zamówień – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny zamówienia,
- *Artykul id* - numer identyfikacyjny artykułu,
- *Klient id* - numer identyfikacyjny klienta,
- *Liczba kg* - liczba zamówionych kilogramów.
- *Data zamówienia* - data zamówienia w formacie "RRRR-MM-DD".

Pierwszy wiersz zawiera nagłówki kolumn.

## Zadania

## Zadanie 1

Podaj imię i nazwisko klienta (klientów), który zapłacił łącznie najwięcej za swoje zamówienia. Pamiętaj, że koszt jednego zamówienia, to liczba zamówionych kilogramów przemnożona przez cenę za kg.

## Zadanie 2

Podaj imiona i nazwiska wszystkich klientów, którzy nie złożyli żadnego zamówienia.

## Zadanie 3

Podaj nazwy wszystkich artykułów, które nie zostały w ogóle zamówione.

## Zadanie 4

Podaj ile artykułów **nie** zostało zamówionych w 2021 roku

## Zadanie 5

Znajdź miesiąc (ignorując rok), w którym było najwięcej zamówień. Podaj nazwę tego miesiąca i liczbę zamówień w tym miesiącu. Jeżeli jest kilka takich miesięcy, podaj wszystkie.

## Zadanie 6

Podaj nazwę miejscowości, której mieszkańcy zamówili łącznie najwięcej kg artykułów. Podaj także łączną wagę artykułów, które zamówili mieszkańcy z tej miejscowości. Jeżeli jest kilka takich miejscowości, podaj wszystkie.

## Zadanie 7

Podaj ile łącznie zamówień złożyli klienci, u których w **dwóch pierwszych** cyfrach kodu pocztowego występuje cyfra **8**.

## Zadanie 8

Zakładając, że imię żeńskie kończy się zawsze na literę **a**, podaj liczbę zamówień, łączną liczbę zamówionych kilogramów, sumaryczny koszt zamówień oraz średni koszt zamówień (z dokładnością do dwóch cyfr po przecinku) z podziałem na kobiety i mężczyzn.

## Zadanie 9

Zakładając, że imię żeńskie kończy się zawsze na literę **a**, podaj który artykuł był najczęściej zamawiany przez kobiety, a który przez mężczyzn.

## Zadanie 10

Znajdź klienta (klientów), który złożył zamówienie na największą ilość różnych artykułów. Podaj imię, nazwisko i liczbę unikalnych artykułów, które zamówił.

## Zadanie 11

Oblicz średnią wartość zamówienia dla każdego miasta. Podaj nazwy miast wraz ze średnią wartością zamówienia, w których ta wartość jest największa oraz te, w których jest ona najmniejsza.

## Zadanie 12

Podaj imię i nazwisko klienta (klientów), który złożył pierwsze zamówienie oraz klienta (klientów), który złożył ostatnie zamówienie. Podaj także daty tych zamówień.

## Zadanie 13

Dla każdego artykułu oblicz liczbę zamówień oraz średnią liczbę zamówionych kilogramów na zamówienie, z dokładnością do dwóch cyfr po przecinku. Podaj nazwę, liczbę zamówień oraz średnią liczbę zamówień artykułu (artykułów), który był najczęściej zamawiany oraz tego, który był najrzadziej zamawiany.

## Zadanie 14

Podaj ile artykułów miało w 2021 roku większą łączną sprzedaż w kg w 2020 roku.

## Zadanie 15

Oblicz i porównaj łączną wartość zamówień złożonych przez klientów z kodem pocztowym zaczynającym się na cyfrę "1" oraz klientów z kodem pocztowym zaczynającym się na cyfrę "2". Podaj, która grupa klientów wydała więcej.

## Zadanie 16

Podaj ile klientów ma kod pocztowy kończący się na cyfrę parzystą, a ile na nieparzystą.

## Zadanie 17

Zamówienia dzielimy pod względem zamówionej liczby kg na:

- *małe* - poniżej 10 kg,
- *średnie* - od 11 do 30 kg,
- *duże* - powyżej 30 kg.

Podaj łączną liczbę zamówień dla każdej z kategorii.
