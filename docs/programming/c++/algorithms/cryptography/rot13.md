# Szyfr ROT13

## [Opis problemu](../../../../algorithms/cryptography/symmetric/rot13.md)


## Szyfrowanie

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

string encryptRot13(string message) {
    string result = "";
    char encrypted;
    
    for(char letter : message) {
        encrypted = letter + 13;
        if(encrypted > 'z') {
            encrypted = encrypted - 'z' + 'a' - 1;
        }
        
        result += encrypted;
    }
    
    return result;
}

int main() {
    string message = "computerscience";
    
    string encrypted = encryptRot13(message);
    
    cout << encrypted << endl;
    
    return 0;
}
```


## Deszyfrowanie

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

string decryptRot13(string encrypted) {
    string result = "";
    char decrypted;
    
    for(char letter : encrypted) {
        decrypted = letter - 13;
        if(decrypted < 'a') {
            decrypted = 'z' - ('a' - decrypted - 1);
        }
        
        result += decrypted;
    }
    
    return result;
}

int main() {
    string encrypted = "pczdihrfgpvrbpr";
    
    string decrypted = decryptRot13(encrypted);
    
    cout << decrypted << endl;
    
    return 0;
}
```

