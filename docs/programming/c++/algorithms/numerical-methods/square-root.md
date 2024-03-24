# Pierwiastek kwadratowy

## Opis problemu

{% content-ref url="../../../../algorithms/numerical-methods/square-root.md" %}
[square-root.md](../../../../algorithms/numerical-methods/square-root.md)
{% endcontent-ref %}

## Metoda Herona

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>
#include <cmath>

using namespace std;

double squareRoot(double n, double p) {
    double x1 = n / 2.0;
    double x2 = (x1 + (n / x1)) / 2.0;
    while (fabs(x2 - x1) > p) {
        x1 = (x2 + (n / x2)) / 2.0;
        swap(x1, x2);
    }

    return x2;
}

int main() {
    double n = 2.0;
    double p = 0.00001;

    double result = squareRoot(n, p);

    cout << result << endl;
    
    return 0;
}
```
{% endcode %}
