# Komandosi

Rozważmy następującą bazę danych:

```mermaid
erDiagram
    Misje }o--|| Komandosi : ""
    KomandosiNaMisji }o--|| Komandosi : ""
    KomandosiNaMisji }o--|| Misje : ""
    UmiejetnosciKomandosow }o--|| Komandosi : ""
    UmiejetnosciKomandosow }o--|| UmiejetnosciSpecjalne : ""

    Komandosi {
        INTEGER id PK
        TEXT imie
        TEXT nazwisko
        TEXT stopien
    }
    Misje {
        INTEGER id PK
        TEXT nazwa
        INTEGER numer_dowodcy FK
        INTEGER liczba_dni_misji
        DATE data_misji
    }
    KomandosiNaMisji {
        INTEGER numer_komandosa FK
        INTEGER numer_misji FK
    }
    UmiejetnosciSpecjalne {
        INTEGER id PK
        TEXT nazwa
    }
    UmiejetnosciKomandosow {
        INTEGER numer_komandosa FK
        INTEGER numer_umiejetnosci FK
    }
```

Podaj instrukcje SQL realizujące poniższe zadania.

## Zadanie 1

Wypisz imię i nazwisko każdego porucznika.

## Zadanie 2

Policz, ile misji odbyło się w maju.

## Zadanie 3

Wypisz imię i nazwisko każdego komandosa, który był dowódcą na misji. Posortuj po nazwisku i imieniu.

## Zadanie 4

Dla każdego komandosa wypisz jego umiejętności specjalne.

## Zadanie 5

Dla każdej misji policz, ilu komandosów brało w niej udział.

## Zadanie 6

Dla każdego komandosa wypisz, ile łącznie spędził dni na misjach.

## Zadanie 7

Dla każdej misji wypisz, ilu saperów brało w niej udział.
