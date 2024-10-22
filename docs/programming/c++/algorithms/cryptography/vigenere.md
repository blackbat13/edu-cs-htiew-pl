# Szyfr Vigenere'a

## [:link: Opis problemu](../../../../algorithms/cryptography/symmetric/vigenere.md)

## Szyfrowanie

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

string encode(string message, string key) {
    string encoded = "";
    int keyIndex = 0;
    int encodedLetter;
    int k;
    
    for (char letter : message) {
        k = key[keyIndex] - 'a';
        encodedLetter = letter + k;
        
        if (encodedLetter > 'z') {
            encodedLetter = encodedLetter - 'z' + 'a';
        }

        encoded += (char)encodedLetter;
        keyIndex++;
        keyIndex %= key.length();
    }

    return encoded;
}

int main() {
    string message = "computerscience";
    string key = "cat";

    string encoded = encode(message, key);

    cout << encoded << endl;
 
    return 0;   
}
```

## Deszyfrowanie

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

string decode(string message, string key) {
    string decoded = "";
    int keyIndex = 0;
    int decodedLetter;
    int k;
    
    for (char letter : message) {
        k = key[keyIndex] - 'a';
        decodedLetter = letter - k;
        
        if (decodedLetter < 'a') {
            decodedLetter = 'z' - ('a' - decodedLetter);
        }

        decoded += (char)decodedLetter;
        keyIndex++;
        keyIndex %= key.length();
    }

    return decoded;
}

int main() {
    string message = "eogrungrmeixpcx";
    string key = "cat";

    string decoded = decode(message, key);

    cout << decoded << endl;
 
    return 0;   
}
```
