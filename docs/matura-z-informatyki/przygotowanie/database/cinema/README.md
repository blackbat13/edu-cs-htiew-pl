# Kino

## Wprowadzenie

W plikach *Filmy.txt*, *Klienci.txt, Miejsca.txt, Rezerwacje.txt, Rzedy.txt, Seanse.txt* znajdują się informacje dotyczące działalności kina, którą będziesz analizować.

### Filmy

{% file src="../../../../.gitbook/assets/cinema/Filmy.txt" %}
Filmy.txt
{% endfile %}

Plik *Filmy.txt* zawiera dane filmów - oddzielone średnikiem pozycje:

- *ID_Filmu* - unikalny identyfikator filmu,
- *Tytul* - tytuł filmu.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Klienci

{% file src="../../../../.gitbook/assets/cinema/Klienci.txt" %}
Klienci.txt
{% endfile %}

Plik *Klienci.txt* zawiera dane klientów - oddzielone średnikiem pozycje:

- *ID_Klienta* - unikalny identyfikator klienta,
- *Nazwisko* - nazwisko klienta.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Miejsca

{% file src="../../../../.gitbook/assets/cinema/Miejsca.txt" %}
Miejsca.txt
{% endfile %}

Plik *Miejsca.txt* zawiera dane miejsc - oddzielone średnikiem pozycje:

- *ID_Miejsca* - unikalny identyfikator miejsca,
- *Numer* - numer miejsca,
- *ID_Rzedu* - identyfikator rzędu, w którym to miejsce się znajduje.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Rezerwacje

{% file src="../../../../.gitbook/assets/cinema/Rezerwacje.txt" %}
Rezerwacje.txt
{% endfile %}

Plik *Rezerwacje.txt* zawiera dane dotyczące rezerwacji dokonanych przez klientów kina - oddzielone średnikiem pozycje:

- *ID_Rezerwacji* - unikalny identyfikator rezerwacji,
- *ID_Seansu* - identyfikator seansu,
- *ID_Miejsca* - identyfikator miejsca,
- *ID_Klienta* - identyfikator klienta.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Rząd

{% file src="../../../../.gitbook/assets/cinema/Rzad.txt" %}
Rzad.txt
{% endfile %}

Plik *Rezerwacje.txt* zawiera dane rzędów - oddzielone średnikiem pozycje:

- *ID_Rzedu* - unikalny identyfikator rzędu,
- *Numer* - numer rzędu.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Seanse

{% file src="../../../../.gitbook/assets/cinema/Seanse.txt" %}
Seanse.txt
{% endfile %}

Plik *Seanse.txt* zawiera dane seansów - oddzielone średnikiem pozycje:

- *ID_Seansu* - unikalny identyfikator seansu,
- *ID_Filmu* - identyfikator filmu,
- *Termin* - termin seansu będący jego datą oraz godziną rozpoczęcia, podany w formacie **R-M-D**.

Pierwszy wiersz zawiera nagłówki kolumn. 

## Zadania

Zacznij od stworzenia tabel *Filmy*, *Klienci*, *Miejsca*, *Rezerwacje*, *Rzedy* oraz *Seanse* importując dane z odpowiednich, wymienionych wyżej plików tekstowych. W każdej z tabel zdefiniuj odpowiedni **klucz podstawowy** (na podstawie pola istniejącego już w tabeli, albo nowo utworzonego). Utwórz odpowiednie **relacje** pomiędzy tabelami.

### Zadanie 1

Wypisz identyfikatory i nazwiska wszystkich klientów, których nazwiska kończą się na literę **a**. Wynik posortuj rosnąco po numerze identyfikatorze. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 2

Wyświetl tytuły wszystkich filmów, które w swoim zapisie posiadają literę **o** lub **O**. Wynik posortuj rosnąco po tytule filmu.

### Zadanie 3

Wyświetl identyfikatory wszystkich rezerwacji klienta o nazwisku **Augustyniak**.

### Zadanie 4

Wypisz identyfikatory wszystkich seansów, które zostały wyświetlone 9 stycznia 2016 roku.

### Zadanie 5

Wyświetl tytuły wszystkich filmów, które były wyświetlane po godz. 21:00. 

### Zadanie 6

Dla każdego klienta wypisz jego identyfikator, nazwisko oraz liczbę dokonanych rezerwacji. Wynik posortuj alfabetycznie po nazwisku. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 7

Dla każdego seansu wypisz tytuł wyświetlanego filmu oraz liczbę dokonanych na ten seans rezerwacji. Wynik posortuj malejąco po liczbie rezerwacji i rosnąco po tytule. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 8

Dla każdego filmu wypisz jego tytuł oraz liczbę wyświetleń. Wynik posortuj alfabetycznie po tytule. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 9

Wypisz numer rzędu, w którym miejsca były najczęściej rezerwowane.

### Zadanie 10

Podaj nazwiska 5 klientów rezerwujących największą liczbę miejsc.

### Zadanie 11

Dla każdej rezerwacji wypisz *id rezerwacji*, *nazwę filmu*, *numer rzędu*, *numer miejsca*, *nazwisko klienta* oraz *termin rozpoczęcia seansu*. Wynik posortuj rosnąco po identyfikatorze rezerwacji. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 12

Dla każdego seansu wypisz *id seansu*, *id filmu*, *rok wyświetlenia seansu*, *miesiąc wyświetlenia seansu* oraz *dzień wyświetlenia seansu*. Wynik posortuj rosnąco po identyfikatorze seansu. Podaj pierwszy i ostatni wiersz wyniku.
