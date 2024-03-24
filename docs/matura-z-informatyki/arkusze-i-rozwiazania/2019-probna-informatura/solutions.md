# Rozwiązania

## Część I

### Zadanie 1

#### Zadanie 1.1

| **Wprowadzona liczba $$n$$** | **Wartość wyznaczonej sumy $$s$$** | **Czy liczba $$n$$ jest podzielna przez $$7$$** | **Czy liczba $$n$$ jest podzielna przez $$11$$** | **Czy liczba $$n$$ jest podzielna przez $$13$$** |
|:---:|:---:|:---:|:---:|:---:|
| $$22133645$$ | $$s=645-133+22=534$$ | NIE | NIE | NIE |
| $$20449$$ | $$s=449-20=429$$ | NIE | TAK | TAK |
| $$1343342$$ | $$s=342-343+1=0$$ | TAK | TAK | TAK |

#### Zadanie 1.2

```
1. s := 0
2. p := 1
3. Dopóki n > 0, wykonuj:
    4. s := s + (n mod 1000) * p
    5. n := n div 1000
    6. p := p * (-1)
7. Jeżeli (s mod 7) = 0, to:
    8. Wypisz "TAK"
9. W przeciwnym wypadku:
    10. Wypisz "NIE"
11. Jeżeli (s mod 11) = 0, to:
    12. Wypisz "TAK"
13. W przeciwnym wypadku:
    14. Wypisz "NIE"
15. Jeżeli (s mod 13) = 0, to:
    16. Wypisz "TAK"
17. W przeciwnym wypadku:
    18. Wypisz "NIE"
```

#### Zadanie 1.3

```
1. wynik := 0
2. Dopóki n > 0, wykonuj:
    3. wynik := wynik * 10
    4. wynik := wynik + (n mod 10)
    5. n := n div 10
6. Wypisz wynik
```

### Zadanie 2

#### Zadanie 2.1

**PFFP**

#### Zadanie 2.2

**FPFF**

#### Zadanie 2.3

**FPPF**

### Zadanie 3

#### Zadanie 3.1

| | **P/F** |
|:---:|:---:|
| 58 | P |
| 122 | F |
| 958 | P |

#### Zadanie 3.2

```
Funkcja suma_cyfr(n):
    1. s = 0;
    2. dopóki n > 0 wykonuj
        s = s + n mod 10;
        n = n div 10;
    3. zwróć s
```

#### Zadanie 3.3

##### a)

```
Procedura rozkład(n):
    1. dzielnik <- 2
    2. dopóki n > 0 wykonuj
            dopóki (n mod dzielnik = 0) wykonuj
                wypisz dzielnik
                n <- n div dzielnik
            dzielnik <- dzielnik + 1
```

##### b)

```
Funkcja rozkład(n):
    1. dzielnik <- 2
    2. suma <- 0
    3. dopóki n > 0 wykonuj
            dopóki (n mod dzielnik = 0) wykonuj
                suma <- suma + suma_cyfr(dzielnik)
                n <- n div dzielnik
            dzielnik <- dzielnik + 1
    4. zwróć suma
```

#### Zadanie 3.4

```
Funkcja pierwsza(n):
    1. i <- 2
    2. dopóki i*i <= n wykonuj
        jeśli (n mod i = 0) zwróć fałsz
        i <- i + 1
    3. zwróć prawda
```

#### Zadanie 3.5

```
1. Jeżeli pierwsza(n), to:
    2. Wypisz fałsz i zakończ
3. Jeżeli suma_cyfr(n) = rozkład(n), to:
    4. Wypisz prawda
5. w przeciwnym przypadku:
    6. Wypisz fałsz
```

## Część II

### Zadanie 4

{% file src="../../../.gitbook/assets/2019_p_m_zad4.cpp" %}
C++
{% endfile %}

### Zadanie 5

{% file src="../../../.gitbook/assets/2019_p_m_zad5.xlsx" %}
Excel
{% endfile %}

### Zadanie 6

{% file src="../../../.gitbook/assets/2019_p_m_zad6.accdb" %}
Access
{% endfile %}
