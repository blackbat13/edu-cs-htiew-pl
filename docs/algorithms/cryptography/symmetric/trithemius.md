# Szyfr Trithemius'a

Szyfr Trithemius'a został wymyślony przez niemieckiego mnicha i uczonego, Jana Trithemiusa, w XVI wieku. Jest to odmiana szyfru Cezara, w której przesunięcie liter zmienia się z każdą literą w tekście jawnym.

## Opis działania

Zasada działania szyfru Trithemius'a polega na tym, że każda kolejna litera tekstu jawnego jest przesuwana o kolejne miejsce. Pierwsza litera tekstu jawnego jest przesuwana o jedno miejsce, druga litera o dwa miejsca, trzecia litera o trzy miejsca, i tak dalej.

## Przykład

Dla tekstu jawnego "ABC":

- A jest przesuwane o 1 miejsce i staje się B
- B jest przesuwane o 2 miejsca i staje się D
- C jest przesuwane o 3 miejsca i staje się F

Wynikowe zaszyfrowane słowo to: "BDF".

## Bezpieczeństwo

Podobnie jak szyfr Cezara, szyfr Trithemius'a nie jest traktowany jako bezpieczna metoda szyfrowania w dzisiejszych czasach. Jednak w XVI wieku jego zmienny krok przesunięcia stanowił pewne wyzwanie dla osób próbujących złamać szyfr. Mimo to, dzięki współczesnym metodom analizy, jest on stosunkowo łatwy do złamania.

Szyfr Trithemius'a był głównie używany w celach edukacyjnych i literackich, choć także mógł być wykorzystywany do pewnych praktycznych zastosowań w tamtych czasach.

## Specyfikacja

### Dane

- **jawny/szyfrogram** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Szyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $1$ do $26$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja SzyfrujTrithemius(jawny):
    1. szyfrogram := ""
    2. k := 0
    3. Dla i := 1 do Długość(jawny), wykonuj:
        4. nowaPozycja := Pozycja(jawny[i]) + k
        5. Jeżeli nowaPozycja > 26, to:
            6. nowaPozycja := nowaPozycja - 26
        7. nowaLitera := Alfabet(nowaPozycja)
        8. szyfrogram := szyfrogram + nowaLitera
        9. k := (k + 1) mod 26

    10. Zwróć szyfrogram 
```

## Deszyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $1$ do $26$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja DeszyfrujTrithemius(szyfrogram):
    1. jawny := ""
    2. k := 0
    3. Dla i := 1 do Długość(szyfrogram), wykonuj:
        4. nowaPozycja := Pozycja(szyfrogram[i]) - k
        5. Jeżeli nowaPozycja < 1, to:
            6. nowaPozycja := 26 + nowaPozycja
        7. nowaLitera := Alfabet(nowaPozycja)
        8. jawny := jawny + nowaLitera
        9. k := (k + 1) mod 26

    10. Zwróć jawny 
```

## Implementacja

### [C++](../../../programming/c++/algorithms/cryptography/trithemius.md)

### [Python](../../../programming/python/algorithms/cryptography/trithemius.md)
