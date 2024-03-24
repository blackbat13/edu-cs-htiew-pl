# Rozwiązania

## Część I

### Zadanie 1

#### c)

```
1. Zapamiętujemy pierwszy bit z liczby
2. Usuwamy pierwszy bit z liczby
3. Jeżeli pierwszy bit to 1, to zamieniamy znaki na przeciwne
4. Konwertujemy na dziesiętny
5. Jeżeli pierwszy bit to 1, to mnożymy wynik przez -1
```

```
1. x := 0
2. Jeżeli bin[1] = 1, to:
    3. Od i := 2 do d, wykonuj:
        4. Jeżeli bin[i] = 0:
            5. bin[i] = 1
        6. w przeciwnym przypadku
            7. bin[i] = 0
8. p := 1
9. Od i := d do 2, wykonuj:
    10. x := x + bin[i] * p
    11. p := p * 2
12. Jeżeli bin[1] = 1:
    13. x := x * -1
14. Wypisz x
```
