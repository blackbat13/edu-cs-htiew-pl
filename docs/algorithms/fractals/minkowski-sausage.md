# Minkowski Sausage

## Opis problemu

### Specyfikacja

#### Dane

- **stopień** - stopień fraktala
- **długość** - początkowa długość linii

## Rozwiązanie

### Pseudokod

```
procedura MinkowskiSausage(stopień, długość):
    1. Jeżeli stopień = 0, to:
        2. Przód(długość)
        3. Zakończ
    4. Prawo(30)
    5. MinkowskiSausage(stopień - 1, długość / 2)
    6. Lewo(90)
    7. MinkowskiSausage(stopień - 1, długość / 2)
    8. Prawo(90)
    9. MinkowskiSausage(stopień - 1, długość / 2)
    10. Lewo(30)
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    START(["MinkowskiSausage(stopień, długość"]) --> K1{stopień = 0}
    K1 -- PRAWDA --> K2["Przód(długość)"]
    K2 --> STOP([STOP])
    K1 -- FAŁSZ --> K4["Prawo(30)
    MinkowskiSausage(stopień - 1, długość / 2)
    Lewo(90)
    MinkowskiSausage(stopień - 1, długość / 2)
    Prawo(90)
    MinkowskiSausage(stopień - 1, długość / 2)
    Lewo(30)"]
    K4 --> STOP
```

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/fractals/minkowski-sausage.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/fractals/minkowski-sausage.md){ .md-button }

### [Blockly](../../programming/blockly/algorithms/fractals/minkowski-sausage.md){ .md-button }
