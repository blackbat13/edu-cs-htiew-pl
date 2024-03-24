# Funkcje

W języku Python funkcje definiujemy zaczynając od słowa kluczowego `def`, po którym następuje nazwa funkcji, lista parametrów oddzielonych przecinkiem podanych w okrągłych nawiasach, a następnie dwukropek oznaczający początek bloku ciała funkcji.

## Przykład

```python
def suma(a, b):
    return a + b
```

## Sugestie typów

Tak jak i przy definicji zmiennych, tak samo przy tworzeniu funkcji możemy dodać sugestie typów, zarówno dla argumentów jak i zwracanej wartości.

### Przykład

```python
def suma(a: int, b: int) -> int:
    return a + b
```

## Procedury

W Pythonie nie odróżniamy procedur od funkcji, ale oczywiście możemy tworzyć funkcje, które nie zwracają wartości.

### Przykład

```python
def powitanie(imie: str):
    print(f"Witaj {imie}!")
```
