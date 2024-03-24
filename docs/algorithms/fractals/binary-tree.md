# Drzewo binarne

## Opis problemu

### Specyfikacja

#### Dane

* $$stopień$$ - stopień drzewa binarnego
* $$długość$$ - początkowa długość gałęzi (pnia)

#### Wynik

* Drzewo binarne stopnia $$stopień$$ i początkowej długości $$długość$$.

### Prezentacja

{% file src="../../.gitbook/assets/Drzewo Binarne (1).pdf" %}
Drzewo binarne - wprowadzenie
{% endfile %}

## Rozwiązanie

### Prezentacja

{% file src="../../.gitbook/assets/Drzewo Binarne - algorytm (1).pdf" %}
Drzewo binarne - algorytm
{% endfile %}

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

### C++

{% content-ref url="../../programming/c++/algorithms/fractals/binary-tree.md" %}
[binary-tree.md](../../programming/c++/algorithms/fractals/binary-tree.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/fractals/binary-tree.md" %}
[binary-tree.md](../../programming/python/algorithms/fractals/binary-tree.md)
{% endcontent-ref %}

### Blockly

{% content-ref url="../../programming/blockly/algorithms/fractals/binary-tree.md" %}
[binary-tree.md](../../programming/blockly/algorithms/fractals/binary-tree.md)
{% endcontent-ref %}
