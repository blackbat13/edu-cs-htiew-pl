# Block diagram

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    START([START]) --> K1[/Wczytaj a, b/]
    K1 --> K2{a = b}
    K2 -- PRAWDA --> K3[/Wypisz '='/]
    K2 -- FAŁSZ --> K4{a < b}
    K4 -- PRAWDA --> K5[/Wypisz '<'/]
    K4 -- FAŁSZ --> K7[/Wypisz '>'/]
    K3 --> STOP([STOP])
    K5 --> STOP
    K7 --> STOP 
```
