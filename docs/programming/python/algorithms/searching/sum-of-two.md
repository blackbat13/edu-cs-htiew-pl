# Suma dwóch liczb

## [Opis problemu](../../../../algorithms/searching/sum-of-two.md)


## Rozwiązanie naiwne

```python linenums="1"
def sum_of_two(tab: list, k: int):
    for i, num1 in enumerate(tab):
        for _, num2 in enumerate(tab, i + 1):
            if num1 + num2 == k:
                print(num1, num2)
                return
                
    print("Not found")
    

tab = [1, 2, 4, 6, 8, 9, 10, 12, 13, 15]
k = 18

sum_of_two(tab, k)
```


Funkcja `sum_of_two` przyjmuje jako argumenty listę `tab` (lista liczb) oraz liczbę całkowitą `k` (szukana suma).

Początkowo mamy dwie zagnieżdżone pętle `for`. Pierwsza pętla iteruje przez wszystkie indeksy i elementy listy `tab`. Wewnątrz pierwszej pętli mamy drugą pętlę `for`, która iteruje przez kolejne elementy od indeksu `i+1`. Dzięki temu unikamy porównywania tej samej liczby ze samą sobą oraz dublowania porównań.

W każdej iteracji wewnętrznej pętli sprawdzamy, czy suma dwóch elementów tablicy (`num1` i `num2`) jest równa szukanej sumie `k`. Jeśli tak, wypisujemy te dwie liczby i kończymy działanie funkcji za pomocą operacji `return`.

Jeśli nie znaleziono pary liczb o sumie `k` w całej liście, wypisujemy $-1$.

W przykładzie podane są konkretne wartości dla `tab` i `k`. Funkcja `sum_of_two` jest wywoływana z tymi wartościami.

W wyniku wykonania tego kodu, zostaną wypisane liczby $6$ i $12$, ponieważ ich suma wynosi $18$.

## Rozwiązanie optymalne

```python linenums="1"
def sum_of_two(tab: list, k: int):
    left = 0
    right = len(tab) - 1
    
    while left < right and tab[left] + tab[right] != k:
        if tab[left] + tab[right] < k:
            left += 1
        else:
            right -= 1
            
    if left < right:
        print(tab[left], tab[right])
    else:
        print("Not found")
     
           
tab = [1, 2, 4, 6, 8, 9, 10, 12, 13, 15]
k = 18

sum_of_two(tab, k)
```


Funkcja `sum_of_two` przyjmuje jako argumenty listę `tab` (lista liczb) oraz liczbę całkowitą `k` (szukana suma).

Ustalamy początkowe wartości dla lewego wskaźnika (`left`) na $0$ i prawego wskaźnika (`right`) na długość listy minus 1.

W pętli `while` sprawdzamy warunek: `left < right` oraz `tab[left] + tab[right] != k`. W każdej iteracji pętli sprawdzamy, czy suma `tab[left]` i `tab[right]` jest mniejsza od `k`. Jeśli tak, inkrementujemy lewy wskaźnik (`left += 1`), aby przesunąć się w prawo i sprawdzić większe wartości. Jeśli suma jest większa od `k`, dekrementujemy prawy wskaźnik (`right -= 1`), aby przesunąć się w lewo i sprawdzić mniejsze wartości.

Po wyjściu z pętli, jeśli znaleziono parę liczb o sumie `k` (`left < right`), wypisujemy te dwie liczby. Jeśli nie znaleziono takiej pary liczb w całej liście, wypisujemy $-1$.

W przykładzie podane są konkretne wartości dla `tab` i `k`. Funkcja `sum_of_two` jest wywoływana z tymi wartościami.

W wyniku wykonania tego kodu, zostaną wypisane liczby $6$ i $12$, ponieważ ich suma wynosi $18$.
