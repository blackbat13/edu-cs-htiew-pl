# Zapis stałoprzecinkowy

Reprezentacja liczb rzeczywistych w systemie binarnym w zapisie stałoprzecinkowym jest istotnym konceptem w informatyce, szczególnie w kontekście zastosowań inżynieryjnych i naukowych. Ten sposób reprezentacji jest prosty, ale ma ograniczenia w kontekście zakresu i precyzji. Zrozumienie tego konceptu jest kluczowe do pracy z systemami binarnymi i digitalizacją sygnałów.

Zacznijmy od podstawowych zagadnień:

- **Reprezentacja liczby**: liczby rzeczywiste w systemie binarnym w zapisie stałoprzecinkowym są reprezentowane jako ciągi bitów, które są podzielone na dwie części: część całkowitą i część ułamkową, rozdzielone stałym miejscem, zwanym przecinkiem.
- **Część całkowita**: część liczby znajdująca się po lewej stronie przecinka. Konwertowana jest na binarny w sposób podobny do konwersji liczb całkowitych.
- **Część ułamkowa**: część liczby znajdująca się po prawej stronie przecinka. Konwertowana jest na binarny przez mnożenie przez $$2$$ i zapisywanie części całkowitej wyniku na każdym etapie, aż do uzyskania wyniku zero lub osiągnięcia wymaganej precyzji.

## Przykład

### Krok 1

Oddziel część całkowitą i ułamkową liczby rzeczywistej.

Liczba dziesiętna: $$10.625$$

### Krok 2

Konwertuj część całkowitą na binarny.

$$10_{10}=1010_2$$

### Krok 3 

Konwertuj część ułamkową na binarny.

Część ułamkowa ($$0.625$$):

1. $$0.625 * 2 = 1.25$$ (zapisz $$1$$)
2. $$0.25 * 2 = 0.5$$ (zapisz $$0$$)
3. $$0.5 * 2 = 1.0$$ (zapisz $$1$$)

Więc $$0.625_{10}=0.101_2$$

### Krok 4

Połącz część całkowitą i ułamkową w jednym zapisie: $$10.625_{10}=1010.101_2$$

## Zalety i Wady

### Zalety

- Prostota reprezentacji.
- Łatwe dodawanie i odejmowanie.

### Wady

- Ograniczona precyzja.
- Problem z reprezentacją niektórych liczb ułamkowych (np. $$0.1$$ nie ma dokładnej reprezentacji binarnej).
- Może wymagać dużej liczby bitów do reprezentacji liczb z dużą precyzją.

## Zastosowania

Zapisy stałoprzecinkowe są często używane w aplikacjach, gdzie zakres liczb jest ograniczony i znany z góry. Jest on również używany w systemach wbudowanych z powodu swojej prostoty i mniejszych wymagań zasobów w porównaniu z zapisem zmiennoprzecinkowym.

## Podsumowanie

Reprezentacja liczb rzeczywistych w systemie binarnym w zapisie stałoprzecinkowym jest istotna dla wielu dziedzin inżynierii i informatyki. Oferuje ona prosty sposób reprezentowania liczb rzeczywistych, ale z pewnymi ograniczeniami związanymi z precyzją i zakresem.