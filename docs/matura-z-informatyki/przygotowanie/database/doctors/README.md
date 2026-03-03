# Lekarze

Dana jest baza danych dotycząca przychodni lekarskiej, zgodnie z opisem podanym poniżej.

## Opis plików

### Lekarze

[:material-note-text: lekarze.txt](../../../../assets/exam/db/doctors/lekarze.txt)

Plik **lekarze.txt** zawiera dane lekarzy – oddzielone średnikiem pozycje:

- *Id_lekarza* - unikalny numer identyfikacyjny lekarza,
- *Imie* - imię lekarza,
- *Nazwisko* - nazwisko lekarza,
- *Specjalizacja* - specjalizacja lekarza.

Pierwszy wiersz zawiera nagłówki kolumn.

### Pacjenci

[:material-note-text: pacjenci.txt](../../../../assets/exam/db/doctors/pacjenci.txt)

Plik **pacjenci.txt** zawiera dane pacjentów przychodni – oddzielone średnikiem pozycje:

- *Id_pacjenta* - unikalny numer identyfikacyjny pacjenta,
- *Imie* - imię pacjenta,
- *Nazwisko* - nazwisko pacjenta,
- *Pesel* - numer pesel pacjenta.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Wizyty

[:material-note-text: wizyty.txt](../../../../assets/exam/db/doctors/wizyty.txt)

Plik **wizyty.txt** zawiera dane dotyczące wizyt w przychodni – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny wizyty,
- *Id_lekarza* - numer identyfikacyjny lekarza,
- *Id_pacjenta* - numer identyfikacyjny pacjenta,
- *Data* - data wizyty w formacie "RRRR-MM-DD",
- *Typ_wizyty* - typ wizyty.

Pierwszy wiersz zawiera nagłówki kolumn.

## Zadania

## Zadanie 1

Podaj imiona i nazwiska wszystkich lekarzy, którzy **nie mieli** wizyt w 2025 roku. Wyniki posortuj alfabetycznie po nazwisku.

## Zadanie 2

Podaj ilu pacjentów **nie miało** zabiegu ani rehabilitacji w pierwszej połowie dowolnego roku (pierwsze 6 miesięcy).

## Zadanie 3

Podaj imiona i nazwiska pacjentów, którzy urodzili się w latach 1990-1999 (dwie pierwsze cyfry numeru PESEL to 90-99). Wyniki posortuj alfabetycznie po nazwisku.

## Zadanie 4

Podaj imiona i nazwiska pacjentów, którzy urodzili się w lipcu (trzecia i czwarta cyfra numeru PESEL to 07) oraz **nie mieli** żadnej wizyty u kardiologa. Wyniki posortuj alfabetycznie po nazwisku.

## Zadanie 5

Podaj liczbę wizyt dla każdej specjalizacji lekarzy. Wyniki posortuj malejąco po liczbie wizyt.

## Zadanie 6

Dla każdej specjalizacji lekarzy podaj liczbę **różnych** pacjentów, którzy mieli wizytę u lekarza o danej specjalizacji. Wyniki posortuj malejąco po liczbie pacjentów.
