# Drzewo binarne

## Opis problemu

### Specyfikacja

#### Dane

* $stopień$ - stopień drzewa binarnego
* $długość$ - początkowa długość gałęzi (pnia)

#### Wynik

* Drzewo binarne stopnia $stopień$ i początkowej długości $długość$.

### Prezentacja

[:fontawesome-solid-file-pdf: Drzewo binarne - wprowadzenie](../../assets/Drzewo Binarne (1).pdf)

## Rozwiązanie

### Prezentacja

[:fontawesome-solid-file-pdf: Drzewo binarne - algorytm](../../assets/Drzewo Binarne - algorytm (1).pdf)

### Pseudokod

```
funkcja DrzewoBinarne(stopień, długość):
    1. Przód(długość)
    2. Jeżeli stopień > 0, to:
        3. Lewo(45)
        4. DrzewoBinarne(stopień - 1, długość / 2)
        5. Prawo(90)
        6. DrzewoBinarne(stopień - 1, długość / 2)
        7. Lewo(45)
    8. Tył(długość)
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
	START(["DrzewoBinarne(stopień, długość)"]) --> K1["Przód(długość)"]
	K1 --> K2{stopień > 0}
	K2 -- PRAWDA --> K3["Lewo(45)\nDrzewoBinarne(stopień - 1, długość / 2)\nPrawo(90)\nDrzewoBinarne(stopień - 1, długość / 2)\nLewo(45)"]
	K3 --> K8["Tył(długość)"]
	K2 -- FAŁSZ --> K8
	K8 --> STOP([STOP])
```

## Implementacja

### [C++](../../programming/c++/algorithms/fractals/binary-tree.md)

### [Python](../../programming/python/algorithms/fractals/binary-tree.md)

### [Blockly](../../programming/blockly/algorithms/fractals/binary-tree.md)
