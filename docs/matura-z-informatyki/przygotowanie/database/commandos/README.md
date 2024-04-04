# Komandosi

Dana jest baza danych dotycząca komandosów i ich udziałów w różnych misjach, zgodnie z opisem podanym poniżej.

## Opis plików

### Komandosi

[:material-note-text: komandosi.txt](../../../../assets/commandos/komandosi.txt)

Plik **komandosi.txt** zawiera dane komandosów – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny komandosa,
- *Imie* - imię komandosa,
- *Nazwisko* - nazwisko komandosa,
- *Stopien* - stopien komandosa.

Pierwszy wiersz zawiera nagłówki kolumn.

### Misje

[:material-note-text: misje.txt](../../../../assets/commandos/misje.txt)

Plik **misje.txt** zawiera dane misji – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny misji,
- *Kryptonim* - kryptonim misji,
- *Numer dowodcy* - numer dowodcy misji, identyfikator jednego z komandosów,
- *Liczba dni* - długość trwania misji w dniach,
- *Data misji* - data rozpoczęcia misji.

Pierwszy wiersz zawiera nagłówki kolumn. Daty podane są w formacie "RRRR-MM-DD".

### Komandosi na misji

[:material-note-text: komandosi_na_misji.txt](../../../../assets/commandos/komandosi_na_misji.txt)

Plik **komandosi_na_misji.txt** zawiera dane udziału komandosów w misjach – oddzielone średnikiem pozycje:

- *Numer komandosa* - numer identyfikacyjny komandosa,
- *Numer misji* - numer identyfikacyjny misji.

Pierwszy wiersz zawiera nagłówki kolumn.

### Umiejętności specjalne

[:material-note-text: umiejetnosci_specjalne.txt](../../../../assets/commandos/umiejetnosci_specjalne.txt)

Plik **umiejetnosci_specjalne.txt** zawiera dane umiejętności specjalnych – oddzielone średnikiem pozycje:

- *Id* - unikalny numer identyfikacyjny umiejętności specjalnej,
- *Nazwa* - nazwa umiejętności specjalnej.

Pierwszy wiersz zawiera nagłówki kolumn.

### Umiejętności komandosów

[:material-note-text: umiejetnosci_komandosow.txt](../../../../assets/commandos/umiejetnosci_komandosow.txt)

Plik **umiejetnosci_komandosow.txt** zawiera dane umiejętności specjalnych komandosów – oddzielone średnikiem pozycje:

- *Numer komandosa* - numer identyfikacyjny komandosa,
- *Numer umiejetnosci* - numer identyfikacyjny umiejętności specjalnej.

Pierwszy wiersz zawiera nagłówki kolumn.

## Zadania

## Zadanie 1

Utwórz zestawienie zawierające imię i nazwisko każdego **porucznika**, posortowane alfabetycznie po nazwisku. Podaj imię i nazwisko pierwszego i ostatniego porucznika.

## Zadanie 2

Podaj, ile misji odbyło się w maju.

## Zadanie 3

Podaj ilu komandosów **nie** było dowódcą na żadnej misji. Podaj imię i nazwisko każdego takiego komandosa. Wynik posortuj alfabetycznie po nazwisku.

## Zadanie 4

Podaj identyfikatory, imiona i nazwiska wszystkich komandosów, którzy mają **najwięcej** umiejętności specjalnych.

## Zadanie 5

Podaj identyfikatory i kryptonimy misji, w których brało udział najwięcej komandosów.

## Zadanie 6

Podaj identyfikatory i kryptonimy misji, w których nie brał udziału (tzn. nie był także dowódcą) żaden major o specjalności innej niż *Specjalista IT*.

## Zadanie 7

Podaj identyfikatory, imiona i nazwiska wszystkich komandosów, którzy łącznie spędzili na misjach najwięcej czasu.

## Zadanie 8

Podaj kryptonim (lub kryptonimy) misji, która zakończyła się najpóźniej oraz kryptonim (lub kryptonim) misji, która zakończyła się najwcześniej.