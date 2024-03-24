# JOIN

Operacja JOIN w języku zapytań SQL służy do łączenia dwóch lub więcej tabel na podstawie wspólnego pola (klucza). Istnieje kilka różnych typów operacji JOIN, opisanych poniżej. Pokażemy ich działanie na podstawie łączenia ze sobą dwóch tabel: Imiona oraz Zawody. Tabele będziemy łączyć ze sobą na podstawie pola **ID**.

### Imiona

| ID | Imię |
| --- | --- |
| 1 | Anna |
| 2 | Bartek |
| 3 | Celina |

### Zawody

| ID | Zawód |
| --- | --- |
| 2 | Programista |
| 3 | Lekarz |
| 4 | Artysta |

## INNER JOIN

Znany również jako JOIN. Zwraca tylko te rekordy, dla których istnieje dopasowanie w obu tabelach.

### Wynik

| ID | Imię | Zawód |
| --- | --- | --- |
| 2 | Bartek | Programista |
| 3 | Celina | Lekarz |

## LEFT JOIN (LEFT OUTER JOIN)

Zwraca wszystkie rekordy z lewej tabeli (Imiona), a dopasowane rekordy z prawej tabeli (Zawody). Jeśli nie ma dopasowania, wynikiem jest NULL.

### Wynik

| ID | Imię | Zawód |
| --- | --- | --- |
| 1 | Anna | NULL |
| 2 | Bartek | Programista |
| 3 | Celina | Lekarz |

## RIGHT JOIN (RIGHT OUTER JOIN)

Zwraca wszystkie rekordy z prawej tabeli (Zawody), a dopasowane rekordy z lewej tabeli (Imiona). Jeśli nie ma dopasowania, wynikiem jest NULL.

### Wynik

| ID | Imię | Zawód |
| --- | --- | --- |
| 2 | Bartek | Programista |
| 3 | Celina | Lekarz |
| 4 | NULL | Artysta |

## FULL JOIN (FULL OUTER JOIN)

Zwraca wszystkie rekordy z obu tabel, niezalżnie od tego, czy istnieje dla nich dopasowanie w drugiej tabeli. Jeśli dla danego rekordu w jednej tabeli nie ma dopasowania w drugiej tabeli, wynikiem jest NULL dla wszystkich kolumn drugiej tabeli.

### Wynik

| ID | Imię | Zawód |
| --- | --- | --- |
| 1 | Anna | NULL |
| 2 | Bartek | Programista |
| 3 | Celina | Lekarz |
| 4 | NULL | Artysta |
