# Szyfr płotkowy

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/symmetric/rail-fence.md" %}
[rail-fence.md](../../../../algorithms/cryptography/symmetric/rail-fence.md)
{% endcontent-ref %}

## Szyfrowanie

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

string encode(string message, int key) {
    string encoded = "";
    int jump, i;

    for (int k = 0; k < key; k++) {
        if (k == key - 1) {
            jump = (key - 1) * 2;
        } else {
            jump = (key - (k + 1)) * 2;
        }
            
        i = k;
        
        while (i < message.length()) {
            encoded += message[i];
            i += jump;
        }
    }

    return encoded;
}

int main() {
    string message = "computer science";

    string encoded = encode(message, 3);

    cout << encoded << endl;
    
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

string decode(string message, int key) {
    string decoded = message;
    int j = 0;
    int jump, i;

    for (int k = 0; k < key; k++) {
        if (k == key - 1) {
            jump = (key - 1) * 2;
        } else {
            jump = (key - (k + 1)) * 2;
        }
        
        i = k;
        
        while (i < message.length()) {
            decoded[i] = message[j];
            j += 1;
            i += jump;
        }
    }
    
    return decoded;
}

int main() {
    string message = "cu eoptrsinemecc";

    string decoded = decode(message, 3);

    cout << decoded << endl;

    return 0;
}
```
{% endcode %}
