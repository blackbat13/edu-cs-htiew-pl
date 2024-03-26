# Sklep

Rozważmy następującą bazę danych:

```mermaid
erDiagram
    Zamowienia }o--|| Artykuly : ""
    Zamowienia }o--|| Klienci : ""
    Artykuly {
        INTEGER id_art PK
        TEXT nazwa
        REAL cena
    }
    Klienci {
        INTEGER id_kl PK
        TEXT imie
        TEXT nazwisko
        TEXT miasto
        TEXT ulica
        TEXT kod_pocztowy
    }
    Zamowienia {
        INTEGER id_zam PK
        INTEGER id_art FK
        INTEGER id_kl FK
        INTEGER liczba_sztuk
        DATE data_zam
    }
```

Tabela *Zamowienia* zawiera historię wszystkich złożonych zamówień na artykuły.

Podaj instrukcje SQL realizujące poniższe zadania.

## Zadanie 1

Podaj dane wszystkich zamówień, które zostały dokonane w maju 2015 roku.

## Zadanie 2

Podaj wszystkie imiona klientów kończące się na literę ‘a’.

## Zadanie 3

Podaj identyfikator, imię i nazwisko każdego klienta, który 18 marca 2016 roku dokonał co najmniej jednego zakupu.

## Zadanie 4

Dla każdego klienta podaj jego identyfikator, imię, nazwisko i sumaryczny koszt wszystkich jego zamówień. Dane posortuj alfabetycznie po nazwisku.

## Zadanie 5

Podaj identyfikator, imię i nazwisko każdego klienta, który dokonał przynajmniej jednego zamówienia przed 2010 rokiem.

## Zadanie 6

Dla każdego artykułu podaj jego identyfikator, nazwę oraz liczbę zamówień, które dotyczyły tego artykułu.

## Zadanie 7

Utwórz zestawienie zawierające nazwę miasta, id artykułu, nazwę artykułu oraz liczbę sztuk tego artykułu sprzedanych klientom z danego miasta, gdzie przekroczyła ona $100$ sztuk.

## Zadanie 8

Dla każdego artykułu podaj jego identyfikator, nazwę oraz liczbę sprzedanych egzemplarzy.

## Zadanie 9

Podaj identyfikatory i nazwy artykułów, których nikt nie zamówił.

## Zadanie 10

Podaj identyfikator, imię oraz nazwisko każdego klienta, który złożył dokładnie $2$ zamówienia na artykuły o *id_art* równym $10$ lub $20$.
