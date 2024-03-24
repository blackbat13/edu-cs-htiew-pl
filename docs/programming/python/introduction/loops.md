# Pętle

Jak i w innych językach programowania ciężko jest napisać bardziej zaawansowany kod nie korzystając z pętli. W Pythonie mamy standardowo dwa rodzaje pętli: pętlę iteracyjną oraz pętlę warunkową.

## Pętla iteracyjna

Pętla iteracyjna w języku Python jest tak naprawdę pętlą przechodzącą przez pewien zbiór elementów, tzn. pętlą typu **for in** czy też **for each**.  Może to być lista, zbiór i inne. Wykorzystując funkcję `range` możemy utworzyć zakres kolejnych wartości i przez niego przejść. Należy zwrócić uwagę na to, że funkcja `range` symuluje w pewnym sensie przedział prawostronnie otwarty.

Poniżej kilka przykładów konstrukcji klasycznej pętli iteracyjnej w języku Python.

### Wypisanie liczb od **0** do **9** **włącznie**:

```python
for i in range(10):
    print(i)
```

### Wypisanie liczb od **1** do **9** **włącznie**:

```python
for i in range(1, 10):
    print(i)
```

### Wypisanie co drugiej wartości od **0** do **8** **włącznie**:

```python
for i in range(0, 10, 2):
    print(i)
```

### Wypisanie liczb od **10** do **1** **włącznie**:

```python
for i in range(10, 0, -1):
    print(i)
```

## Pętla warunkowa

Pętla warunkowa w języku Python wygląda podobnie jak w wielu innych językach. Poniżej prosty przykład.

### Wypisanie liczb od **0** do **9** **włącznie**:

```python
i = 0
while i < 10:
    print(i)
    i += 1
```

Warto zwrócić uwagę na zastosowanie operatora `+=` w linijce 4. Jest to celowe, ponieważ w języku Python 3 nie ma operatora `++`.
