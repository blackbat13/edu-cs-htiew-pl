# Szyfr Beauforta

Szyfr Beauforta, nazwany na cześć Sir Francisa Beauforta, jest odmianą szyfru Vigenère'a, w którym operacja szyfrowania i deszyfrowania jest zamieniona. Podobnie jak w przypadku Vigenère'a, jest to technika szyfrowania substytucyjnego wieloalfabetycznego.

## Opis działania

1. **Klucz**: wybierz klucz (słowo lub fraza), który będzie używany do szyfrowania i deszyfrowania wiadomości.

1. **Szyfrowanie**:
   - Rozszerz klucz do długości oryginalnej wiadomości.
   - Dla każdej litery wiadomości:
     - Znajdź indeks litery klucza w alfabecie.
     - Odejmij ten indeks od indeksu litery oryginalnej wiadomości (zamiast dodawania, jak w Vigenère).
     - Jeśli wynik jest ujemny, dodaj długość alfabetu.
     - Znajdź literę odpowiadającą wynikowi - jest to zaszyfrowana litera.

2. **Deszyfrowanie**: proces deszyfrowania jest identyczny z procesem szyfrowania w szyfrze Beauforta, ponieważ jest to odwrotna operacja Vigenère'a.

### Przykład

Załóżmy, że mamy wiadomość "HELLO" i klucz "KEY". Pierwszym krokiem jest rozszerzenie klucza do "KEYKE". Teraz każda litera wiadomości jest "odejmowana" od litery klucza, aby uzyskać zaszyfrowaną wiadomość.

## Bezpieczeństwo

Podobnie jak szyfr Vigenère'a, szyfr Beauforta może być łamany przy użyciu technik kryptoanalizy, takich jak analiza częstotliwości liter w tekście. Szyfr ten byłby trudniejszy do złamania w czasach przed komputerami, ale dzisiaj istnieją skuteczne metody ataku na tę metodę szyfrowania. 

## Specyfikacja

### Dane

- **tekst** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego
- **klucz** - ciąg znaków składający się z małych liter alfabetu angielskiego

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Szyfrowanie i deszyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $$1$$ do $$26$$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja Beaufort(tekst, klucz):
    1. wynik := ""
    2. kluczIndeks := 1
    3. Dla i := 1 do Długość(twkst), wykonuj:
        4. nowaPozycja := 27 - Pozycja(twkst[i]) + Pozycja[kluczIndeks]
        5. Jeżeli nowaPozycja > 26, to:
            6. nowaPozycja := nowaPozycja - 26
        7. nowaLitera := Alfabet(nowaPozycja)
        8. wynik := wynik + nowaLitera
        9. kluczIndeks := kluczIndeks + 1
        10. Jeżeli kluczIndeks > Długość(klucz), to:
            11. kluczIndeks := kluczIndeks - Długość(klucz)

    12. Zwróć wynik 
```

## Implementacja

### C++

{% content-ref url="../../../programming/c++/algorithms/cryptography/beaufort.md" %}
[beaufort.md](../../../programming/c++/algorithms/cryptography/beaufort.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../../programming/python/algorithms/cryptography/beaufort.md" %}
[beaufort.md](../../../programming/python/algorithms/cryptography/beaufort.md)
{% endcontent-ref %}
