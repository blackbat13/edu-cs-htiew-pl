# Szyfr Trithemius'a

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/symmetric/trithemius.md" %}
[trithemius.md](../../../../algorithms/cryptography/symmetric/trithemius.md)
{% endcontent-ref %}

## Szyfrowanie

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

string encryptTrithemius(string message) {
    string result = "";
    char encrypted;
    int k = 0;
    
    for(char letter : message) {
        encrypted = letter + k;
        if(encrypted > 'z') {
            encrypted = encrypted - 'z' + 'a' - 1;
        }
        
        result += encrypted;
        k += 1;
        k %= 26;
    }
    
    return result;
}

int main() {
    string message = "computerscience";
    
    string encrypted = encryptTrithemius(message);
    
    cout << encrypted << endl;
    
    return 0;
}
```
{% endcode %}

## Deszyfrowanie

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

string decryptTrithemius(string encrypted) {
    string result = "";
    char decrypted;
    int k = 0;
    
    for(char letter : encrypted) {
        decrypted = letter - k;
        if(decrypted < 'a') {
            decrypted = 'z' - ('a' - decrypted - 1);
        }
        
        result += decrypted;
        k += 1;
        k %= 26;
    }
    
    return result;
}

int main() {
    string encrypted = "cposyykyblspzps";
    
    string decrypted = decryptTrithemius(encrypted);
    
    cout << decrypted << endl;
    
    return 0;
}
```
{% endcode %}
