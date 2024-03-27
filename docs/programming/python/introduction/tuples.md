# Krotki

W języku Python krotka (ang. *tuple*) jest niezmienną (ang. *immutable*) strukturą danych. Oznacza to, że wartości raz utworzonej krotki nie możemy modyfikować. W swoim zachowaniu krotki przypominają poniekąd listy, ale z kilkoma różnicami. Najważniejszą różnicą jest to, że krotki nie posiadają metod `append()` ani `remove()`, co oznacza, że nie możemy ich modyfikować.

## Utworzenie krotki

Krotkę zapisujemy w nawiasach okrągłych, w których umieszczamy elementy oddzielone przecinkami. Każdy element może być dowolnego typu, np. liczba calkowita, zmiennoprzecinkowa, ciąg znaków, lista, krotka, itp.

```python
numbers = (2, 3, 5)
letters = ('a', 'b', 'c')
mixed = (2, 'b', 3.5)
```

## Odczytywanie elementów

Aby odczytać element z krotki, używamy indeksu, który określa pozycję elementu w krotce. Pierwszy element ma indeks 0, drugi 1 itd.

```python
numbers = (2, 3, 5)
print(numbers[0])  # wypisze 2
print(numbers[2])  # wypisze 5
```

Możemy też odwoływać się do elementów krotki od końca, używając indeksu `-1`. Element o indeksie `-1` jest ostatnim w krotce, element o indeksie `-2` jest przedostatnim itd.

```python
numbers = (2, 3, 5)
print(numbers[-1])  # wypisze 5
print(numbers[-2])  # wypisze 3
```

## Zmiana krotki

Krotki nie mogą być zmieniane. Jeśli chcemy zmienić elementy krotki, musimy ją generalnie przepisać na nowo. Oczywiście, jak chcemy zmienić wartość tylko jednego elementu, pozostałe możemy zachować przepisując je.

```python
numbers = (2, 3, 5)
numbers = (numbers[0], numbers[1], 7)
```

## Długość krotki

Aby dowiedzieć się ile elementów ma krotka, używamy funkcji `len()`.

```python
numbers = (2, 3, 5)
print(len(numbers))  # wypisze 3
```

## Krotki w krotkach

Krotki mogą być zagniezdzone w krotkach.

```python
outer = (1, 2)
inner = (3, 4)
nested = (outer, inner)
print(nested)  # wypisze ((1, 2), (3, 4))
```

## Nazwane krotki

Domyślnie wartości w krotkach indeksujemy od 0. Jeśli chcemy, aby wartości miały własne nazwy, możemy skorzystać ze struktury `namedtuple` z biblioteki `collections`. Na początek zaczynamy od utworzenia własnego typu nazwanej krotki.

```python
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])
```

Teraz możemy tworzyć własne *punkty*.

```python
point = Point(2, 6)
```

Możemy także je tworzyć podając argumenty po nazwie.

```python
point = Point(x = 2, y = 6)
```

Możemy także z łatwością odwoływać się do wartości w naszej krotce, podając po kropce nazwę wartości, którą chcemy odczytać.

```python
print(point.x)  # wypisze 2
print(point.y)  # wypisze 6
```
