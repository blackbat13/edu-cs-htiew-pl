# Zbiór Cantora

## Opis problemu

### Specyfikacja

#### Dane

* $stopień$ - stopień
* $długość$ - początkowa długość

## Rozwiązanie

### Pseudokod

```
funkcja ZbiórCantora(stopień, długość):
    1. Jeżeli stopień > 0, to:
        2. ZbiórCantora(stopień - 1, długość / 3)
        3. PodnieśPisak()
        4. Przód(długość / 3)
        5. OpóśćPisak()
        6. ZbiórCantora(stopień - 1, długość / 3)
    7. w przeciwnym przypadku:
        8. Przód(długość)
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
	START(["ZbiórCantora(stopień, długość)"]) --> K1{stopień > 0}
    K1 -- PRAWDA --> K2["ZbiórCantora(stopień - 1, długość / 3)\nPodnieśPisak()\nPrzód(długość / 3)\nOpóśćPisak()\nZbiórCantora(stopień - 1, długość / 3)"]
    K1 -- FAŁSZ --> K8["Przód(długość)"]
    K2 --> STOP([STOP])
    K8 --> STOP
```
## Implementacja

### [C++](../../programming/c++/algorithms/fractals/cantor-dust.md)

### [Python](../../programming/python/algorithms/fractals/cantor-dust.md)

### [Blockly](../../programming/blockly/algorithms/fractals/cantor-dust.md)
