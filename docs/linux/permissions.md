# Prawa dostępu

## Wstęp

W systemie Linux każdy plik ma przypisane prawa dostępu dla właściciela pliku, grupy użytkowników i wszystkich innych. Prawa określane są za pomocą ciągu znaków rwx i można je zobaczyć używając polecenia `ls -l`.

### Kolejność uprawnień

|     d     |              rwx              |          rwx          |             rwx             |
| :-------: | :---------------------------: | :-------------------: | :-------------------------: |
| Typ pliku | Uprawnienia właściciela pliku | Uprawnienia dla grupy | Uprawnienia dla pozostałych |

### Typ uprawnień

| Wartość ósemkowa | Oznaczenie |       Znaczenie      |
| :--------------: | :--------: | :------------------: |
|         4        |      r     |   Prawo do odczytu   |
|         2        |      w     |    Prawo do zapisu   |
|         1        |      x     | Prawo do wykonywania |

| Wartość ósemkowa | Oznaczenie |          Prawa dostępu         |
| :--------------: | :--------: | :----------------------------: |
|         7        |     rwx    | czytanie, pisanie, wykonywanie |
|         6        |     rw-    |       czytanie i pisanie       |
|         5        |     r-x    |     czytanie i wykonywanie     |
|         4        |     r--    |            czytanie            |
|         3        |     -wx    |      wykonywanie i pisanie     |
|         2        |     -w-    |             pisanie            |
|         1        |     --x    |           wykonywanie          |
|         0        |     ---    |              brak              |

### Typ pliku

| Oznaczenie |        Znaczenie       |
| :--------: | :--------------------: |
|      -     |       Zwykły plik      |
|      d     |         Katalog        |
|      l     | Dowiązanie symboliczne |
|      s     |         Gniazdo        |
|      f     |          FIFO          |
|      c     |   Urządzenie znakowe   |
|      b     |   Urządzenie blokowe   |

## Nadanie uprawnień

Do zmiany uprawnień nadanych plikowi służy polecenie `chmod`. Aby móc zmienić uprawnienia, musimy mieć do tego odpowiednie prawa, tzn. być właścicielem pliku, albo administratorem.

### chmod

Składnia polecenia wygląda następująco:

**`chmod [uprawnienia] [plik]`**

#### Przykład

**`chmod 600 plik.txt`**

Oznacza nadanie uprawnień do czytania i pisania właścicielowi pliku (6) i brak uprawnień dla grupy (0) i pozostałych użytkowników (0).

### Zmiana uprawnień

Za pomocą polecenia chmod możemy nie tylko nadawać uprawnienia, ale także modyfikować już nadane. Wówczas, zamiast podawać pełne uprawnienia, użyjemy składni:

\[jednostka]\[operacja]\[uprawnienia]

#### Dozwolone oznaczenia jednostki

| Oznaczenie |      Znaczenie     |
| :--------: | :----------------: |
|      u     |  Użytkownik (user) |
|      g     |    Grupa (group)   |
|      o     | Pozostali (others) |
|      a     |    Wszyscy (all)   |

#### Dozwolone operacje

| Oznaczenie |         Znaczenie        |
| :--------: | :----------------------: |
|      +     |    Dodanie uprawnienia   |
|      -     |   Usunięcie uprawnienia  |
|      =     | Ustanowienie uprawnienia |

#### Przykład

**`chmod u+rx plik.txt`**

Oznacza dodanie uprawnień do czytania i wykonywania właścicielowi pliku.

## Ściąga

[Ściąga](https://quickref.me/chmod)