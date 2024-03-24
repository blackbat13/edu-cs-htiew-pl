# Wypożyczalnia samochodów

## Wprowadzenie

Wypożyczalnia samochodów WYPSA posiada bazy w kilku miejscowościach: Aniołkowo, Manipulatowo, Nieszczerzyn, Piarowa, Wielka Wola. W każdej z baz wypożyczyć można samochód typu B, C lub D (rosnąca wielkość, stopień luksusu i cena za wypożyczenie). Płaci się za każdą rozpoczętą dobę. Poniższe pliki zawierają dane z działalności wypożyczalni w pierwszym półroczu 2015 roku.

### Samochody

{% file src="../../../../.gitbook/assets/wypsa/samochody.txt" %}
samochody.txt
{% endfile %}

Plik **samochody.txt** zawiera dane samochodów – oddzielone średnikiem pozycje: 

- *Nr ew.* - numer ewidencyjny samochodu, jednoznacznie identyfikujący samochód,
- *Nr firm* - zaczyna się literą określającą typ samochodu, jego dalszą częścią jest pewien numer,
- *Macierzysta* - określa macierzystą miejscowość, z której pochodzi samochód,
- *Nr rej* - numer rejestracyjny samochodu, zaczynający się dwiema pierwszymi literami nazwy macierzystej miejscowości.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Ceny

{% file src="../../../../.gitbook/assets/wypsa/ceny.txt" %}
ceny.txt
{% endfile %}

Plik **ceny.txt** zawiera ceny za dobę wypożyczenia samochodu odpowiedniego typu – oddzielone średnikiem pozycje:

- *Typ* - typ samochodu,
- *Cena* - cena za dobę wypożyczenia.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Klienci

{% file src="../../../../.gitbook/assets/wypsa/klienci.txt" %}
klienci.txt
{% endfile %}

Plik **klienci.txt** zawiera dane klientów– oddzielone średnikiem pozycje:

- *Numer Klienta* - jednoznaczny identyfikator klienta,
- *Imie* - imię klienta,
- *Nazwisko* - nazwisko klienta.

Pierwszy wiersz zawiera nagłówki kolumn. 

### Wypożyczenia

{% file src="../../../../.gitbook/assets/wypsa/wypozyczenia.txt" %}
wypozyczenia.txt
{% endfile %}

Plik **wypozyczenia.txt** zawiera dane o wypożyczeniach - oddzielone średnikiem pozycje:

- *Samochod* - numer ewidencyjny samochodu,
- *Klient* - numer klienta,
- *Wypozyczenie* - data wypożyczenia,
- *Zwrot* - data zwrotu.

Pierwszy wiersz zawiera nagłówki kolumn. Data podana jest w formacie rok-miesiąc-dzień.

## Zadania

Zacznij od stworzenia tabel *Samochody*, *Ceny*, *Klienci* oraz *Wypozyczenia* importując dane z odpowiednich, wymienionych wyżej plików tekstowych. W każdej z tabel zdefiniuj odpowiedni **klucz podstawowy** (na podstawie pola istniejącego już w tabeli, albo nowo utworzonego). Utwórz odpowiednie **relacje** pomiędzy tabelami.

### Przydatne funkcje

- Obliczenie różnicy w dniach pomiędzy dwoma datami: `DateDiff(„d”; #20.05.2015#; #23.05.2015#) = 3`.
- Pobranie pierwszych liter wyrazu: `Left(„abc”; 2) = „ab”` – funkcja zwraca wybraną liczbę liter z początku wyrazu.

### Zadanie 1

Dla każdego samochodu z tabeli *Samochody* wypisz jego numer ewidencyjny, numer firmowy oraz cenę wypożyczenia za dobę. Wyniki posortuj rosnąco po numerze ewidencyjnym. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 2

Wypisz numer, imię oraz nazwisko klientów, których **nazwisko** zaczyna się na literę **A**. Wyniki posortuj rosnąco po nazwisku.

### Zadanie 3

Wypisz numer, imię oraz nazwisko klientów, których **imię** zawiera co najmniej jedną literę **b** lub **B**. Wyniki posortuj rosnąco najpierw po nazwisku, następnie po imieniu. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 4

Podaj liczbę samochodów, które zostały wypożyczone **przed** 23 lutym 2015 roku (datę podajemy ograniczoną znakami #, np.: `#23.02.2015#`).

### Zadanie 5

Dla każdego wypożyczenia wypisz jego datę rozpoczęcia, zakończenia oraz długość trwania wypożyczenia wyrażoną w dniach. Wyniki posortuj rosnąco najpierw po dacie rozpoczęcia, następnie po dacie zakończenia oraz długości trwania w dniach. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 6

Dla każdego klienta wypisz jego imię, nazwisko oraz liczbę dokonanych wypożyczeń. Wyniki posortuj rosnąco po nazwisku i liczbie wypożyczeń. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 7

Dla każdego klienta wypisz jego imię, nazwisko oraz sumaryczny czas wszystkich jego wypożyczeni, podany w dniach. Wyniki posortuj rosnąco po nazwisku i czasie wypożyczeń. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 8

Dla każdego klienta, który wypożyczył co najmniej dwa **różne** samochody, wypisz jego imię, nazwisko oraz liczbę wypożyczonych, różnych samochodów. Wyniki posortuj rosnąco po nazwisku i liczbie wypożyczeń. Podaj pierwszy i ostatni wiersz wyniku.

### Zadanie 9

Podaj numer ewidenyjny, rejestracyjny oraz liczbę wypożyczeń najczęściej wypożyczanego samochodu.

### Zadanie 10

Wypisz numer ewidencyjny, rejestracyjny oraz sumaryczną długość wypożyczeń w dniach wszystkich samochodów z miejscowości *Wielka Wola*. Wyniki posortuj malejąco po długości wypożyczeń oraz rosnąco po numerze ewidencyjnym. Podaj pierwszy i ostatni wiersz wyniku.
