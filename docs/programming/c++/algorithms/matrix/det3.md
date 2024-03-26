# Wyznacznik macierzy 3x3

## [Opis problemu](../../../../algorithms/matrix/det3.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int det3(int matrix[3][3]) {
    return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[2][0] * \
           matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * \
           matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9}};
       
    int result = det3(matrix);

    cout << result << endl;
    
    return 0;
}
```


### Opis implementacji

Funkcja `det3` (**linia 5**) wylicza wyznacznik macierzy $3\times3$ przekazanej jako parametr funkcji. Wewnątrz funkcji mamy tylko jedną operację zwracającą wyznacznik macierzy obliczony zgodnie ze wzorem.

W części głównej najpierw przygotowujemy macierz (**linia 12**), następnie obliczamy jej wyznacznik (**linia 16**) i wypisujemy go na ekranie (**linia 18**). Na koniec kończymy działanie programu (**linia 20**).
