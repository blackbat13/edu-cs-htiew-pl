# Szyfr płotkowy

Szyfr płotkowy, często nazywany również szyfrem żaglowym, jest techniką transpozycji, gdzie litery tekstu jawnego są pisane na skos w dół i wzdłuż, a potem odczytywane linia po linii. Daje to efekt, jakby litery były zawieszone na pewnego rodzaju "płotku".

## Opis działania

1. **Ustal głębokość płotka**: wybierz liczbę, która będzie głębokością płotka (np. 3).

2. **Zapisanie tekstu**: pisz tekst jawny na skos w dół do osiągnięcia wybranej głębokości, a następnie zmień kierunek i pisz w górę, aż dojdziesz do górnej krawędzi. Kontynuuj tę metodę przez cały tekst.

3. **Odczytanie zaszyfrowanej wiadomości**: aby otrzymać tekst zaszyfrowany, odczytaj każdy rząd liter od góry do dołu.

## Bezpieczeństwo

Szyfr płotkowy jest stosunkowo prosty do deszyfrowania, zwłaszcza jeśli przeciwnik zna lub może odgadnąć głębokość płotka. Podobnie jak inne metody transpozycji, nie zmienia on częstotliwości liter, co sprawia, że jest podatny na analizę statystyczną.

## Specyfikacja

### Dane

- **jawny/szyfrogram** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego
- **klucz** - liczba naturalna, większa od zera

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Przykład 1

Tekst jawny: **ALAMAKOTA**.

Klucz: $$3$$

```
  A   O
 L M K T
A   A   A
```

Szyfrogram: **AOLMKTAAA**

## Przykład 2

Tekst jawny: **ALAMAKOTA**.

Klucz: $$4$$

```
   M
  A A    A
 L   K  T
A     O
```

Szyfrogram: **MAAALKTAO**

## Szyfrowanie

### Funkcje pomocnicze

- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funckja SzyfrujPłotkowy(jawny, klucz):
    1. szyfrogram := ""
    2. Dla k := 1 do k, wykonuj:
        3. Jeżeli k = klucz, to:
            4. skok := klucz * 2
        5. w przeciwnym przypadku:
            6. skok = (klucz - k) * 2
        7. i := k
        8. Dopóki i <= Długość(jawny), wykonuj:
            9. szyfrogram := szyfrogram + jawny[i]
            10. i := i + skok

    11. Zwróć szyfrogram
```

## Deszyfrowanie

### Funkcje pomocnicze

- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja DeszyfrujPłotkowy(szyfrogram, klucz):
    1. jawny := szyfrogram
    2. j := 0
    3. Dla k := 1 do klucz, wykonuj:
        4. Jeżeli k = klucz, to:
            5. skok := klucz * 2
        6. w przeciwnym przypadku:
            7. skok := (klucz - k) * 2
        7. i := k
        8. Dopóki i < Długość(szyfrogram), wykonuj:
            9. jawny[i] := szyfrogram[j]
            10. j := j + 1
            11. i := i + skok

    12. Zwróć jawny
```

## Implementacja

### C++

{% content-ref url="../../../programming/c++/algorithms/cryptography/rail-fence.md" %}
[rail-fence.md](../../../programming/c++/algorithms/cryptography/rail-fence.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../../programming/python/algorithms/cryptography/rail-fence.md" %}
[rail-fence.md](../../../programming/python/algorithms/cryptography/rail-fence.md)
{% endcontent-ref %}
