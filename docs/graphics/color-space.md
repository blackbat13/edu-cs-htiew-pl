# Przestrzeń kolorów w grafice komputerowej

Przestrzeń kolorów to matematyczny model opisujący sposób reprezentowania kolorów za pomocą zestawu liczb, zwykle trzech lub czterech składników. W grafice komputerowej, zrozumienie różnych przestrzeni kolorów jest kluczowe dla poprawnego przechowywania, przetwarzania i wyświetlania obrazów.

## Podstawowe przestrzenie kolorów

1. **RGB (Red, Green, Blue)**
   - Najczęściej stosowana przestrzeń kolorów w grafice komputerowej, opierająca się na trzech podstawowych składnikach światła: czerwonym, zielonym i niebieskim.
   - Zastosowanie: monitory, telewizory, skanery, aparaty cyfrowe.
   
2. **CMYK (Cyan, Magenta, Yellow, Key/Black)**
   - Używa czterech kolorów atramentu.
   - Zastosowanie: druk w kolorze.
   
3. **HSV/HSL (Hue, Saturation, Value/Lightness)**
   - Reprezentacja kolorów za pomocą ich odcienia, nasycenia i jasności.
   - Zastosowanie: edycja graficzna, analiza i przetwarzanie obrazów.
   
4. **YUV**
   - Oddziela informacje o jasności (Y) od informacji o kolorze (UV).
   - Zastosowanie: telewizja, kompresja wideo.
   
5. **Lab**
   - Ludzkie oko postrzega kolory w sposób, który różni się od czysto fizycznych składników światła; przestrzeń Lab stara się przybliżyć ludzki sposób postrzegania kolorów.
   - Zastosowanie: analiza i przetwarzanie obrazów, druk.

## Konwersja pomiędzy przestrzeniami

Przekształcanie kolorów z jednej przestrzeni do innej nierzadko wiąże się z pewnymi utratami. Na przykład konwersja z RGB do CMYK może nie być jednoznaczna, ponieważ przestrzenie te nie pokrywają się dokładnie (nie wszystkie kolory RGB mogą być dokładnie oddane w CMYK).

## Głębokość kolorów

Dotyczy liczby bitów używanych do reprezentowania koloru każdego piksela. Na przykład:

- **8-bit**: 256 kolorów
- **16-bit**: 65,536 kolorów
- **24-bit**: ponad 16 milionów kolorów (prawdziwe kolory)
- **32-bit**: ponad 16 milionów kolorów plus kanał alfa do przezroczystości

## Przestrzenie kolorów a kalibracja

Dla profesjonalistów z branży graficznej kluczowe jest, aby kolory na ekranie monitora były wiernie oddane w stosunku do oryginału lub druku. Dlatego kalibracja monitora i stosowanie odpowiednich profilów ICC jest tak ważne.

## Prezentacja

Krótka prezentacja na temat przestrzeni kolorów.

{% file src="../.gitbook/assets/Przestrzenie Kolorów.pdf" %}
Przestrzenie kolorów
{% endfile %}