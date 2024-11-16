# Sito segmentowe

Czasami jest tak, że potrzebujemy wygenerować liczby pierwsze z zadanego zakresu. Powiedzmy, że np. potrzebujemy znać wszystkie liczby pierwsze od miliona do dwóch milionów. Oczywiście moglibyśmy skorzystać ze standardowego Sita Eratostenesa. Jednak nie jest to najbardziej wydajne rozwiązanie. Dlaczego? Korzystając ze standardowego sita wygenerujemy wszystkie liczby z zakresu od jeden do dwóch milionów. Oznacza to, że dostaniemy wiele nadmiarowych liczb pierwszych! Tutaj przychodzi z pomocą sito segmentowe.

Idea sita segmentowego jest prosta. Najpierw generujemy odpowiedni zakres liczb pierwszych za pomocą standardowego sita, a następnie używamy ich do eliminacji liczb złożonych na naszym *segmencie*.

## Specyfikacja

### Dane

- $a$ - liczba naturalna, początek zakresu
- $b$ - liczba naturalna, koniec zakresu

### Wynik

- Liczby pierwsze z zakresu $<a, b>$

## Psuedokod

```
Funkcja SitoSegmentowe(a, b):
    1. pierwsze := SitoEratostenesa(sufit pierwiastka kwadratowego z b)
    2. n := b - a + 1
    3. czyPierwsza[0..n-1] := tablica wypełniona wartościami true
    4. Dla każdej liczby p w tablicy pierwsze, wykonuj:
        5. start := (a div p) * p
        6. Jeżeli start < a, to:
            7. start := start + p
        8. Jeżeli start == p, to:
            9. start := start + p
        10. Dla j od start do b, przechodząc co p, wykonuj:
            11. czyPierwsza[j - a] := false
    12. wynik := pusta tablica
    13. Dla i od 0 do n - 1, wykonuj:
        14. Jeżeli czy_pierwsza[i], to:
            15. Dopisz i + a do tablicy wynik
    16. Zwróc wynik
```

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/integers/segment-sieve.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/integers/segment-sieve.md){ .md-button }
