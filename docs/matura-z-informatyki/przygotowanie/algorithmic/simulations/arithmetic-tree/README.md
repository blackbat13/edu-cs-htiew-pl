# Drzewa wyrażeń arytmetycznych

## Pseudokod

```
funkcja Oblicz(wierzchołek):
    1. Jeżeli wierzchołek jest liściem, to:
        2. Zwróć wartość wierzchołka
    3. Zwróć wynik operacji arytmetycznej, gdzie operatorem jest wartość wierzchołka, a wartościami są odpowiednio Oblicz(lewy potomek) oraz Oblicz(prawy potomek)
```

## Zadanie 1

Zapoznaj się z pseudokodem opisującym sposób obliczania wartości wyrażenia arytmetycznego zapisanego za pomocą drzewa binarnego, a następnie oblicz wartość wyrażenia reprezentowanego przez poniższe drzewo. Zapisz poszczególne kroki obliczeń poprzez przedstawienie zmieniającego się drzewa binarnego, gdzie, w odpowiedniej kolejności, poddrzewa są zastępowane poprzez jeden wierzchołek zawierający wartość wyrażenia arytmetycznego, które zostało obliczone na tym poddrzewie.

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    op1["\-"] --> op2["\*"]
    op1 --> op3["/"]
    op3 --> n1["5"]
    op3 --> n2["1"]
    op2 --> op4["\+"]
    op4 --> n3["2"]
    op4 --> n4["3"]
    op2 --> n5["4"]
```

## Zadanie 2

Wykonaj polecenie z zadania pierwszego opierając się na poniższym drzewie.

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    op1["\-"] --> op2["\*"]
    op2 --> n1["10"]
    op2 --> op3["\+"]
    op3 --> op4["/"]
    op3 --> n2["8"]
    op4 --> n3["15"]
    op4 --> n4["5"]
    op1 --> n5["3"] 
```

## Zadanie 3

Przedstaw poniższe wyrażenie arytmetyczne w postaci drzewa wyrażeń arytmetycznych.

$4 + (9 - 3) * (6 / 2)$
