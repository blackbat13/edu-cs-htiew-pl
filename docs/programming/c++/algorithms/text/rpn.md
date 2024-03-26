---
description: Obliczanie wartości wyrażenia ONP
---

# ONP

## [Opis problemu](../../../../algorithms/text/rpn.md)


## Implementacja

```cpp linenums="1"
#include <iostream>
#include <stack>

using namespace std;

double compute(double a, double b, char op) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}

double calculateRPN(string rpn) {
    stack<double> rpnStack;
    double a, b, result;

    for (int i = 0; i < rpn.length(); i++) {
        if (isdigit(rpn[i])) {
            rpnStack.push(rpn[i] - '0');
        } else {
            b = rpnStack.top();
            rpnStack.pop();

            a = rpnStack.top();
            rpnStack.pop();
            
            result = compute(a, b, rpn[i])
            rpnStack.push(result);
        }
    }

    return rpnStack.top();
}

int main() {
    string rpn = "27+3/13-4*+2/";
    
    double result = calculateRpn(rpn);

    cout << result << endl;

    return 0;
}
```


### Opis implementacji

Funkcja `calculateRPN` (**linia 19**) oblicza wartość wyrażenia ONP podanego w formie ciągu znaków. Zakładamy, że podane wyrażenie jest poprawne, a każdy znak reprezentuje jednocyfrową liczbę lub operację. 

Na początku tworzymy stos do przechowywania wyników kolejnych obliczeń (**linia 20**), oraz pomocnicze zmienne do przechowywania bieżących wartości ze stosu oraz wyniku pośrednich operacji (**linia 21**). 

Następnie przechodzimy pętlą po każdym znaku wyrażenia ONP (**linia 23**). Jeżeli przetwarzany aktualnie znak jest cyfrą (**linia 24**), to dodajemy jego liczbową wartość na stos (**linia 25**). W przeciwnym przypadku (**linia 26**) mamy do czynienia z operatorem. Pobieramy więc dwie ostatnie wartości ze stosu, zarazem je z niego usuwając (**linie 27-31**). Następnie korzystamy z pomocniczej funkcji `compute` by obliczyć wynik operacji (**linia 33**), który następnie wrzucamy na stos (**linia 34**).

Po przetworzeniu wszystkich znaków z wyrażenia ONP na stosie powinna zostać dokładnie jedna wartość, którą zwracamy jako wynik funkcji (**linia 38**).
