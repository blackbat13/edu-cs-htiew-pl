# Wyznacznik macierzy 3x3

## [:link: Opis problemu](../../../../algorithms/matrix/det3.md)

## Implementacja

```python linenums="1"
def det3(matrix) -> int:
    return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[2][0] * \
           matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * \
           matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1]

matrix = [
       [1, 2, 3], 
       [4, 5, 6], 
       [7, 8, 9]]
       
result = det3(matrix)

print(result)
```

### Opis implementacji

Funkcja `det3` (**linia 1**) wylicza wyznacznik macierzy $3\times3$ przekazanej jako parametr funkcji. Wewnątrz funkcji mamy tylko jedną operację zwracającą wyznacznik macierzy obliczony zgodnie ze wzorem.

W części głównej najpierw przygotowujemy macierz (**linia 7**), następnie obliczamy jej wyznacznik (**linia 9**) i wypisujemy go na ekranie (**linia 11**).
