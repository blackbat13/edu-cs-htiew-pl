# Rozwiązania

## Zadanie 1

### Zadanie 1.3

=== "Python"

    ```python
    x = int(input("x = "))
    y = int(input("y = "))

    z = 0

    while y >= 1:
        if y % 2 == 1:
            z = z + x

        x = x + x
        y = y // 2

    print(z)
    ```

## Zadanie 3

### Zadanie 3.1

=== "Python"

    ```python
    with open("anagram.txt") as file:
        binary_list = file.read().split()

    result1 = 0
    result2 = 0
    for binary in binary_list:
        count0 = binary.count("0")
        count1 = binary.count("1")
        if count0 == count1:
            result1 += 1
        elif abs(count0 - count1) == 1:
            result2 += 1

    print("Zadanie 3.1")
    print("Zrównoważone:", result1)
    print("Prawie zrównoważone:", result2)
    ```

### Zadanie 3.2

=== "Python"

    ```python
    from math import factorial


    with open("anagram.txt") as file:
        binary_list = file.read().split()

    max_anagrams = 0
    for binary in binary_list:
        if len(binary) != 8:
            continue

        count0 = binary.count("0")
        count1 = binary.count("1")
        anagrams_count = factorial(8) / (factorial(count0) * factorial(count1))
        if count0 > 0:
            anagrams_count -= factorial(7) / (factorial(count0 - 1) * factorial(count1))
        if anagrams_count > max_anagrams:
            max_anagrams = anagrams_count

    print("Zadanie 3.2")
    for binary in binary_list:
        if len(binary) != 8:
            continue

        count0 = binary.count("0")
        count1 = binary.count("1")
        anagrams_count = factorial(8) / (factorial(count0) * factorial(count1))
        if count0 > 0:
            anagrams_count -= factorial(7) / (factorial(count0 - 1) * factorial(count1))
        if anagrams_count == max_anagrams:
            print(binary)
    ```

### Zadanie 3.3

=== "Python"

    ```python
    with open("anagram.txt") as file:
        binary_list = file.read().split()

    max_diff = 0
    for i in range(1, len(binary_list)):
        diff = abs(int(binary_list[i], 2) - int(binary_list[i - 1], 2))
        if diff > max_diff:
            max_diff = diff

    print("Zadanie 3.3")
    print(bin(max_diff))
    ```

### Zadanie 3.4

=== "Python"

    ```python
    with open("anagram.txt") as file:
        binary_list = file.read().split()

    result1 = 0
    max_distinct_sum = 0
    for binary in binary_list:
        decimal = int(binary, 2)
        decimal_str = str(decimal)
        if decimal_str.count("0") == 0:
            result1 += 1

        distinct_sum = sum(map(int, set(decimal_str)))
        if distinct_sum > max_distinct_sum:
            max_distinct_sum = distinct_sum

    print("Zadanie 3.4")
    print("a)", result1)

    for binary in binary_list:
        decimal = int(binary, 2)
        decimal_str = str(decimal)

        distinct_sum = sum(map(int, set(decimal_str)))
        if distinct_sum == max_distinct_sum:
            print("b)", decimal)
            break
    ```

## Zadanie 6

[:material-microsoft-excel: Rozwiązanie - Excel](../../../assets/matura/2023-czerwiec-cke/zad6.xlsx)

## Zadanie 7

[:material-microsoft-access: Rozwiązanie - Access](../../../assets/matura/2023-czerwiec-cke/zad7.accdb)