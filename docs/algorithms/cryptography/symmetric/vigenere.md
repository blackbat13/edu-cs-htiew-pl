# Szyfr Vigenere'a

Szyfr Vigenère'a, nazwany na cześć Blaise'a de Vigenère, to metoda szyfrowania alfabetycznego tekstu za pomocą prostej formy szyfru polialfabetycznego. Został wynaleziony w XVI wieku i przez wiele lat uważano go za "niezłamalny", zanim nie został ostatecznie złamany w XIX wieku.

## Opis działania

1. **Klucz**: aby zaszyfrować tekst, potrzebny jest klucz, który jest powtarzany lub rozszerzany, aż osiągnie długość tekstu jawnego.
   
2. **Tablica Vigenère'a**: jest to tablica, w której każdy wiersz zawiera alfabet przesunięty o jedno miejsce względem poprzedniego. Służy do szyfrowania i deszyfrowania tekstu.

3. **Proces szyfrowania**:
   - Każda litera tekstu jawnego jest przesuwana w alfabecie o liczbę miejsc równą pozycji odpowiadającej literze klucza.
   - Dla przykładu, jeśli litera klucza to "B" (druga litera alfabetu), litera tekstu jawnego jest przesuwana o 2 miejsca.

## Przykład

Dla tekstu jawnego "TEKST" i klucza "KLUCZ":

- T (za pomocą K) przesuwa się o pozycję K => W
- E (za pomocą L) przesuwa się o pozycję L => M
- K (za pomocą U) przesuwa się o pozycję U => C
- S (za pomocą C) przesuwa się o pozycję C => U
- T (za pomocą Z) przesuwa się o pozycję Z => S

Wynikowe zaszyfrowane słowo to: "WMCUS".

## Bezpieczeństwo

Mimo że przez wieki uważano go za bezpieczny, metody analizy częstotliwości pozwoliły złamać szyfr Vigenère'a. Ostatecznie, pod koniec XIX wieku, Charles Babbage i Friedrich Kasiski opracowali metody jego łamania.

Szyfr Vigenère'a był popularny wśród dyplomatów i wojskowych do komunikacji tajnej przez kilka wieków. Mimo że nie jest już używany do celów bezpieczeństwa, jest często przedstawiany w edukacji jako wprowadzenie do kryptografii polialfabetycznej.

## Specyfikacja

### Dane

- **jawny/szyfrogram** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego
- **klucz** - ciąg znaków składający się z małych liter alfabetu angielskiego

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Szyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $$1$$ do $$26$$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja SzyfrujVigenere(jawny, klucz):
    1. szyfrogram := ""
    2. kluczIndeks := 1
    3. Dla i := 1 do Długość(jawny), wykonuj:
        4. nowaPozycja := Pozycja(jawny[i]) + Pozycja(klucz[kluczIndeks])
        5. Jeżeli nowaPozycja > 26, to:
            6. nowaPozycja := nowaPozycja - 26
        7. nowaLitera := Alfabet(nowaPozycja)
        8. szyfrogram := szyfrogram + nowaLitera
        9. kluczIndeks := kluczIndeks + 1
        10. Jeżeli kluczIndeks > Długość(klucz), to:
            11. kluczIndeks := 1

    12. Zwróć szyfrogram 
```

## Deszyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $$1$$ do $$26$$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja DeszyfrujVigenere(szyfrogram, klucz):
    1. jawny := ""
    2. kluczIndeks := 1
    3. Dla i := 1 do Długość(szyfrogram), wykonuj:
        4. nowaPozycja := Pozycja(jawny[i]) - Pozycja(klucz[kluczIndeks])
        5. Jeżeli nowaPozycja < 1, to:
            6. nowaPozycja := 26 + nowaPozycja
        7. nowaLitera := Alfabet(nowaPozycja)
        8. jawny := jawny + nowaLitera
        9. kluczIndeks := kluczIndeks + 1
        10. Jeżeli kluczIndeks > Długość(klucz), to:
            11. kluczIndeks := 1

    12. Zwróć jawny 
```

## Implementacja

### C++

{% content-ref url="../../../programming/c++/algorithms/cryptography/vigenere.md" %}
[vigenere.md](../../../programming/c++/algorithms/cryptography/vigenere.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../../programming/python/algorithms/cryptography/vigenere.md" %}
[vigenere.md](../../../programming/python/algorithms/cryptography/vigenere.md)
{% endcontent-ref %}
