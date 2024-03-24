# Konwersja pomiędzy systemami liczbowymi

## Opis problemu

{% content-ref url="../../../../algorithms/numeral-systems/README.md" %}
[Systemy liczbowe](../../../../algorithms/numeral-systems/README.md)
{% endcontent-ref %}

## Konwersja z dziesiętnego

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

string fromDec(int number, int newBase) {
    string converted = "";
    int remainder = 0;
    
    while (number > 0) {
        remainder = number % newBase;
        number = number / newBase;
        
        if (remainder > 9) {
            converted = (char)('A' + remainder - 10) + converted;
        } else {
            converted = (char)(remainder + '0') + converted;
        }
    }
    
    return converted;
}

int main() {
    int number = 241;
    int base = 16;

    string converted = fromDec(number, base);

    cout << number << "(10) = " << converted << "(" << base << ")" << endl;
    
    return 0;
}
```
{% endcode %}

## Konwersja na dziesiętny

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>
 
using namespace std;
 
int toDec(string number, int base) {
    int converted = 0;
    int power = 1;
    int i = number.length() - 1;
    int value;
 
    while (i >= 0) {
        if (number[i] <= '9') {
            converted += (number[i] - '0') * power;
        } else {
            value = number[i] - 'A' + 10;
            converted += value * power;
        }
 
        power *= base;
        i -= 1;
    }
 
    return converted;
}
 
int main() {
    string number = "AF2";
    int base = 16;
 
    int converted = toDec(number, base);
 
    cout << number << "(" << base << ") = " << converted << "(10)" << endl;
 
    return 0;
}
```
{% endcode %}
