# Zapis zmiennoprzecinkowy

Reprezentacja liczb rzeczywistych w zapisie zmiennoprzecinkowym w systemie binarnym to technika, która umożliwia efektywne przechowywanie i manipulację liczbami rzeczywistymi w komputerze. W tej metodzie liczby reprezentowane są za pomocą trzech składników: **znaku**, **mantysy** i **cechy**.

## Struktura

Liczby zmiennoprzecinkowe zazwyczaj są przedstawione zgodnie ze standardem IEEE 754, który określa strukturę jak następuje:

- **Bit Znaku** (ang. *Sign Bit*): określa znak liczby; $0$ oznacza dodatni, a $1$ oznacza ujemny.
- **Cecha** (ang. *Exponent*): reprezentuje wykładnik liczby w postaci znormalizowanej; reprezentowana za pomocą $8$ bitów w pojedynczej precyzji, $11$ bitów w podwójnej precyzji.
- **Mantysa** (ang. *Fraction*): zawiera cyfry znaczące liczby; reprezentowana za pomocą $23$ bitów w pojedynczej precyzji, $52$ bitów w podwójnej precyzji.

## Konwersja z systemu dziesiętnego

Jak przedstawić liczbę rzeczywistą w systemie binarnym w zapisie zmiennoprzecinkowym opisuje poniższa lista kroków.

1. **Określenie znaku**: ustalamy znak liczby.
2. **Znalezienie reprezentacji binarnych**: zamieniamy liczbę na równoważną liczbę binarną (przed i po kropce dziesiętnej).
3. **Normalizacja**: przesuwamy przecinek binarny tak, aby przed nim była tylko jedna cyfra $1$. Zapisujemy wykładnik przedstawiający liczbę miejsc, o które przesunięto przecinek.
4. **Określenie cechy i mantysy**: wyodrębniamy wartość cechy i mantysę ze znormalizowanej formy.

### Przykład konwersji

Załóżmy, że chcemy przedstawić liczbę $-110.75$ w formie zmiennoprzecinkowej (w standardzie IEEE 754 z pojedynczą precyzją):

1. **Znak**: liczba jest ujemna, więc bit znaku będzie $1$.
2. **Reprezentacja binarna**: $110.75$ w binarnym to $110.11_2$.
3. **Normalizacja**: $110.11_2$ może być znormalizowane jako $1.1011_2 \times 2^2$.
4. **Cecha i mantysa**:
    - **Cecha**: $2 + 127$ (wartość bias) = $129$, co daje nam $10000001_2$.
    - **Mantysa**: $.1011_2$ (pomijając ukrytą jedynkę).

Stąd, $-110.75$ przedstawiamy jako:

$1\ 10000001\ 10110000000000000000000$

## Zastosowania i ważne kwestie

- **Precyzja**: reprezentacja zmiennoprzecinkowa może prowadzić do błędów zaokrąglenia, ponieważ nie wszystkie liczby dziesiętne mogą być dokładnie przedstawione w binarnym zapisie zmiennoprzecinkowym.
- **Zakres**: reprezentacja ta pozwala na przedstawienie bardzo małych i bardzo dużych liczb, co jest szczególnie przydatne w obliczeniach naukowych i inżynieryjnych.
- **Szybkość**: operacje na liczbach zmiennoprzecinkowych mogą być wolniejsze w porównaniu z operacjami na liczbach całkowitych, szczególnie w przypadku procesorów z ograniczoną obsługą operacji zmiennoprzecinkowych.

## Podsumowanie

Zapis zmiennoprzecinkowy w systemie binarnym jest niezbędnym narzędziem w informatyce, umożliwiającym reprezentację i manipulację liczbami rzeczywistymi w skomputeryzowanych systemach. Choć może prowadzić do błędów zaokrąglenia, jego elastyczność i zakres sprawiają, że jest to dominujący sposób reprezentacji liczb rzeczywistych w komputerach.
