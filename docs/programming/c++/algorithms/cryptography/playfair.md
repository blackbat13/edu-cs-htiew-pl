# Szyfr Playfaira

## [:link: Opis problemu](../../../../algorithms/cryptography/symmetric/playfair.md)

## Szyfrowanie

```cpp linenums="1"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> find(char letter, vector<vector<char>>& tab) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (letter == tab[i][j]) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<char> createOrder(string key) {
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o',
                             'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> order;
    
    for (char letter : key) {
        auto it = find(alphabet.begin(), alphabet.end(), letter);
        if (it != alphabet.end()) {
            alphabet.erase(it);
            order.push_back(letter);
        }
    }
    
    order.insert(order.end(), alphabet.begin(), alphabet.end());
    return order;
}

string encode(string key, string message) {
    vector<char> order = createOrder(key);
    vector<vector<char>> tab(5, vector<char>(5));
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tab[i][j] = order[i * 5 + j];
        }
    }
    
    if (message.size() % 2 == 1) {
        message += "x";
    }
    
    string result = "";
    for (int i = 0; i < message.size(); i += 2) {
        auto [x1, y1] = find(message[i], tab);
        auto [x2, y2] = find(message[i + 1], tab);
        
        if (y1 == y2) {
            result += tab[x1][(y1 + 1) % 5];
            result += tab[x2][(y2 + 1) % 5];
        } else if (x1 == x2) {
            result += tab[(x1 + 1) % 5][y1];
            result += tab[(x2 + 1) % 5][y2];
        } else {
            result += tab[x1][y2];
            result += tab[x2][y1];
        }
    }
    
    return result;
}

int main() {
    string key = "computer";
    string message = "science";
    
    string encoded = encode(key, message);
    cout << encoded << endl;
    
    return 0;
}
```

## Deszyfrowanie

```cpp linenums="1"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> find(char letter, vector<vector<char>>& tab) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (letter == tab[i][j]) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<char> createOrder(string key) {
    vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l', 'm', 'n', 'o',
                             'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> order;
    
    for (char letter : key) {
        auto it = find(alphabet.begin(), alphabet.end(), letter);
        if (it != alphabet.end()) {
            alphabet.erase(it);
            order.push_back(letter);
        }
    }
    
    order.insert(order.end(), alphabet.begin(), alphabet.end());
    return order;
}

string decode(string key, string message) {
    vector<char> order = createOrder(key);
    vector<vector<char>> tab(5, vector<char>(5));
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tab[i][j] = order[i * 5 + j];
        }
    }
    
    if (message.size() % 2 == 1) {
        message += "x";
    }
    
    string result = "";
    for (int i = 0; i < message.size(); i += 2) {
        auto [x1, y1] = find(message[i], tab);
        auto [x2, y2] = find(message[i + 1], tab);
        
        if (y1 == y2) {
            result += tab[x1][y1 - 1];
            result += tab[x2][y2 - 1];
        } else if (x1 == x2) {
            result += tab[x1 - 1][y1];
            result += tab[x2 - 1][y2];
        } else {
            result += tab[x1][y2];
            result += tab[x2][y1];
        }
    }
    
    return result;
}

int main() {
    string key = "computer";
    string message = "kufbkmrw";
    
    string decoded = decode(key, message);
    cout << decoded << endl;
    
    return 0;
}
```
