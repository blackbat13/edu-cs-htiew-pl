# Najdłuższy spójny podciąg rosnący

## [Opis problemu](../../../../algorithms/searching/longest-growing-substring.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int longestGrowingSubstringLength(int n, int tab[]) {
    int mx = 1;
    int length = 1;
    
    for (int i = 1; i < n; i++) {
        if (tab[i] > tab[i-1]) {
            length += 1;
            if (length > mx) {
                mx = length;
            }
        } else {
            length = 1;
        }
    }
    
    return mx;
}

int main() {
    int tab[10] = {4, 9, 7, 2, 4, 7, 9, 3, 8, 6};
    int n = 10;

    int result = longestGrowingSubstringLength(n, tab);
    
    cout << result << endl;
    
    return 0;
}
```


### Opis implementacji

Funkcja `longestGrowingSubstringLength` przyjmuje dwa argumenty: liczbę `n` reprezentującą liczbę elementów w tablicy i tablicę `tab` zawierającą te elementy. Funkcja zwraca długość najdłuższego rosnącego podciągu.

Schemat działania funkcji jest następujący:

1. Zainicjalizuj długość `length` aktualnie analizowanego podciągu oraz najdłuższego dotychczas znalezionego podciągu `mx` na $1$.
2. Przeszukaj tablicę od drugiego elementu do końca.
3. Jeżeli bieżący element `tab[i]` jest większy od poprzedniego `tab[i-1]`, to zwiększ długość `length` aktualnie analizowanego podciągu o $1$ i jeżeli ta długość jest większa od dotychczas najdłuższego podciągu, zaktualizuj `mx`.
4. Jeżeli bieżący element `tab[i]` nie jest większy od poprzedniego `tab[i-1]`, to zresetuj długość `length` aktualnie analizowanego podciągu do $1$.
5. Po przejściu przez całą tablicę zwróć `mx`, czyli długość najdłuższego rosnącego podciągu.

Funkcja `main` definiuje tablicę `tab` z $10$ elementami, przekazuje tę tablicę do funkcji `longestGrowingSubstringLength` w celu znalezienia długości najdłuższego rosnącego podciągu, a następnie wyświetla ten wynik na ekranie.
