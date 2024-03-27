# Szyfr Playfaira

Szyfr Playfair, wynaleziony w 1854 roku przez Charlesa Wheatstone’a i promowany przez lorda Playfaira, jest techniką szyfrowania digrafów (par liter). To jeden z pierwszych prób stworzenia bardziej skomplikowanego szyfru niż tradycyjne szyfry monoalfabetyczne.

## Opis działania

1. **Klucz**: wybierz frazę kluczową (np. "KRYPTOGRAFIA"). Usuń z niej powtarzające się litery i wypełnij resztę literami alfabetu (w większości implementacji litery "I" i "J" są traktowane jako jedno). 

2. **Macierz 5x5**: utwórz macierz $5\times5$ i wypełnij ją literami uzyskanymi w poprzednim kroku.

3. **Szyfrowanie**:
   - Tekst jawny dzieli się na pary liter. Jeśli litera w parze się powtarza lub jest nieparzysta liczba liter, dodaj "X" lub inną literę dla wyrównania.
   - Dla każdej pary:
     - Jeśli obie litery znajdują się w tym samym wierszu, zastąp je literami po prawej stronie (lub z lewej, jeśli są na końcu).
     - Jeśli obie litery znajdują się w tej samej kolumnie, zastąp je literami poniżej (lub powyżej, jeśli są na dole).
     - W przeciwnym razie zastąp je literami z ich własnego wiersza, ale kolumny drugiej litery.

4. **Deszyfrowanie**: proces ten jest odwrotny do szyfrowania, z wyjątkiem tego, że litery są przesuwane w lewo lub w górę, zamiast w prawo lub w dół.

### Przykład

Załóżmy, że mamy klucz "KRYPTOGRAFIA" i wiadomość "TEKST". Po utworzeniu macierzy i podzieleniu tekstu na pary ("TE", "KS", "TX"), szyfrowanie przebiega według zasad wymienionych powyżej.

## Bezpieczeństwo

Szyfr Playfair jest bardziej bezpieczny niż szyfry monoalfabetyczne, ponieważ uwzględnia pary liter, co sprawia, że analiza częstotliwości jest trudniejsza. Niemniej jednak, ze względu na jego deterministyczną naturę, jest podatny na bardziej zaawansowane metody kryptoanalizy i nie jest odpowiedni dla nowoczesnych zastosowań..

## Specyfikacja

### Dane

- **jawny/szyfrogram** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego
- **klucz** - ciąg znaków składający się z małych liter alfabetu angielskiego

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Implementacja

### [C++](../../../programming/c++/algorithms/cryptography/playfair.md)

### [Python](../../../programming/python/algorithms/cryptography/playfair.md)
