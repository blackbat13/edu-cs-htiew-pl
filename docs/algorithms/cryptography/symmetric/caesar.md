# Szyfr Cezara

Szyfr Cezara to jedna z najstarszych znanych technik szyfrowania. Został nazwany na cześć Juliusza Cezara, który rzekomo używał go do szyfrowania swojej prywatnej korespondencji.

## Opis działania

1. **Przesunięcie**: wybierz liczbę, zwaną przesunięciem (np. 3). Ta liczba określa, o ile miejsc w alfabecie litery będą przesuwane.

1. **Szyfrowanie**:
   - Dla każdej litery w tekście jawnym:
     - Znajdź jej położenie w alfabecie.
     - Dodaj do niego wartość przesunięcia.
     - Jeśli wynik przekroczy długość alfabetu, zacznij od początku (np. dla alfabetu łacińskiego "z" przesunięte o 1 staje się "a").
     - Zastąp literę tekstu jawnego literą z nowym położeniem.

2. **Deszyfrowanie**: proces ten jest odwrotny do szyfrowania. Zamiast dodawać wartość przesunięcia, odejmuje się ją od każdej litery w tekście zaszyfrowanym.

### Przykład

Załóżmy, że mamy wiadomość "ABC" i przesunięcie 3. Po zastosowaniu szyfru Cezara wiadomość staje się "DEF".

## Bezpieczeństwo

Szyfr Cezara jest bardzo prosty i łatwo jest go złamać, nawet bez znajomości klucza. Wystarczy przetestować wszystkie 25 możliwych przesunięć (dla standardowego alfabetu łacińskiego) lub użyć analizy częstotliwości liter. Dlatego szyfr Cezara jest uważany za niebezpieczny i nieodpowiedni dla większości zastosowań w dzisiejszych czasach.

## Specyfikacja

### Dane

- **jawny/szyfrogram** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego
- **klucz** - liczba naturalna z zakresu $<0,25>$

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Szyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $1$ do $26$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja SzyfrujCezar(jawny, klucz):
    1. szyfrogram := ""
    2. Dla i := 1 do Długość(jawny), wykonuj:
        3. nowaPozycja := Pozycja(jawny[i]) + klucz
        4. Jeżeli nowaPozycja > 26, to:
            5. nowaPozycja := nowaPozycja - 26
        6. nowaLitera := Alfabet(nowaPozycja)
        7. szyfrogram := szyfrogram + nowaLitera

    8. Zwróć szyfrogram 
```

## Deszyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $1$ do $26$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja DeszyfrujCezar(szyfrogram, klucz):
    1. jawny := ""
    2. Dla i := 1 do Długość(szyfrogram), wykonuj:
        3. nowaPozycja := Pozycja(szyfrogram[i]) - klucz
        4. Jeżeli nowaPozycja < 1, to:
            5. nowaPozycja := 26 + nowaPozycja
        6. nowaLitera := Alfabet(nowaPozycja)
        7. jawny := jawny + nowaLitera

    8. Zwróć jawny 
```

## Implementacja

### [C++](../../../programming/c++/algorithms/cryptography/caesar.md)

### [Python](../../../programming/python/algorithms/cryptography/caesar.md)
