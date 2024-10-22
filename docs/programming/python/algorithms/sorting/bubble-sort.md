# Sortowanie bąbelkowe

## [:link: Opis problemu](../../../../algorithms/sorting/bubble-sort.md)

## Implementacja

```python linenums="1"
def bubble_sort(array: list):
	sorted = False
	i = 0
	while not sorted:
		sorted = True
		for j in range(len(array) - 1, i, -1):
			if array[j - 1] > array[j]:
				array[j], array[j - 1] = array[j-1], array[j]
				sorted = False
		i += 1

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

bubble_sort(array)

print(array)
```

### Opis implementacji

Funkcja `bubble_sort` przyjmuje jako argument listę `array`, która ma być posortowana.

Na początku funkcji ustawiamy zmienną `sorted` na `False`, co oznacza, że lista nie jest jeszcze posortowana. Ustawiamy także zmienną `i` na $0$, która będzie reprezentować indeks granicy posortowanej części listy.

Następnie rozpoczynamy pętlę `while`, która będzie się wykonywać, dopóki lista nie zostanie posortowana. Wewnątrz pętli ustawiamy zmienną `sorted` na `True`, zakładając, że lista jest posortowana.

Następnie mamy pętlę `for`, która iteruje w odwrotnej kolejności od `len(array) - 1` do `i` (indeks granicy posortowanej części). Porównujemy elementy `array[j - 1]` i `array[j]` i `jeśli array[j - 1]` jest większe od `array[j]`, zamieniamy je miejscami przy użyciu operacji `array[j], array[j - 1] = array[j-1], array[j]`. W ten sposób większe elementy są przesuwane na koniec listy.
Jeśli w trakcie iteracji wewnętrznej pętli `for` nastąpiła zamiana elementów, ustawiamy zmienną `sorted` na `False`, co oznacza, że lista nie jest jeszcze posortowana. Po zakończeniu iteracji wewnętrznej pętli `for`, największy element znajduje się na ostatniej pozycji granicy posortowanej części.

Po wyjściu z wewnętrznej pętli `for` zwiększamy wartość `i` o $1$, aby przesunąć granicę posortowanej części.

Proces sortowania bąbelkowego jest powtarzany, aż do momentu, gdy żadna zamiana elementów nie jest już potrzebna. Oznacza to, że lista jest już posortowana. Po zakończeniu sortowania, posortowana lista jest przechowywana w zmiennej `array`.

W części głównej programu przygotowujemy listę do posortowania, a następnie wywołujemy funkcję `bubble_sort`, jako parametr przekazując utworzoną listę. Na końcu wyświetlamy posortowaną listę za pomocą funkcji `print`.