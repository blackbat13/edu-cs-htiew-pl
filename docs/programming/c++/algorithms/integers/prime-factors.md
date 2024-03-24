# Rozkład na czynniki pierwsze

## Opis problemu

{% content-ref url="../../../../algorithms/integers/prime-factors.md" %}
[prime-factors.md](../../../../algorithms/integers/prime-factors.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

void distribute(int n) {
    int factor = 2;
    
    while(n > 1) {
        if(n % factor == 0) {
            cout << factor << " ";
            n /= factor;
        } else {
            factor++;
        }
    }
}

int main() {
    int n = 124;

    cout << "Prime factors of " << n << ": ";
    distribute(n);

    return 0;
}
```
{% endcode %}

### Opis implementacji

Funkcja `distribute` (**linia 5**) przyjmuje jeden parametr: liczbę naturalną do rozłożenia na czynniki pierwsze. Na początku tworzymy zmienną do przechowywania wartości kolejnych czynników (**linia 6**). Następnie wykonujemy działania w pętli tak długo, jak długo możemy jeszcze rozkładać $$n$$ na czynniki pierwsze (**linia 8**). Wewnątrz pętli sprawdzamy, czy $$n$$ jest podzielne przez obecnie sprawdzany czynnik (**linia 9**). Jeżeli tak, to wypisujemy czynnik na ekranie (**linia 10**) i dzielimy $$n$$ przez ten czynnik (**linia 11**). W przeciwnym przypadku (**linia 12**) przechodzimy do kolejnego czynnika, zwiększając jego wartość o jeden (**linia 13**).

W części głównej przygotowujemy dane wejściowe, czyli liczbę do rozłożenia na czynniki pierwsze (**linia 19**). Następnie wypisujemy stosowny komunikat (**linia 21**) oraz wywołujemy funkcję rozkładającą $$n$$ na czynniki pierwsze (**linia 22**). Na koniec kończymy działanie programu (**linia 24**).