# WHERE

## Zadanie 1

Wypisz dane wszystkich klientów z Niemiec.

### Wynik

| CustomerId | FirstName | LastName   | Company | Address                 | City      | State | Country | PostalCode | Phone            | Fax  | Email                     | SupportRepId |
|------------|-----------|------------|---------|-------------------------|-----------|-------|---------|------------|------------------|------|---------------------------|--------------|
| 2          | Leonie    | Köhler     | null    | Theodor-Heuss-Straße 34 | Stuttgart | null  | Germany | 70174      | +49 0711 2842222 | null | leonekohler@surfeu.de     | 5            |
| 36         | Hannah    | Schneider  | null    | Tauentzienstraße 8      | Berlin    | null  | Germany | 10789      | +49 030 26550280 | null | hannah.schneider@yahoo.de | 5            |
| 37         | Fynn      | Zimmermann | null    | Berger Straße 10        | Frankfurt | null  | Germany | 60316      | +49 069 40598889 | null | fzimmermann@yahoo.de      | 3            |
| 38         | Niklas    | Schröder   | null    | Barbarossastraße 19     | Berlin    | null  | Germany | 10779      | +49 030 2141444  | null | nschroder@surfeu.de       | 3            |

## Zadanie 2

Wypisz wszystkich klientów pochodzących z Pragi lub Niemiec.

### Wynik

| CustomerId | FirstName | LastName    | Company          | Address                 | City      | State | Country        | PostalCode | Phone            | Fax              | Email                     | SupportRepId |
|------------|-----------|-------------|------------------|-------------------------|-----------|-------|----------------|------------|------------------|------------------|---------------------------|--------------|
| 2          | Leonie    | Köhler      | null             | Theodor-Heuss-Straße 34 | Stuttgart | null  | Germany        | 70174      | +49 0711 2842222 | null             | leonekohler@surfeu.de     | 5            |
| 5          | František | Wichterlová | JetBrains s.r.o. | Klanova 9/506           | Prague    | null  | Czech Republic | 14700      | +420 2 4172 5555 | +420 2 4172 5555 | frantisekw@jetbrains.com  | 4            |
| 6          | Helena    | Holý        | null             | Rilská 3174/6           | Prague    | null  | Czech Republic | 14300      | +420 2 4177 0449 | null             | hholy@gmail.com           | 5            |
| 36         | Hannah    | Schneider   | null             | Tauentzienstraße 8      | Berlin    | null  | Germany        | 10789      | +49 030 26550280 | null             | hannah.schneider@yahoo.de | 5            |
| 37         | Fynn      | Zimmermann  | null             | Berger Straße 10        | Frankfurt | null  | Germany        | 60316      | +49 069 40598889 | null             | fzimmermann@yahoo.de      | 3            |
| 38         | Niklas    | Schröder    | null             | Barbarossastraße 19     | Berlin    | null  | Germany        | 10779      | +49 030 2141444  | null             | nschroder@surfeu.de       | 3            |

## Zadanie 3

Wypisz wszystkich pracowników zatrudnionych po 1 stycznia 2003 roku.

### Wynik

| EmployeeId | LastName | FirstName | Title               | ReportsTo | BirthDate           | HireDate            | Address                     | City       | State | Country | PostalCode | Phone             | Fax               | Email                    |
|------------|----------|-----------|---------------------|-----------|---------------------|---------------------|-----------------------------|------------|-------|---------|------------|-------------------|-------------------|--------------------------|
| 4          | Park     | Margaret  | Sales Support Agent | 2         | 1947-09-19 00:00:00 | 2003-05-03 00:00:00 | 683 10 Street SW            | Calgary    | AB    | Canada  | T2P 5G3    | +1 (403) 263-4423 | +1 (403) 263-4289 | margaret@chinookcorp.com |
| 5          | Johnson  | Steve     | Sales Support Agent | 2         | 1965-03-03 00:00:00 | 2003-10-17 00:00:00 | 7727B 41 Ave                | Calgary    | AB    | Canada  | T3B 1Y7    | 1 (780) 836-9987  | 1 (780) 836-9543  | steve@chinookcorp.com    |
| 6          | Mitchell | Michael   | IT Manager          | 1         | 1973-07-01 00:00:00 | 2003-10-17 00:00:00 | 5827 Bowness Road NW        | Calgary    | AB    | Canada  | T3B 0C5    | +1 (403) 246-9887 | +1 (403) 246-9899 | michael@chinookcorp.com  |
| 7          | King     | Robert    | IT Staff            | 6         | 1970-05-29 00:00:00 | 2004-01-02 00:00:00 | 590 Columbia Boulevard West | Lethbridge | AB    | Canada  | T1K 5N8    | +1 (403) 456-9986 | +1 (403) 456-8485 | robert@chinookcorp.com   |
| 8          | Callahan | Laura     | IT Staff            | 6         | 1968-01-09 00:00:00 | 2004-03-04 00:00:00 | 923 7 ST NW                 | Lethbridge | AB    | Canada  | T1H 1Y8    | +1 (403) 467-3351 | +1 (403) 467-8772 | laura@chinookcorp.com    |

## Zadanie 4

Utwórz zestawienie zawierające nazwę i długość trwania utworów dłuższych niż $10$ minut.

### 10 pierwszych wierszy wyniku

| Name                       | Milliseconds |
|----------------------------|--------------|
| How Many More Times        | 711836       |
| Advance Romance            | 677694       |
| Mercyful Fate              | 671712       |
| Mistreated                 | 758648       |
| You Fool No One            | 804101       |
| In My Time Of Dying        | 666017       |
| The Calling                | 747755       |
| Walkin'                    | 807392       |
| My Funny Valentine (Live)  | 907520       |
| Miles Runs The Voodoo Down | 843964       |

## Zadnie 5

Wypisz imię i nazwisko wszystkich klientów, których imię lub nazwisko kończy się na literę *a*.

### Wynik

| FirstName | LastName   |
|-----------|------------|
| Helena    | HolĂ˝      |
| Kara      | Nielsen    |
| Alexandre | Rocha      |
| Roberto   | Almeida    |
| Fernanda  | Ramos      |
| Julia     | Barnett    |
| Martha    | Silk       |
| Madalena  | Sampaio    |
| Emma      | Jones      |
| Puja      | Srivastava |

## Zadanie 6

Wypisz imię i nazwisko wszystkich klientów, których imię lub nazwisko zaczyna się na literę *A*.

### Wynik

| FirstName | LastName |
|-----------|----------|
| Astrid    | Gruber   |
| Alexandre | Rocha    |
| Roberto   | Almeida  |
| Aaron     | Mitchell |

## Zadanie 7

Wypisz imię i nazwisko wszystkich klientów, którzy mają literę *e* w nazwisku.

### 10 pierwszych wierszy wyniku

| FirstName | LastName    |
|-----------|-------------|
| Luís      | Gonçalves   |
| Leonie    | Köhler      |
| François  | Tremblay    |
| Bjørn     | Hansen      |
| František | Wichterlová |
| Astrid    | Gruber      |
| Daan      | Peeters     |
| Kara      | Nielsen     |
| Roberto   | Almeida     |
| Jennifer  | Peterson    |

## Zadanie 8

Wypisz imię i nazwisko tylko tych klientów, którzy nie mają wpisanej firmy.

### 10 pierwszych wierszy wyniku

| FirstName | LastName |
|-----------|----------|
| Leonie    | Köhler   |
| François  | Tremblay |
| Bjørn     | Hansen   |
| Helena    | Holý     |
| Astrid    | Gruber   |
| Daan      | Peeters  |
| Kara      | Nielsen  |
| Fernanda  | Ramos    |
| Michelle  | Brooks   |
| Dan       | Miller   |

## Zadanie 9

Wypisz imię i nazwisko tylko tych klientów, którzy mają podaną firmę.

### Wynik

| FirstName | LastName    |
|-----------|-------------|
| Luís      | Gonçalves   |
| František | Wichterlová |
| Eduardo   | Martins     |
| Alexandre | Rocha       |
| Roberto   | Almeida     |
| Mark      | Philips     |
| Jennifer  | Peterson    |
| Frank     | Harris      |
| Jack      | Smith       |
| Tim       | Goyer       |

## Zadanie 10

Wypisz wszystkich pracowników, którzy mieli co najmniej 50 lat w 2018 roku.

### Wynik

| EmployeeId | LastName | FirstName | Title               | ReportsTo | BirthDate           | HireDate            | Address             | City       | State | Country | PostalCode | Phone             | Fax               | Email                    |
|------------|----------|-----------|---------------------|-----------|---------------------|---------------------|---------------------|------------|-------|---------|------------|-------------------|-------------------|--------------------------|
| 1          | Adams    | Andrew    | General Manager     | null      | 1962-02-18 00:00:00 | 2002-08-14 00:00:00 | 11120 Jasper Ave NW | Edmonton   | AB    | Canada  | T5K 2N1    | +1 (780) 428-9482 | +1 (780) 428-3457 | andrew@chinookcorp.com   |
| 2          | Edwards  | Nancy     | Sales Manager       | 1         | 1958-12-08 00:00:00 | 2002-05-01 00:00:00 | 825 8 Ave SW        | Calgary    | AB    | Canada  | T2P 2T3    | +1 (403) 262-3443 | +1 (403) 262-3322 | nancy@chinookcorp.com    |
| 4          | Park     | Margaret  | Sales Support Agent | 2         | 1947-09-19 00:00:00 | 2003-05-03 00:00:00 | 683 10 Street SW    | Calgary    | AB    | Canada  | T2P 5G3    | +1 (403) 263-4423 | +1 (403) 263-4289 | margaret@chinookcorp.com |
| 5          | Johnson  | Steve     | Sales Support Agent | 2         | 1965-03-03 00:00:00 | 2003-10-17 00:00:00 | 7727B 41 Ave        | Calgary    | AB    | Canada  | T3B 1Y7    | 1 (780) 836-9987  | 1 (780) 836-9543  | steve@chinookcorp.com    |
| 8          | Callahan | Laura     | IT Staff            | 6         | 1968-01-09 00:00:00 | 2004-03-04 00:00:00 | 923 7 ST NW         | Lethbridge | AB    | Canada  | T1H 1Y8    | +1 (403) 467-3351 | +1 (403) 467-8772 | laura@chinookcorp.com    |
