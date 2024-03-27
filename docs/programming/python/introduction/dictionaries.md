# Słowniki

Słowniki w języku Python są strukturą dynamiczną służącą do przechowywania par klucz-wartość.

## Inicjalizacja słownika

### Pusty słownik

W celu utworzenia pustego słownika wystarczy jako wartość zmiennej przypisać `dict()`.

```python
empty_dict = dict()
```

### Inicjalizacja danymi początkowymi

Gdy tworzymy słownik, możemy wypełnić go początkowymi wartościami. W tym celu używamy notacji nawiasów klamrowych oraz par `klucz: wartość`.

```python
letters_dict = {"a": 1, "b": 2, "c": 3}
```

### Generowanie słownika

Zawartość słownika możemy wygenerować *automatycznie* używając tzw. *dictionary comprehension*.

```python
numbers_dict = {i: i ** 2 for i in range(10)}
```

Możemy także użyć instrukcji warunkowej, by uwzględnić jedynie część elementów.

```python
even_dict = {i: i ** 2 for i in range(10) if i % 2 == 0}
```

## Podstawowe operacje

Jak to ze strukturami danych bywa, możemy nie tylko je tworzyć, ale także operować na ich zawartości, co krótko omówimy.

### Odczytanie wartości pod zadanym kluczem

W celu odczytania wartości zapisanej pod zadanym kluczem używamy notacji nawiasów kwadratowych.

```python
print(letters_dict["a"])
```

### Zmiana wartości pod zadanym indeksem

Poszczególne elementy słownika możemy traktować podobnie do zmiennych, możemy więc na nich przeprowadzać standardowe operacje, w szczególności modyfikację wartości.

```python
letters_dict["a"] *= 10
```

Należy jednak zwrócić uwagę na to, że wartość, na której operujemy w słowniku, musi najpierw istnieć. Jeśli nie, to wystąpi błąd. Istnienie wartości w słowniku możemy sprawdzić instrukcją warunkową.

```python
if "a" in letters_dict:
    letters_dict["a"] *= 10
```

### Wypisanie słownika

W celu wypisania całego słownika wystarczy skorzystać z wbudowanej funkcji `print`.

```python
print(letters_dict)
```

Jeżeli chcemy wypisać wyłącznie klucze, możemy skorzystać z metody `keys`.

```python
print(letters_dict.keys())
```

Podobnie możemy postąpić z wartościami.

```python
print(letters_dict.values())
```

### Pobranie długości słownika

Długość słownika, tzn. liczbę elementów (kluczy) zapisanych w słowniku, możemy pobrać za pomocą funkcji `len`, jako parametr podając słownik, którego długość chcemy poznać.

```python
length = len(letters_dict)
```

## Modyfikacja zawartości słownika

Ponieważ słownik jest strukturą dynamiczną, możemy do niego swobodnie dodawać nowe elementy, a także je usuwać.

### Dodanie elementu do słownika

W celu dodania nowego elementu do słownika, wystarczy przypisać wartość do nowego klucza korzystając z notacji nawiasów kwadratowych.

```python
letters_dict["z"] = 26
```

### Usunięcie klucza ze słownika

Aby usunąć wybrany klucz ze słownika (i przypisaną do niego wartość) możemy skorzystać z funkcji **del**.

```python
del letters_dict["z"]
```

## Przechodzenie po słowniku

### Iteracja po elementach słownika

W celu przejścia po kolejnych elementach słownika możemy skorzystać z pętli `for in`. W ten sposób przejdziemy po **kluczach** słownika. Jeżeli chcemy odczytać także wartości, możemy skorzystać z notacji nawiasów kwadratowych.

```python
for letter in lettes_dict:
    print(letter, letters_dict[letter])
```

Alternatywnie możemy także przejść bezpośrednio po parach klucz-wartość korzystając z metody `items` aby pobrać wszystkie elementy słownika w postaci krotek (tuple).

```python
for letter, value in letters_dict.items():
    print(letter, value)
```

## Słownik z wartością domyślną

Klasyczny słownik w Pythonie nie ma wartości domyślnej. Oznacza to, że jak spróbujemy się odwołać do klucza, który nie został do słownika dodany, to zakończy się to błędem.

```python
letters_dict = dict()

print(letters_dict["a"])
```

Możemy jednak skorzystać ze struktury `defaultdict` z biblioteki `collections`. Ta struktura przyjmuje w konstruktorze funkcję, która będzie wykonywana w przypadku, gdy odwołamy się do nieistniejącego w słowniku klucza. Jako funkcję możemy podać np. `int`. Wówczas domyślną wartością dla *nieistniejącego* klucza będzie zero. Podobnie byłoby np. z `list`, wówczas domyślną wartością będzie pusta lista.

```python
from collections import defaultdict

letters_dict = defaultdict(int)

print(letters_dict["a"])  # Wypisze 0
```
