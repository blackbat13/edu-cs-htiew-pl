# Rozwiązania

## Część I

### Zadanie 3

#### 3.3

```
1. Dla i := 0 do k, wykonuj:
    2. Z[i] := 0
3. Dla i := 0 do n - 1, wykonuj:
    4. Z[T[i]] := Z[T[i]] + 1
5. min = n + 1
6. maks = Z[0]
7. Dla i := 1 do k, wykonuj:
    8. Jeżeli Z[i] < min oraz Z[i] != 0, to:
        9. min := Z[i]
    10. Jeżeli Z[i] > maks, to:
        11. maks := Z[i]
12. Wypisz "Najczesciej: "
13. Dla i := 0 do k, wykonuj:
    14. Jeżeli Z[i] = min, to:
        15. Wypisz i
16. Wypisz "Najrzadziej: "
17. Dla i := 0 do k, wykonuj:
    18. Jeżeli Z[i] = maks, to:
        19. Wypisz i
```

## Część II

### Zadanie 5

{% file src="../../../.gitbook/assets/5_2018_p.xlsx" %}
Excel
{% endfile %}
