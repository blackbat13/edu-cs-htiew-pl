# Pierwiastek kwadratowy

## Opis problemu

Jak policzyć pierwiastek kwadratowy z podanej liczby, gdy nie mamy przy sobie kalkulatora, ani wbudowanych metod programistycznych?

### Specyfikacja

#### Dane

* $$n$$ — liczba rzeczywista.
* $$p$$ — liczba rzeczywista, dokładność.

#### Wynik

* $$\sqrt{n}$$ policzony z dokładnością $$p$$

## Rozwiązanie — metoda Herona

### Pseudokod

```
funkcja MetodaHerona(n, p)
    1. x1 := n / 2
    2. x2 := (x1 + (n / x1)) / 2
    3. Dopóki |x2 - x1| > p, wykonuj:
        4. x1 := (x2 + (n / x2)) / 2
        3. Zamień(x1, x2)
    4. Zwróć x2
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
	START(["MetodaHerona(n, p)"]) --> K1["x1 := n / 2\nx2 := (x1 + (n / x1)) / 2"]
	K1 --> K3{"|x2 - x1| > p"}
	K3 -- PRAWDA --> K4["x1 := (x2 + (n / x2)) / 2\nZamień(x1, x2)"]
	K4 --> K3
    K3 -- FAŁSZ --> K6[/Zwróć x2/]
    K6 --> STOP([STOP])
```

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/numerical-methods/square-root.md" %}
[square-root.md](../../programming/c++/algorithms/numerical-methods/square-root.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/numerical-methods/square-root.md" %}
[square-root.md](../../programming/python/algorithms/numerical-methods/square-root.md)
{% endcontent-ref %}
