# Sortowanie grzebieniowe

## [Opis problemu](../../../../algorithms/sorting/comb-sort.md)


## Implementacja

```python linenums="1"
def comb_sort(array: list):
    gap = len(array)
    shrink = 1.3
    sorted = False
    while not sorted:
        gap = int(gap / shrink)
        if gap <= 1:
            gap = 1
            sorted = True

        i = 0
        while i + gap < len(array):
            if array[i] > array[i + gap]:
                array[i], array[i + gap] = array[i + gap], array[i]
                sorted = False

            i += 1


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

comb_sort(array)
    
print(array)
```


### Opis implementacji

Funkcja `comb_sort` przyjmuje jako argument listę `array`, która ma być posortowana.

Wewnątrz funkcji ustalamy początkową wartość `gap` na rozmiar listy `array`.
Ustalamy także wartość `shrink` na $1.3$, co jest czynnikiem zmniejszającym odstęp `gap` w każdej iteracji. Jako ostatnią ustalamy zmienną `sorted` na `False`, co oznacza, że lista nie jest jeszcze posortowana.

Rozpoczynamy pętlę `while`, która będzie się wykonywać, dopóki lista nie zostanie posortowana. Wewnątrz pętli `while` obliczamy nową wartość `gap` przez podzielenie aktualnej wartości `gap` przez `shrink` i rzutujemy wynik na wartość całkowitą (używamy `int(gap / shrink)`). Jeśli `gap` jest mniejszy lub równy $1$, ustawiamy gap na $1$ i `sorted` na `True`, co oznacza, że lista jest już posortowana. Następnie ustalamy zmienną `i` na $0$, która będzie reprezentować indeks porównywanych elementów.

Rozpoczynamy wewnętrzną pętlę `while`, która będzie się wykonywać, dopóki `i + gap` jest mniejsze niż rozmiar listy `array`. Wewnątrz wewnętrznej pętli porównujemy elementy `array[i]` i `array[i + gap]`. Jeśli `array[i]` jest większe od `array[i + gap]`, zamieniamy je miejscami przy użyciu operacji przypisania wielokrotnego `array[i], array[i + gap] = array[i + gap], array[i]`. Jeśli w trakcie iteracji wewnętrznej pętli `while` nastąpiła zamiana elementów, ustawiamy `sorted` na `False`, co oznacza, że lista nie jest jeszcze posortowana. Na końcu wewnętrznej pętli zwiększamy wartość `i` o $1$, aby przejść do kolejnych porównań.

Po zakończeniu wewnętrznej pętli `while`, przechodzimy do następnej iteracji zewnętrznej pętli `while`.

Proces sortowania grzebieniowego jest powtarzany, aż do momentu, gdy `gap` osiągnie wartość $1$ i nie wystąpią już żadne zamiany elementów. Oznacza to, że lista jest już posortowana. Po zakończeniu sortowania, posortowana lista jest przechowywana w zmiennej `array`.

W części głównej programu przygotowujemy listę do posortowania, a następnie wywołujemy funkcję `comb_sort`, jako parametr przekazując utworzoną listę. Na końcu wyświetlamy posortowaną listę za pomocą funkcji `print`.
