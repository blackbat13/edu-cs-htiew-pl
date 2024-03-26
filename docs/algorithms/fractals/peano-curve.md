# Krzywa Peano

## Opis problemu

### Specyfikacja

#### Dane

- **stopień** - stopień fraktala
- **kąt** - kąt obrotu
- **długość** - długość linii

### Przykład 1

Krzywa Peano o stopniu $4$ i kącie $90\degree$.

![Krzywa Peano](../../assets/peano_curve_4_90.bmp)

### Przykład 2

Krzywa Peano o stopniu $4$ i kącie $60\degree$.

![Krzywa Peano](../../assets/peano_curve_4_60.bmp)

## Rozwiązanie

### Pseudokod

```
procedura KrzywaPeano(stopień, kąt, długość):
    1. Jeżeli stopień = 0, to:
        2. Zakończ
    3. Prawo(kąt)
    4. KrzywaPeano(stopień - 1, -kąt, długość)
    5. Przód(długość)
    6. KrzywaPeano(stopień - 1, kąt, długość)
    7. Przód(długość)
    8. KrzywaPeano(stopień - 1, -kąt, długość)
    9. Lewo(kąt)
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    START(["KrzywaPeano(stopień, kąt, długość"]) --> K1{stopień = 0}
    K1 -- PRAWDA --> K2["Przód(długość)"]
    K2 --> STOP([STOP])
    K1 -- FAŁSZ --> K4["Prawo(kąt)\nKrzywaPeano(stopień - 1, -kąt, długość)\nPrzód(długość)\nKrzywaPeano(stopień - 1, kąt, długość)\nPrzód(długość)\nKrzywaPeano(stopień - 1, -kąt, długość)\nLewo(kąt)"]
    K4 --> STOP
```

## Implementacja

### C++


[peano-curve.md](../../programming/c++/algorithms/fractals/peano-curve.md)


### Python


[peano-curve.md](../../programming/python/algorithms/fractals/peano-curve.md)


### Blockly


[peano-curve.md](../../programming/blockly/algorithms/fractals/peano-curve.md)

