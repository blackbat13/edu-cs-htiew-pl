# Rozwiązania

## Zadanie 1

```python linenums="1"
from math import gcd


def zadanie1():
    path = "input/ulamki.txt"
    with open(path, "r") as file:
        ulamki = [list(map(int, str.split(" "))) for str in file.read().split("\n")]
        with open("skrocone.txt", "w") as out_file:
            for ulamek in ulamki:
                dzielnik = gcd(ulamek[0], ulamek[1])
                ulamek[0] //= dzielnik
                ulamek[1] //= dzielnik
                print(f"{ulamek[0]} {ulamek[1]}", file=out_file)
```


## Zadanie 2

```python linenums="1"
from math import gcd


def zadanie2():
    path = "input/ulamki.txt"
    with open(path, "r") as file:
        ulamki = [list(map(int, str.split(" "))) for str in file.read().split("\n")]
        licznik = ulamki[0][0]
        mianownik = ulamki[0][1]
        ulamki.pop(0)
        for ulamek in ulamki:
            m1 = mianownik
            m2 = ulamek[1]
            licznik *= m2
            mianownik *= m2
            ulamek[0] *= m1
            ulamek[1] *= m1
            licznik += ulamek[0]

        dzielnik = gcd(licznik, mianownik)
        licznik //= dzielnik
        mianownik //= dzielnik
        print(licznik, mianownik)
```


## Zadanie 3

```python linenums="1"
from math import gcd


def zadanie3():
    path = "input/ulamki.txt"
    with open(path, "r") as file:
        ulamki = [list(map(int, str.split(" "))) for str in file.read().split("\n")]
        licznik = ulamki[0][0]
        mianownik = ulamki[0][1]
        ulamki.pop(0)
        for ulamek in ulamki:
            licznik *= ulamek[0]
            mianownik *= ulamek[1]

        dzielnik = gcd(licznik, mianownik)
        licznik //= dzielnik
        mianownik //= dzielnik
        print(licznik, mianownik)
```

