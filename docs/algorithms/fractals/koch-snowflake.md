# Płatek Kocha

## Opis problemu

Płatek Kocha to fraktal stworzony poprzez złożenie ze sobą trzech krzywych Kocha, tak że razem tworzą strukturę przypominającą płatek śniegu.

### Specyfikacja

#### Dane

* $$stopień$$ - stopień fraktala
* $$długość$$ - długość linii

#### Wynik

* Płatek Kocha stopnia $$stopień$ i długości $$długość$$.

## Rozwiązanie

### Pseudokod

```
procedura KrzywaKocha(stopień, długość):
    1. Jeżeli stopień = 0, to:
        2. Przód(długość)
        3. Zakończ
    4. KrzywaKocha(stopień - 1, długość)
    5. Lewo(60)
    6. KrzywaKocha(stopień - 1, długość)
    7. Prawo(120)
    8. KrzywaKocha(stopień - 1, długość)
    9. Lewo(60)
    10. KrzywaKocha(stopień - 1, długość)
```

```
procedura PłatekKocha(stopień, długość):
    1. Dla i := 1 do 3, wykonuj:
        2. KrzywaKocha(stopień, długość)
        3. Prawo(120)
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    START(["KrzywaKocha(stopień, długość"]) --> K1{stopień = 0}
    K1 -- PRAWDA --> K2["Przód(długość)"]
    K2 --> STOP([STOP])
    K1 -- FAŁSZ --> K4["KrzywaKocha(stopień - 1, długość)\nLewo(60)\nKrzywaKocha(stopień - 1, długość)\nPrawo(120)\nKrzywaKocha(stopień - 1, długość)\nLewo(60)\nKrzywaKocha(stopień - 1, długość)"]
    K4 --> STOP
```

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    START(["PłatekKocha(stopień, długość"]) --> K0[i := 1]
    K0 --> K1{i <= 3}
    K1 -- PRAWDA --> K2["KrzywaKocha(stopień, długość)\nPrawo(120)"]
    K2 --> K1i[i := i + 1]
    K1i --> K1
    K1 -- FAŁSZ ---> STOP([STOP])
```

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/fractals/koch-snowflake.md" %}
[koch-snowflake.md](../../programming/c++/algorithms/fractals/koch-snowflake.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/fractals/koch-snowflake.md" %}
[koch-snowflake.md](../../programming/python/algorithms/fractals/koch-snowflake.md)
{% endcontent-ref %}

### Blockly

{% content-ref url="../../programming/blockly/algorithms/fractals/koch-snowflake.md" %}
[koch-snowflake.md](../../programming/blockly/algorithms/fractals/koch-snowflake.md)
{% endcontent-ref %}
