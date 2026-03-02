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

