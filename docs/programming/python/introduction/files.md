# Pliki

Obsługa plików w języku Python jest stosunkowo prosta. Wystarczy otworzyć plik poleceniem `open`, wykonać na nim stosowne operacje, a następnie zamknąć plik metodą `close`.

```python
data_file = open("plik.txt")
# Operacje na pliku
data_file.close()
```

Plik możemy otwierać w różnych trybach, np. do odczytu (*read*), do zapisu (*write*), do dopisywania (*append*). Domyślnie plik otwierany jest w trybie do odczytu, możemy jednak to zmienić podając jako drugi parametr pierwszą literę pożądanego trybu.

```python
data_file = open("plik.txt", "w")  # Plik otwarty w trybie do zapisu
# Operacje na pliku
data_file.close()
```

Pamiętanie o zamknięciu pliku może być kłopotliwe, a jeżeli tego nie zrobimy, to plik może zostać uszkodzony. Na szczęście możemy skorzystać z czegoś, co nazywa się *kontekstem*. W Pythonie możemy pracować w danym kontekście za pomocą polecenia `with`. Spójrzmy na poniższy przykład, by lepiej zrozumieć działanie tego polecenia.

```python
with open("plik.txt") as data_file:
    # Operacje na pliku
```

Plik zostanie zamknięty wraz z wyjściem z zakresu polecenia `with`, więc nie musimy już zawracać sobie tym głowy.

## Czytanie danych z pliku

Odczytywanie danych z pliku tekstowego możemy zrealizować na kilka sposobów. Jednym z nich jest przeiterowanie po całym pliku za pomocą pętli `for`. W ten sposób możemy łatwo odczytać każdą linię z pliku. Należy jednak pamiętać, że odczytana linia będzie zawierała znak końca linii.

```python
with open("plik.txt") as data_file:
    for line in data_file:
        # Operacje na linii z pliku
```

Możemy także wczytać wszystkie linie z pliku w postaci listy za pomocą metody `readlines`. Tutaj także każdy element będzie zawierał znak końca linii.

```python
with open("plik.txt") as data_file:
    lines_list = data_file.readlines()
```

Innym rozwiązaniem jest wczytanie zawartości całego pliku w postaci jednego, długiego tekstu. W tym celu skorzystamy z metody `read`.

```python
with open("plik.txt") as data_file:
    file_content = data_file.read()
```

## Pisanie do pliku

Jednym ze sposobów na zapisanie danych do pliku jest skorzystanie z metody `write`. Należy jednak pamiętać, że ta metoda nie dodaje automatycznie znaku końca linii.

```python
with open("plik.txt", "w") as data_file:
    data_file.write("Hello World!")
```

Możemy także skorzystać z popularnej funkcji `print` przekazując do niej nasz plik w postaci dodatkowego parametru `file`.

```python
with open("plik.txt", "w") as data_file:
    print("Hello World!", file=data_file)
```
