# Wampiry

## Wprowadzenie

Pan Józef von Stąd jest znanym badaczem wampirów. Od wielu lat prowadzi zapiski dotyczące tych niezwykłych stworzeń, które zebrał i zapisał w kilku plikach tekstowych, opisanych poniżej.

### Klany

[:material-note-text: Klany.txt](../../../../assets/vampires/Klany.txt)

Plik **Klany.txt** zawiera dane klanów – oddzielone średnikiem pozycje: 

- *KlanID* - numer identyfikacyjny klanu,
- *Nazwa* - nazwa klanu,
- *DataZalozenia* - data założenia klanu,
- *KrajPochodzenia* - kraj, w którym klan został założony.

Pierwszy wiersz zawiera nagłówki kolumn. Daty podane są w formacie "DD.MM.RRRR".

### Wampiry

[:material-note-text: Wampiry.txt](../../../../assets/vampires/Wampiry.txt)

Plik **Wampiry.txt** zawiera dane klanów – oddzielone średnikiem pozycje: 

- *WampirID* - numer identyfikacyjny wampira,
- *Imie* - imię wampira,
- *DataUrodzenia* - data urodzenia wampira,
- *DataPrzemiany* - data przemiany w wampira,
- *KrajPochodzenia* - kraj pochodzenia wampira,
- *KlanID* - numer identyfikacyjny klanu, do którego wampir przynależy.

Pierwszy wiersz zawiera nagłówki kolumn. Daty podane są w formacie "DD.MM.RRRR".

### Ofiary

[:material-note-text: Ofiary.txt](../../../../assets/vampires/Ofiary.txt)

Plik **Ofiary.txt** zawiera dane klanów – oddzielone średnikiem pozycje: 

- *OfiaraID* - numer identyfikacyjny ofiary,
- *Imie* - imię ofiary,
- *DataUrodzenia* - data urodzenia,
- *DataZgonu* - data zgonu.

Pierwszy wiersz zawiera nagłówki kolumn. Daty podane są w formacie "DD.MM.RRRR".

### Ataki

[:material-note-text: Ataki.txt](../../../../assets/vampires/Ataki.txt)

Plik **Ataki.txt** zawiera dane klanów – oddzielone średnikiem pozycje: 

- *AtakID* - numer identyfikacyjny ataku,
- *WampirID* - numer identyfikacyjny wampira, który dokonał ataku,
- *OfiaraID* - numer identyfikacyjny ofiary ataku,
- *DataAtaku* - data ataku,
- *Lokalizacja* - lokalizacja ataku, jedna z trzech wartości:
  - "Wampir" - atak miał miejsce w kraju pochodzenia wampira,
  - "Klan" - atak miał miejsce w kraju założenia klanu,
  - "Zagranica" - atak miał miejsce w innym kraju, niezwiązanym z wampirem ani klanem (takie miejsca nie interesują Pana Józefa).

Pierwszy wiersz zawiera nagłówki kolumn. Daty podane są w formacie "DD.MM.RRRR".

## Zadania

Zacznij od stworzenia tabel *Klany*, *Wampiry*, *Ofiary* oraz *Ataki* importując dane z odpowiednich, wymienionych wyżej plików tekstowych. W każdej z tabel zdefiniuj odpowiedni **klucz podstawowy** (na podstawie pola istniejącego już w tabeli, albo nowo utworzonego). Utwórz odpowiednie **relacje** pomiędzy tabelami.

### Zadanie 1

Wypisz, w kolejności alfabetycznej, imiona wszystkich wampirów pochodzących z Rumunii.

### Zadanie 2

Utwórz zestawienie zawierające imię wampira oraz liczbę dokonanych przez niego ataków. Wyniki posortuj rosnąco po liczbie ataków.

### Zadanie 3

Utwórz zestawienie zawierające imię wampira, datę przemiany oraz datę pierwszego ataku. Wyniki posortuj rosnąco po czasie, jaki upłynął od przemiany do pierwszego ataku. Wypisz tylko te wampiry, które dokonały co najmniej jednego ataku.

### Zadanie 4

Wypisz imiona wszystkich wampirów, które nie dokonały żadnego ataku. Wynik posortuj alfabetycznie po imionach.

### Zadanie 5

Wypisz imię wampira, który musiał najdłużej czekać na przemianę od swoich urodzin. Jeżeli jest kilku takich wampirów, wypisz wszystkich.

### Zadanie 6

Utwórz zestawienie zawierające imię ofiary, datę ataku, imię wampira, który dokonał ataku, oraz nazwę klanu, do którego należy wampir.

### Zadanie 7

Utwórz zestawienie zawierające imię ofiary oraz liczbę ataków, które zostały na nią przeprowadzone. Posortuj alfabetycznie po imionach.

### Zadanie 8

Wypisz imiona wszystkich ofiar, które zginęły bezpośrednio w wyniku ataku, tzn. data jednego z ataków przeprowadzonego na daną ofiarę jest równa jej dacie zgonu. Posortuj alfabetycznie po imionach.

### Zadanie 9

Utwórz zestawienie zawierające nazwę kraju, liczbę wampirów pochodzących z tego kraju, liczbę klanów założonych w tym kraju, oraz liczbę ataków przeprowadzonych w tym kraju. Posortuj alfabetycznie po nazwie kraju.

### Zadanie 10

Wypisz nazwy wszystkich klanów, które nie posiadają członków. Posortuj alfabetycznie po nazwach.

### Zadanie 11

Utwórz zestawienie zawierające imię wampira oraz zaokrąglone w górę: liczbę dni, liczbę miesięcy i liczbę lat, które upłynęły od urodzin do przemiany. Wyniki posortuj alfabetycznie po imionach.

### Zadanie 12

Utwórz zestawienie zawierające imię wampira, jego datę urodzenia, datę przemiany oraz wiek wampira w momencie przemiany. Wyniki posortuj alfabetycznie po imionach.

### Zadanie 13

Utwórz zestawienie zawierające imię ofiary oraz liczbę dni, które upłynęły od pierwszego do ostatniego ataku.
