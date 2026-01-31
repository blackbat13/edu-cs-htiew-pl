# Szyfr Beauforta

## [:link: Opis problemu](../../../../algorithms/cryptography/symmetric/beaufort.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

string encode(string message, string key) {
    string encoded;
    int letter, keyIndex, k;
    letter = keyIndex = k = 0;
    
    for(char character : message) {
        k = 26 - ((int)character - (int)'a') + ((int)key[keyIndex] - (int)'a');
        k %= 26;
        letter = (int)'a' + k;
        
        if (letter > (int)'z') {
            letter = (int)'a' + letter - (int)'z';
        }

        encoded += (char)letter;
        keyIndex++;
        keyIndex %= key.size();
    }

    return encoded;
}

int main() {
    string message = "computerscience";
    string key = "cat";

    string encoded = encode(message, key);
    string decoded = encode(encoded, key);

    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decoded << endl;
    
    return 0;
}
```
