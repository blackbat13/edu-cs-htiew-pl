# Operacje arytmetyczne

W języku C++, tak jak i w wielu innych językach programowania, mamy pewien zestaw operatorów arytmetycznych. Przyjrzyjmy się im.

## Podstawowe

```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 2;
    
    int suma = a + b; // 7
    int roznica = a - b; // 3
    int iloczyn = a * b; // 10
    int iloraz = a / b; // 2

    return 0;
}
```

!!! info
	 Wynik dzielenia liczb całkowitych będzie także liczbą całkowitą, tzn. wartością zaokrągloną w dół.

### Dzielenie rzeczywiste

W celu uzyskania rzeczywistego wyniku dzielenia dwóch zmiennych typu całkowitego, należy użyć rzutowania na typ rzeczywisty. Przynajmniej jedna z wartości w dzieleniu musi być typu rzeczywistego. Mogą też być obie.

```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 2;
    
    double iloraz = (double)a / (double)b; // 2.5

    return 0;
}
```

Wynik dzielenia liczb rzeczywistych jest także liczbą rzeczywistą, co pokazuje poniższy przykład.

```cpp
#include <iostream>

using namespace std;

int main() {
    double a = 5;
    double b = 2;
    
    double iloraz = a / b; // 2.5

    return 0;
}
```

### Reszta z dzielenia

W celu uzyskania reszty z dzielenia dwóch zmiennych typu całkowitego należy użyć operatora modulo (`%`).

```cpp
#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 2;
    
    int reszta = a % b; // 1

    return 0;
}
```
