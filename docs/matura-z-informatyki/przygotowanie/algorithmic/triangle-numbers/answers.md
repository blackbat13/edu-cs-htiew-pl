# Rozwiązania

## Zadanie 1

| $k$  | $k$ jest liczbą trójkątną | $n$ |
| ---- | ------------------------- | ---- |
| 6    | TAK                       | 3    |
| 8    | NIE                       | -    |
| 18   | NIE                       | -    |
| 28   | TAK                       | 7    |
| 56   | NIE                       | -    |
| 465  | TAK                       | 30   |

## Zadanie 2

### Rozwiązanie logarytmiczne

```
funkcja czy_trojkatna(k):
    1. lewy := 1
    2. prawy := k
    3. Dopóki lewy <= prawy:
        4. srodek := (lewy + prawy) div 2
        5. suma := ((1 + srodek) * srodek) / 2
        6. Jeżeli suma = k, to:
            7. Zwróć PRAWDA i zakończ
        8. w przeciwnym przypadku, jeżeli suma < k, to:
            9. lewy := srodek + 1
        10. w przeciwnym przypadku:
            11. prawy := srodek - 1
    12. Zwróć FAŁSZ i zakończ
```

### Rozwiązanie liniowe

```
funkcja czy_trojkatna(k):
    1. suma := 0
    2. i := 1
    3. Dopóki suma < k, wykonuj:
        4. suma := suma + i
        5. i := i + 1
    6. Jeżeli suma = k, to:
        7. Zwróć PRAWDA i zakończ
    8. Zwróć FAŁSZ i zakończ
```

## Zadanie 3

### Odpowiedź

```
1034920260
1116352126
1061521926
1109228550
1122645420
1055264770
1053060778
1183824811
1219167510
1204104201
```

### Rozwiązanie

=== "Python"

    ```python linenums="1"
    def is_triangle_number(k):
        left = 1
        right = k
        while left <= right:
            middle = (left + right) // 2
            n_sum = ((1 + middle) * middle) // 2
            if n_sum == k:
                return True
            elif n_sum < k:
                left = middle + 1
            else:
                right = middle - 1

        return False


    with open("trojkatne.txt") as file:
        numbers = [int(line) for line in file]

    triangle_numbers = [k for k in numbers if is_triangle_number(k)]

    print(*triangle_numbers, sep="\n")
    ```
