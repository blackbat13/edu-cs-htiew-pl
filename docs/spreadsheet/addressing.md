# Adresowanie komórek w arkuszu kalkulacyjnym

W arkuszu kalkulacyjnym każda komórka jest unikalnie identyfikowana przez jej adres, który składa się z oznaczenia kolumny (liter) i numeru wiersza. Na przykład, komórka w pierwszej kolumnie i pierwszym wierszu będzie miała adres **A1**.

## Typy Adresowania

1. **Adresowanie względne:**
   - W adresowaniu względnym, adres komórki zmienia się, gdy formuła jest kopiowana lub przenoszona do innej komórki.
   - Przykład: Jeśli masz formułę `=A1+1` w komórce B1 i skopiujesz ją do B2, formuła zmieni się na `=A2+1`.

2. **Adresowanie bezpośrednie:**
   - W adresowaniu bezpośrednim, adres komórki pozostaje niezmienny, niezależnie od tego, gdzie formuła jest kopiowana.
   - To osiąga się przez dodanie znaku dolara ($) przed literą kolumny i/lub numerem wiersza. Na przykład: `$A$1`.
   - Przykład: Jeśli masz formułę `=$A$1+1` w komórce B1 i skopiujesz ją do B2, formuła pozostanie `=$A$1+1`.

3. **Mieszane adresowanie:**
   - Kombinuje adresowanie względne i bezpośrednie, gdzie albo kolumna, albo wiersz jest zakotwiczony.
   - Przykłady: `$A1` (kolumna A jest zakotwiczona) lub `A$1` (wiersz 1 jest zakotwiczony).

## Zakotwiczanie wierszy i kolumn

Zakotwiczanie jest używane, gdy potrzebujesz odwołać się do konkretnej komórki lub zakresu komórek, niezależnie od tego, gdzie w arkuszu umieszczasz lub kopiujesz formułę.

Załóżmy, że masz wartość stałą w komórce A1, którą chcesz użyć w serii obliczeń w kolumnie B. Używając adresowania `$A$1` w formule, możesz swobodnie kopiować tę formułę w dół kolumny B, zachowując stałe odwołanie do komórki A1.

## Przykład: tabliczka mnożenia

W tym przykładzie pokazujemy, jak używać adresowania mieszanego, aby utworzyć tabliczkę mnożenia.

![](../assets/spreadsheet/multiplication.gif)
