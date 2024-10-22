# Sortowanie koktajlowe

## [:link: Opis problemu](../../../../algorithms/sorting/cocktail-shaker-sort.md)

## Implementacja

```python linenums="1"
def cocktail_shaker_sort(array: list):
    for i in range(len(array) // 2 + 1):
        for j in range(i, len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
        
        for j in range(len(array) - 1 - i, i, -1):
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

cocktail_shaker_sort(array)
    
print(array)
```

### Opis implementacji

Funkcja `cocktail_shaker_sort` przyjmuje jako argument listę `array`, która ma być posortowana.

W pierwszej pętli `for` iterujemy przez połowę długości listy `array` podzielonej przez 2 (dzielimy przez 2, ponieważ w każdej iteracji sortowania oba końce listy są już posortowane, więc możemy je pomijać).

Wewnętrzna pętla `for` rozpoczyna się od `i` i iteruje do `len(array) - i - 1`. Porównuje elementy `array[j]` i `array[j + 1]` i jeśli `array[j]` jest większe od `array[j + 1]`, zamienia je miejscami przy użyciu operacji `array[j], array[j + 1] = array[j + 1], array[j]`. W ten sposób większe elementy są przesuwane na koniec listy.

Po zakończeniu pierwszej wewnętrznej pętli, największy element znajduje się na ostatniej pozycji listy.

Następnie mamy drugą wewnętrzną pętlę `for`, która iteruje od `len(array) - 1 - i` (czyli od ostatniego elementu minus `i`) do `i`. W tej pętli porównujemy sąsiednie elementy `array[j]` i `array[j - 1]` i jeśli `array[j]` jest mniejsze od `array[j - 1]`, zamieniamy je miejscami.

Po zakończeniu drugiej wewnętrznej pętli, najmniejszy element znajduje się na pierwszej pozycji listy.

Po zakończeniu sortowania, posortowana lista jest przechowywana w zmiennej `array`.

W części głównej programu przygotowujemy listę do posortowania, a następnie wywołujemy funkcję `cocktail_shaker_sort`, jako parametr przekazując utworzoną listę. Na końcu wyświetlamy posortowaną listę za pomocą funkcji `print`.