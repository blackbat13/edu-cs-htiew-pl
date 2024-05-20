# Rozwiązania

## Zadanie 1

- Długość: 10
- Początek: 702
- Koniec: 711
- Znak: 1

=== Python

    ```python linenums="1"
    with open("long_bin.txt") as file:
        bin_num = file.read().strip()

    current_digit = ""
    current_length = 0
    current_start = 0
    max_length = 0
    max_start = 0
    max_digit = ""

    for i, digit in enumerate(bin_num):
        if digit == current_digit:
            current_length += 1
        else:
            current_digit = digit
            current_length = 1
            current_start = i

        if current_length > max_length:
            max_length = current_length
            max_start = current_start
            max_digit = current_digit

    print("Długość:", max_length)
    print("Początek:", max_start + 1)
    print("Koniec:", max_start + max_length)
    print("Znak:", max_digit)
    ```

## Zadanie 2

```sql
SELECT imie, nazwisko, nazwa, AVG(ocena) AS srednia
FROM Oceny
JOIN Uczniowie ON Oceny.uczen_id = Uczniowie.id
JOIN Przedmioty ON Oceny.przedmiot_id = Przedmioty.id
WHERE nazwa = 'matematyka' OR nazwa = 'informatyka'
GROUP BY Uczniowie.id, imie, nazwisko, nazwa
HAVING srednia > 5
ORDER BY srednia ASC;
```

## Zadanie 3

- Liczba błędnych wpisów:	493
- Najczęściej odwiedzana strona:	huff.com
- Najdłużej odwiedzana strona:	allen.com

[:material-microsoft-excel: visits-solution.xlsx](../../../../assets/repeat-1/visits-solution.xlsx)

## Zadanie 4

|      **Karty**      | **Liczba kart na lewej ręce** | **Kolor karty na lewej ręce** |
|:-------------------:|:-----------------------------:|:-----------------------------:|
| 2, 5, 1, 1, 2, 1, 1 |               3               |               1               |
|      2, 2, 1, 1     |               0               |               -               |
| 2, 2, 3, 2, 4, 2, 3 |               1               |               2               |
| 3, 2, 3, 2, 3, 5, 5 |               1               |               5               |

```
1. lewa_kolor := 0
2. lewa_licznik := 0
3. maks_licznik := 0
4. Dla i := 1 do n, wykonuj:
    5. prawa := karty[i]
    6. Jeżeli lewa_licznik = 0, to:
        7. lewa_kolor := prawa
        8. lewa_licznik := 1
    9. w przeciwnym przypadku, jeżeli lewa_kolor = prawa, to:
        10. lewa_licznik := lewa_licznik + 1
    11. w przeciwnym przypadku, to:
        12. lewa_licznik := lewa_licznik - 1
    13. Jeżeli lewa_licznik > maks_licznik, to:
        14. maks_licznik := lewa_licznik
15. Wypisz maks_licznik
```

## Zadanie 5

- Najmniejsza liczba: $101010111_{U2}$
- Największa liczba: $011011110_{U2}$

=== Python

    ```python linenums="1"
    def u2_to_int(u2_num):
        first_digit = u2_num[0]
        if first_digit == "0":
            return int(u2_num, 2)
        return int(u2_num[1:], 2) - 2 ** (len(u2_num) - 1)


    with open("u2.txt") as file:
        u2_numbers = file.read().strip().split()

    u2_numbers.sort(key=lambda el: u2_to_int(el))

    print("Minimum:", u2_numbers[0])
    print("Maksimum:", u2_numbers[-1])
    ```

## Zadanie 6

Liczba: 8
Pierwszy: 5 kut-kutek
Ostatni: 138 fpuh

[:material-microsoft-access: characters-solution.accdb](../../../../assets/repeat-1/characters-solution.accdb)