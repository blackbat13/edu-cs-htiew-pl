# Schemat Hornera

## [:link: Opis problemu](../../../../algorithms/numerical-methods/horner.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

double hornerPolynomial(double coef[], double x, int n) {
    double result = 0;
    for(int i = n; i >= 0; i--) {
        result *= x;
        result += coef[i];
    }
    
    return result;
}

void printPolynomial(double coef[], int n) {
    cout << "f(x) = " << coef[0];
    for(int i = 1; i <= n; i++) {
        cout << " + " << coef[i] << "x^" << i; 
    }
    
    cout << endl;
}

int main() {
    double coef[3] = {1, 2, 3};
    double x = 2;
    int n = 2;
    double result;
    
    printPolynomial(coef, n);

    result = hornerPolynomial(coef, x, n);

    cout << "f(" << x << ") = " << result << endl;
    
    return 0;
}
```

### Opis implementacji

Zacznijmy od funkcji pomocniczej `printPolynomial` (**linia 15**), której celem jest wyświetlenie wielomianu w czytelnej formie na ekranie. Nie jest ona niezbędną częścią algorytmu, ale może być pomocna przy weryfikacji poprawności wyniku. Funkcja przyjmuje dwa parametry: tablicę współczynników wielomianu `coef`, oraz stopień wielomianu `n`. W tablicy znajduje się dokładnie $n+1$ liczb. Współczynniki są zapisane w kolejności od najmniejszej potęgi ($0$) do największej ($n$).

Na początku funkcji wypisujemy pierwszy współczynnik (**linia 16**). Następnie przechodzimy pętlą przez kolejne elementy tablicy (**linia 17**), wypisując współczynnik przy $i$-tej potędze przemnożony przez $x$ podniesione do potęgi $i$.  

Przejdźmy teraz do właściwej implementacji algorytmu obliczania wartości wielomianu za pomocą schematu Hornera, czyli do funkcji `hornerPolynomial` (**linia 5**). Funkcja ta przyjmuje podobne parametry jak pomocnicza funkcja `printPolynomial`, ale ponadto przyjmuje także wartość $x$, którą mamy przyjąć podczas obliczeń. Współczynniki i stopień wielomianu podane są w takiej samej formie jak wcześniej.

Na początku tworzymy zmienną `result`, w której będziemy zapisywać wyniki obliczeń, i przypisujemy jej wartość $0$ (**linia 6**). Następnie przechodzimy pętlą przez kolejne współczynniki wielomianu, poczynając od współczynnika przy najwyższej potędze (**linia 7**). Zauważmy, że korzystamy tutaj z pętli malejącej. W pętli wykonujemy dwie operacje: przemnażamy wynik dotychczasowych obliczeń przez wartość `x` (**linia 8**), a następnie dodajemy do wyniku wartość kolejnego współczynnika (**linia 9**). Po przejściu przez wszystkie współczynniki wystarczy zwrócić wynik obliczeń (**linia 12**).

W części głównej definiujemy wartości parametrów naszych obliczeń (**linie 25-27**), wypisujemy wielomian w czytelnej formie korzystając z pomocniczej funkcji `printPolynomial` (**linia 30**), obliczamy wartość wielomianu za pomocą funkcji `hornerPolynomial` (**linia 32**) i wypisujemy wynik na ekranie (**linia 34**). Na koniec kończymy działanie programu (**linia 36**).
