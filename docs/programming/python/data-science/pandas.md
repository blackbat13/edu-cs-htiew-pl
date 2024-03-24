# Biblioteka Pandas

Jednym z pierwszych kroków, które musimy wykonać, zanim przejdziemy do analizowania ciekawych danych, jest wczytanie tychże danych do programu. W tym pomoże nam biblioteka **pandas**, która diametralnie ułatwia pracę z danymi tabelarycznymi w Pythonie.

Pandas to biblioteka przeznaczona do analizy i przetwarzania danych. Jej głównymi strukturami danych są jednowymiarowe serie danych (ang. *Series*) oraz wielowymiarowe ramki danych (ang. *DataFrame*). Ramki danych przypominają trochę tabele w programie Excel – mają wiersze i kolumny.

## Instalacja

Aby korzystać z biblioteki *pandas*, najpierw należy ją zainstalować. Możemy to zrobić w niemalże trywialny sposób, wpisując w terminalu poniższe polecenie:

```bash
pip install pandas
```

## Pierwsze kroki z pandas

Zacznijmy od prostego przykładu. Załóżmy, że mamy pewne dane o sprzedaży owoców:

```python
import pandas as pd

fruits = {
    'Owoce': ['Jabłka', 'Banany', 'Wiśnie'],
    'Ilość': [10, 5, 8],
    'Cena': [3.5, 1.2, 2.5]
}

df = pd.DataFrame(fruits)
print(df)
```

Po wydrukowaniu ramki danych zobaczymy poniższą tabelkę:

```
   Owoce  Ilość  Cena
0  Jabłka    10   3.5
1  Banany     5   1.2
2  Wiśnie     8   2.5
```

## Jak korzystać z danych?

Pandas oferuje wiele narzędzi do pracy z danymi. Poniżej kilka przykładów.

### Wybór kolumny

```python
print(df['Owoce'])
```

### Filtrowanie danych

```python
print(df[df['Ilość'] > 7])
```

### Podstawowe statystyki

```python
print(df.describe())
```

## Dlaczego warto używać pandas?

1. **Elastyczność** - przetwarzaj dane tak, jak potrzebujesz.
2. **Wydajność** - obsługuje duże zestawy danych.
3. **Integracja** - łatwo łączy się z innymi bibliotekami Pythona.
4. **Wsparcie dla różnych formatów** - czytaj i zapisuj w formatach CSV, Excel, SQL i wielu innych.

## Podsumowanie

Pandas to potężne narzędzie do przetwarzania danych w Pythonie. Dzięki intuicyjnym strukturom danych i wielu funkcjom ułatwia analizę nawet skomplikowanych zestawów informacji. A to tylko wierzchołek góry lodowej! Zachęcamy do dalszej eksploracji tej fantastycznej biblioteki.
