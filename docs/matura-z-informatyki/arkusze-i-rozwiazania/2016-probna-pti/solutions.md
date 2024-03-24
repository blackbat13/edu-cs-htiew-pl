# Rozwiązania

## Część I

### Zadanie 1

#### 1.1

**Konwertujemy wartość bezwzględną**

| div | mod |
| :-: | :-: |
| 116 |  0  |
|  58 |  1  |
|  25 |  1  |
|  12 |  0  |
|  6  |  0  |
|  3  |  1  |
|  1  |  1  |
|  0  |     |

$$
102_{10}=1100110_2
$$

**Dodajemy brakujące bity**

$$
01100110
$$

**Zamieniamy bity na przeciwne**

$$
10011001
$$

**Dodajemy liczbę 1 do wyniku**

$$
10011010
$$

**Konwersja skończona**

$$
-102_{10}=10011010_{U2}
$$

#### 1.2

$$ONP(3\ 5\ +\ 4\ 2\ *\ -) = (3 + 5) - (4 * 2) = 8 - 8 = 0$$

### Zadanie 2

#### 2.1

```
[n = 2758]

1. [s = 0]

3. [s = 0 + (2758 mod 10) = 0 + 8 = 8]
4. [n = 2758 div 10 = 275]
5. 275 != 0 - OK

3. [s = 8 + (275 mod 10) = 8 + 5 = 13]
4. [n = 275 div 10 = 27]
5. 27 != 0 - OK

3. [s = 13 + (27 mod 10) = 13 + 7 = 20]
4. [n = 27 div 10 = 2]
5. 2 != 0 - OK

3. [s = 20 + (2 mod 10) = 20 + 2 = 22]
4. [n = 2 div 10 = 0]
5. 0 != 0 - NIE, koniec pętli

6. 22 mod 3 = 0 - NIE

8. OK
9. false

Wynik: false
```

```
[n = 1935]

1. [s = 0]

3. [s = 0 + (1935 mod 10) = 0 + 5 = 5]
4. [n = 1935 div 10 = 193]
5. 193 != 0 - OK

3. [s = 5 + (193 mod 10) = 5 + 3 = 8]
4. [n = 193 div 10 = 19]
5. 19 != 0 - OK

3. [s = 8 + (19 mod 10) = 8 + 9 = 17]
4. [n = 19 div 10 = 1]
5. 1 != 0 - OK

3. [s = 17 + (1 mod 10) = 17 + 1 = 18]
4. [n = 1 div 10 = 0]
5. 0 != 0 - NIE, koniec pętli

6. 18 mod 3 = 0 - OK
7. true

Wynik: true
```

#### 2.2

TODO

#### 2.3

```
1. suma := 0
2. Dopóki n != 0, wykonuj:
   3. dwie := n mod 100
   4. suma := suma + (dwie mod 7)
   5. n := n div 100
   6. n := n * 2
7. Jeżeli suma mod 7 = 0, to:
    8. Zwróć true
9. w przeciwnym przypadku:
    10. Zwróć false
``` 

### Zadanie 3

#### 3.1

TODO

#### 3.2

|  Miesiąc  | Liczba par królików |
| :-------: | :-----------------: |
|     1     |          2          |
|     2     |          2          |
|     3     |          2          |
|     4     |          6          |
|     5     |          10         |
|     6     |          14         |
|     7     |          26         |
|     8     |          46         |
|     9     |          74         |
|    10     |         126         |

$$
fib_2(n) =  \begin{cases} 
      2 & n \leq 3 \\
      fib_2(n - 1) + 2 * fib_2(n - 3) & n > 3 \\
   \end{cases}
$$

#### 3.3

```
Funkcja Fib-2(n):
1. Jeżeli n <= 3 to:
    2. Zwróć 2
3. fib2 := tablica [1..n]
4. fib2[1] := 2
5. fib2[2] := 2
6. fib2[3] := 2
7. Od i := 4 do n, wykonuj:
    8. fib2[i] := fib2[i - 1] + 2 * fib2[i - 3]
9. Zwróć fib2[n]
```

## Część II

### Zadanie 5

{% file src="../../../.gitbook/assets/2016_p_zad5.xlsx" %}
Excel
{% endfile %}

### Zadanie 6

{% file src="../../../.gitbook/assets/2016_p_zad6.accdb" %}
Access
{% endfile %}
