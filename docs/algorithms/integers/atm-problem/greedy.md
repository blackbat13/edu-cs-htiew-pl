# Rozwiązanie zachłanne

### Funkcje pomocnicze

- **Sortuj(tablica)** - sortuje tablicę **malejąco**

### Pseudokod

```
funkcja Reszta(n, nominały, kwota):
    1. Sortuj(nominały)
    2. wynik := 0
    3. Od i := 1 do n, wykonuj:
        4. Dopóki kwota >= nominały[i], to:
            5. kwota := kwota - nominały[i]
            6. wynik := wynik + 1
            
    7. Zwróć wynik
```

#### Optymalizacja

```
funkcja Reszta(n, nominały, kwota):
    1. Sortuj(nominały)
    2. wynik := 0
    3. Od i := 1 do n, wykonuj:
        4. Jeżeli kwota >= nominały[i], to:
            5. wynik := wynik + kwota div nominały[i]
            6. kwota := kwota mod nominały[i]
            
    7. Zwróć wynik
```

!!! info
	**div** oznacza dzielenie całkowite
	
	**mod** oznacza resztę z dzielenia

### Złożoność

$O(n)$ - liniowa (przy zastosowaniu odpowiedniego algorytmu sortowania)

## Implementacja

### C++


[change.md](../../../programming/c++/algorithms/integers/change.md)


### Python


[change.md](../../../programming/python/algorithms/integers/change.md)

