# Palindrom

## [:link: Opis problemu](../../../../algorithms/text/palindrome.md)

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <algorithm>

using namespace std;

bool isPalindrome(string str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());

    return str == reversed;
}

int main() {
    string str = "kajak";

    bool result = isPalindrome(str);

    if (result) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
```
