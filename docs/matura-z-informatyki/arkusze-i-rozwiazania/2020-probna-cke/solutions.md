# Rozwiązania

## Część I

### Zadanie 2

#### 2.2

```
1. czestosci := tablica o rozmiarze [1..n] wypełniona wartościami 0
2. Dla i := 1 do n, wykonuj:
  3. liczba := T[i]
  4. Dla j := 1 do n, wykonuj:
     5. Jeżeli T[j] = liczba, to:
        6. czestosci[i] := czestosci[i]+1

7. maks := czestosci[1]
8. maks_ind := 1  
9. Dla i := 1 do n, wykonuj:
  10. Jeżeli czestosci[i] > maks, to:
     11. maks := czestosci[i]
     12. maks_ind := i
     
13. Wypisz T[maks_ind]
```

```
1. maks := 0
2. moda := 0
3. Dla i := 1 do n, wykonuj:
   4. liczba := T[i]
   5. czestosc := 0
   6. Dla j := 1 do n, wykonuj:
      7. Jeżeli T[j] = liczba, to:
         8. czestosc := czestosc + 1
         
   9. Jeżeli czestosc > maks, to:
      10. maks := czestosc
      11. moda := liczba
      
12. Wypisz moda
```

## Część II

### Zadanie 4

TODO

### Zadanie 5

TODO

### Zadanie 6

{% file src="../../../.gitbook/assets/2020_p_cke_zad6.accdb" %}
Rozwiązanie - Access
{% endfile %}
