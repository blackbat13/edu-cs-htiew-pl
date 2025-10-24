# Mapa

Za pomocą mapy możemy tworzyć pary typu (klucz, wartość) i zapamiętywać je w zbiorze, w którym klucze są unikalne.
W innych językach programowania ten typ struktury nazywany jest często **słownikiem** (ang. _dictionary_).

## Biblioteka

Mapa znajduje się w bibliotece `map`.

```cpp
#include <map>
```

## Implementacja - przykłady

### Utworzenie pustej mapy

Tworzymy pustą mapę, w której klucze będą tekstami, a wartości będą liczbami całkowitymi.

```cpp
map<string, int> dictionary;
```

### Dodajemy element do mapy

Aby dodać nową parę (klucz, wartość) do mapy wystarczy przypisać wartość do klucza. W ten sam sposób możemy także zmienić dotychczasową wartość, jeżeli klucz już istniał w mapie.

```cpp
dictionary["apple"] = 1;
```

### Odczytanie elementu z mapy

Aby odczytać wartość przypisaną do klucza używamy notacji nawiasów kwadratowych.

```cpp
cout << dictionary["apple"] << endl; // 1
```

### Odczytanie nieistniejącego klucza

Jeżeli spróbujemy odczytać klucz, którego nie ma w mapie, to zostanie on automatycznie dodany, a przypisana do niego wartość będzie wartością domyślną dla typu wartości. Np. dla typu int wartość domyślna to 0.

```cpp
cout << dictionary["pear"] << endl; // 0
```

## Dokumentacja

[:link: Map Reference](https://www.cplusplus.com/reference/map/map/)