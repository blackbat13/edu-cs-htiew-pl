# Rozwiązania

## Zadanie 1

### Zadanie 1.1

**FPFF**

|               |                                                                                                                                                                                                                                                                             |              |          |
|---------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------|----------|
| **1.** |     znajdowanie   odpowiednich dróg połączeń między węzłami sieci (tzw. routing). Operuje   adresami logicznymi węzłów sieci które przydzielane są niezależnie od   rzeczywistej adresacji fizycznej poszczególnych urządzeń.                                               |     ~~P~~        |     **F**    |
| **2.** |     gwarantowanie   wyższym warstwom komunikacyjnym dostarczenia wszystkich pakietów w całości, z   zachowaniem kolejności i bez duplikatów. Zapewnia to wiarygodne połączenie   kosztem większego narzutu w postaci nagłówka i większej liczby przesyłanych   pakietów.    | **P** |     ~~F~~    |
| **3.** |     pośredniczenie   między warstwami łącza danych  i   sieciową, w kojarzeniu adresu MAC przypisanemu interfejsowi z adresem   sieciowym IP.                                                                                                                               |     ~~P~~        |     **F**    |
| **4.** |     zamiana   nazwy domenowej, zrozumiałej dla człowieka na adresy IP urządzeń w sieci.                                                                                                                                                                                     |     ~~P~~        |     **F**    |

### Zadanie 1.2

**PFFF**

**Wynik działania funkcji**: $$3 2 1 0$$

**Symulacja:**

```
f(1):
    1<5 PRAWDA
        f(2):
            2 < 5 PRAWDA
                f(3):
                    3 < 5 PRAWDA
                        f(4):
                            4 < 5 PRAWDA
                                f(5):
                                    5 < 5 FAŁSZ
                                wypisz(3)
                        wypisz(2)
                wypisz(1)
        wypisz(0)
```

### Zadanie 1.3

**FFPF**

- $$222_3 > 121_6$$ FAŁSZ
- $$222_3 = 10_{11}$$ FAŁSZ
- $$222_3 > 11_{10}$$ PRAWDA
- $$222_3 < 121_4$$$ FAŁSZ

## Zadanie 2

### Zadanie 2.1

| **N**        | **Czy   Ada ma strategię pozwalającą jej wygrać?**        |
|:------------:|:---------------------------------------------------------:|
|       1      |                             TAK                           |
|       2      |                             NIE                           |
|       3      |                             TAK                           |
|       4      |                             TAK                           |
|       5      |                             TAK                           |
|       6      |                           **TAK**                         |
|       7      |                           **NIE**                         |
|     8        |                           **TAK**                         |
|     14       |                           **NIE**                         |

### Zadanie 2.2

```
1. wyniki := [1..N]
2. wyniki[1] := TRUE
3. wyniki[2] := FALSE
4. wyniki[3] := TRUE
5. wyniki[4] := TRUE
6. Dla i := 5 do N, wykonuj:
    7. Jeżeli wyniki[i - 1] = FALSE lub wyniki[i - 3] = FALSE lub wyniki[i - 4] = FALSE, to:
        8. wyniki[i] = TRUE
    9. w przeciwnym przypadku:
        10. wyniki[i] = FALSE
11. Jeżeli wyniki[N] = TRUE, to:
    12. Wypisz "TAK"
13. w przeciwnym przypadku:
    14. Wypisz "NIE"
```

## Zadanie 3

### Zadanie 3.1

| **N**        | **Czy silna?**          | **Suma**        |
|:------------:|:-----------------------:|:---------------:|
|       7      |            TAK          | $$3! + 1!$$     |
|       4      |            NIE          |         -       |
|       5      |            **NIE**      |         -       |
|       6      |            **TAK**      |       $$3!$$    |
|       9      |            **TAK**      | $$3! + 2! + 1!$$|
|       25     |            **TAK**      | $$4! + 1!$$     |

### Zadanie 3.2

```
1. silnia := 1
2. liczba := 1
3. Dopóki N <= (silnia * (liczba + 1)), wykonuj:
    4. liczba := liczba + 1
    5. silnia := silnia * liczba
6. Dopóki liczba > 0 oraz N > 0, wykonuj:
    7. Jeżeli silnia <= N, to:
        8. N := N - silnia
    9. silnia := silnia / liczba
    10. liczba := liczba - 1
11. Jeżeli N = 0, to:
    12. Wypisz "TAK"
13. w przeciwnym przypadku:
    14. Wypisz "NIE"
```

## Zadanie 4

### Python

{% file src="../../../../.gitbook/assets/2023_pti_zad4.py" %}
Rozwiązanie
{% endfile %}

### Wyniki

{% file src="../../../../.gitbook/assets/2023_pti_wyniki4.txt" %}
Plik wyniki4.txt
{% endfile %}

{% file src="../../../../.gitbook/assets/2023_pti_rodziny.txt" %}
Plik rodziny.txt
{% endfile %}

## Zadanie 5

### Zadanie 5.1

|      N     |    $$a_n$$|     $$b_n$$    |     $$c_n$$    |     $$m\Sigma_n$$    |     $$w\Sigma_n$$    |     $$\Sigma_n$$    |
|:----------:|:---------:|:---------:|:---------:|:----------:|:----------:|:---------:|
|      1     |     -1    |      1    |     -1    |      -1    |      0     |     -1    |
|      2     |      1    |      2    |      1    |      -1    |      1     |      0    |
|      3     |     -1    |      3    |     -2    |      -3    |      1     |     -2    |
|      6     |     1      |     6      |     3      |    -6        |     6       |     0      |
|      11    |     -1      |    11       |    -6       |     -21       |     15       |     -6      |
|      24    |     1      |     24      |      12     |      -78      |     78       |     0      |
|     120    |    1       |    120       |     60      |      -1830      |    1830        |    0       |

## Zadanie 6

{% file src="../../../../.gitbook/assets/2023_pti_zad6.xlsx" %}
Rozwiązanie
{% endfile %}

## Zadanie 7

### Zadanie 7.1

```sql
SELECT DISTINCT Magazyn_koncowy 
    FROM Magazyny 
        JOIN Kursy ON Magazyny.Nazwa = Kursy.Magazyn_poczatkowy 
    WHERE Adres LIKE '*Toruń*';
```

### Zadanie 7.2

```sql
SELECT DISTINCT Model
    FROM Pojazdy 
    WHERE Ladownosc <= 3.5;
```

### Zadanie 7.3

```sql
SELECT Magazyn_poczatkowy, Magazyn_koncowy, COUNT(Lp) as Liczba_kursow, SUM(Data_przyjazdu - Data_wyjazdu) as Laczny_czas 
    FROM Kursy
    GROUP BY Magazyn_poczatkowy, Magazyn_koncowy 
    ORDER BY Liczba_kursow DESC, Magazyn_poczatkowy ASC;
```

## Zadanie 8

{% file src="../../../../.gitbook/assets/2023_pti_zad8.accdb" %}
Rozwiązanie
{% endfile %}
