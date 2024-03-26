# Python - rozwiązania

## Wczytanie danych

Zacznijmy od wczytania danych z pliku. Liczby są zapisane osobno w każdej linii, więc ich wczytanie jest proste. Wczytane liczby binarne w postaci tekstowej zapiszemy w liście nazwanej `binary_numbers_list`.

```python
def read_data():
    with open("liczby.txt") as data_file:
        binary_numbers_list = data_file.read().split("\n")
    
    return binary_numbers_list
```

## Zadanie 1

Aby sprawdzić, czy liczba binarna jest parzysta, wystarczy spojrzeć na jej **ostatnią** (najmniej znaczącą) cyfrę.

```python
def count_even(binary_numbers_list):
    count = 0  # Licznik liczb parzystych
    for binary in binary_numbers_list:
        if binary[-1] == "0":  # Jeżeli ostatni znak liczby binarnej to 0
            count += 1  # zwiększamy licznik liczb parzystych
    
    return count
```

## Zadanie 2

Aby sprawdzić, czy liczba binarna jest podzielna przez $4$ wystarczy sprawdzić jej **dwie ostatnie** (najmniej znaczące) cyfry. Jeżeli są równe $0$, to liczba jest podzielna przez $4$.

```python
def count_divisible_by_4(binary_numbers_list):
    count = 0
    for binary in binary_numbers_list:
        if binary[-1] == "0" and binary[-2] == "0":
            count += 1

    return count
```

## Zadanie 3

Zamieniamy liczbę binarną na system dziesiętny i sprawdzamy podzielność przez 10 za pomocą operatora modulo (reszty z dzielenia).

=== "Rozwiązanie 1"
    ```python
    def binary_to_decimal(binary):  # Funkcja konwertująca liczbę binarną reprezentowaną jako tekst na liczbę naturalną w systemie dziesiętnym
        decimal = 0  # Wartość w systemie 10
        power = 1  # Potęga 2
        # Idziemy pętlą od końca
        for i in range(len(binary) - 1, -1, -1):
            decimal += int(binary[i]) * power  # Przemnażamy cyfrę przez potęgę dwójki
            power *= 2  # Zwiększamy potęgę dwójki
        
        return decimal

    def count_divisible_by_10(binary_numbers_list):
        count = 0
        for binary in binary_numbers_list:
            decimal = binary_to_decimal(binary)
            if decimal % 10 == 0:
                count += 1

        return count
    ```

=== "Rozwiązanie 2"

    ```python
    def count_divisible_by_10(binary_numbers_list):
        count = 0
        for binary in binary_numbers_list:
            decimal = int(binary, 2)  # Konwertujemy tekst na liczbę dziesiętną za pomocą funkcji int. Jej drugi parametr to podstawa systemu, z którego dokonujemy konwersji.
            if decimal % 10 == 0:
                count += 1
        
        return count
    ```

## Zadanie 4

Liczba binarna jest potęgą dwójki, jeżeli w jej zapisie występuje dokładnie jedna jedynka.
 
```python
def count_power_of_2(binary_numbers_list):
    count = 0
    for binary in binary_numbers:
        digit_counter = dict()  # Słownik do zliczania cyfr 0 i 1
        digit_counter["0"] = 0  # Inicjalizujemy liczniki zer i jedynek
        digit_counter["1"] = 0
        for digit in binary:  # Dla każdej cyfry w zapisie liczby binarnej
            digit_counter[digit] += 1  # Zwiększamy licznik dla danej cyfry

        if digit_counter["1"] == 1:
            count += 1

    return count
```

## Zadanie 5

```python
def count_more_zeroes(binary_numbers_list):
    count = 0
    for binary in binary_numbers_list:
        digit_counter = dict()  # Słownik do zliczania cyfr 0 i 1
        digit_counter["0"] = 0  # Inicjalizujemy liczniki zer i jedynek
        digit_counter["1"] = 0
        for digit in binary:  # Dla każdej cyfry w zapisie liczby binarnej
            digit_counter[digit] += 1  # Zwiększamy licznik dla danej cyfry

        if digit_counter["0"] > digit_counter["1"]:
            count += 1

    return count
```

## Zadanie 6

```python
def count_more_ones(binary_numbers_list):
    count = 0
    for binary in binary_numbers_list:
        digit_counter = dict()  # Słownik do zliczania cyfr 0 i 1
        digit_counter["0"] = 0  # Inicjalizujemy liczniki zer i jedynek
        digit_counter["1"] = 0
        for digit in binary:  # Dla każdej cyfry w zapisie liczby binarnej
            digit_counter[digit] += 1  # Zwiększamy licznik dla danej cyfry

        if digit_counter["1"] > digit_counter["0"]:
            count += 1

    return count
```

## Zadanie 7

```python
def count_equal_zeroes_and_ones(binary_numbers_list):
    count = 0
    for binary in binary_numbers_list:
        digit_counter = dict()  # Słownik do zliczania cyfr 0 i 1
        digit_counter["0"] = 0  # Inicjalizujemy liczniki zer i jedynek
        digit_counter["1"] = 0
        for digit in binary:  # Dla każdej cyfry w zapisie liczby binarnej
            digit_counter[digit] += 1  # Zwiększamy licznik dla danej cyfry

        if digit_counter["0"] == digit_counter["1"]:
            count += 1

    return count
```

## Zadanie 8

```python
def find_min_max(binary_numbers_list):
    min_dec = 10000000000000
    min_bin = ""
    max_dec = 0
    max_bin = ""
    for binary in binary_numbers_list:
        decimal = int(binary, 2)

        if decimal < min_dec:
            min_dec = decimal
            min_bin = binary

        if decimal > max_dec:
            max_dec = decimal
            max_bin = binary

    return min_bin, max_bin
```

## Zadanie 9

=== "Rozwiązanie 1"

    ```python
    def count_unique(binary_numbers_list):
        dict_counter = dict()
        for binary in binary_numbers_list:
            dict_counter[binary] = 1  # Przypisujemy dowolną wartość, żeby dodać liczbę do słownika

        return len(dict_counter)  # Zwracamy długość słownika
    ```

=== "Rozwiązanie 2"

    ```python
    def count_unique(binary_numbers_list):
        set_counter = set()  # Zbiór unikalnych wartości
        for binary in binary_numbers_list:
            set_counter.add(binary)  # Dopisujemy liczbę binarną do zbioru

        return len(set_counter)  # Zwracamy długość zbioru
    ```

## Zadanie 10

```python
def count_4_rest(binary_numbers_list):
    dict_counter = dict()
    # Tworzymy słownik liczników, który inicjalizujemy różnymi końcówkami liczb binarnych, które odpowiadają kolejnym resztom z dzielenia przez 4
    dict_counter["00"] = 0
    dict_counter["01"] = 0
    dict_counter["10"] = 0
    dict_counter["11"] = 0
    for binary in binary_numbers_list:
        dict_counter[binary[-2] + binary[-1]] += 1  # Zwiększamy odpowiedni licznik

    return dict_counter["00"], dict_counter["01"], dict_counter["10"], dict_counter["11"]
```

## Zadanie 11

```python
def count_1_on_odds(binary_numbers_list):
    count = 0
    for binary in binary_numbers_list:
        correct = True
        for pos in range(len(binary)):
            if (pos + 1) % 2 == 0 and binary[pos] == "1":  # Sprawdzamy, czy jedynka pojawiła się na parzystej pozycji
                correct = False
                break

        if correct:
            count += 1

    return count
```

## Zadanie 12

```python
def find_longest_growing_substring(binary_numbers_list):
    max_length = 1  # Długość najdłuższego podciągu rosnącego
    max_first_index = 0  # Indeks pierwszej wartości w najdłuższym podciągu rosnącym

    current_length = 1  # Długość obecnie obliczanego ciągu
    current_first_index = 0  # Indeks pierwszej wartości w obecnie obliczanym ciągu

    for index in range(1, len(binary_numbers_list)):
        # Porównujemy obecną wartość z poprzednią
        if int(binary_numbers_list[index], 2) > int(binary_numbers_list[index - 1], 2):
            current_length += 1
        else:
            current_length = 1
            current_first_index = index

        if current_length > max_length:
            max_length = current_length
            max_first_index = current_first_index

    print("Długość:", max_length)
    print("Indeks pierwszego el.:", max_first_index)
    print("Indeks ostatniego el.:", max_first_index + max_length - 1)
    max_last_index = max_first_index + max_length
    print(binary_numbers_list[max_first_index:max_last_index])
```
