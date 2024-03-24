# Pyplot

`matplotlib.pyplot` jest jednym z najpopularniejszych narzędzi do tworzenia wykresów i dzięki niemu przetwarzanie danych staje się nie tylko proste, ale również atrakcyjne wizualnie. Zapraszam do krótkiego wprowadzenia!

`matplotlib` to biblioteka do tworzenia wykresów w Pythonie. `pyplot` to jej moduł, który oferuje funkcje pozwalające na łatwe rysowanie różnego rodzaju wykresów w stylu MATLAB.

## Instalacja

Aby korzystać z `matplotlib`, najpierw musimy ją zainstalować:

```bash
pip install matplotlib
```

## Pierwszy wykres

Stworzenie prostego wykresu liniowego jest naprawdę proste:

```python
import matplotlib.pyplot as plt

x = [1, 2, 3, 4, 5]
y = [1, 4, 9, 16, 25]

plt.plot(x, y)
plt.title("Wykres liniowy")
plt.xlabel("Oś X")
plt.ylabel("Oś Y")
plt.show()
```

## Inne typy wykresów

Oprócz wykresu liniowego `matplotlib.pyplot` oferuje wiele innych rodzajów wykresów. Kilka przedstawiamy poniżej.

### Wykres punktowy

```python
plt.scatter(x, y)
```

### Wykres słupkowy:

```python
plt.bar(x, y)
```

### Histogram:

```python
plt.hist(y)
```

## Dostosowywanie wykresów

`matplotlib` pozwala na wiele modyfikacji wyglądu wykresu:

- Kolory i style linii:
  ```python
  plt.plot(x, y, color='red', linestyle='dashed')
  ```

- Dodawanie legendy:
  ```python
  plt.plot(x, y, label='Legenda')
  plt.legend()
  ```

- Zmiana zakresu osi:
  ```python
  plt.xlim(0, 10)
  plt.ylim(0, 30)
  ```

## Dlaczego warto używać `matplotlib.pyplot`?

1. **Wszechstronność** - Tworzenie różnych typów wykresów od prostych po skomplikowane.
2. **Personalizacja** - Możliwość dostosowywania wyglądu wykresów do własnych potrzeb.
3. **Integracja** - Doskonała integracja z innymi bibliotekami Pythona, takimi jak pandas.
4. **Popularność** - Wieloletnie wsparcie społeczności i mnóstwo dostępnych zasobów.

## Podsumowanie

`matplotlib.pyplot` to kluczowe narzędzie dla każdego, kto chce wizualizować dane w Pythonie. Dzięki niemu możesz prezentować informacje w przystępny i atrakcyjny sposób. Powyższy przewodnik przedstawia jedynie podstawy - możliwości są naprawdę ogromne. Zachęcam do eksperymentowania i odkrywania wszystkich funkcji, jakie oferuje ta biblioteka!
