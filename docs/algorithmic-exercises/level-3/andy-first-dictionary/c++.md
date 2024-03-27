# C++ - rozwiązanie

```cpp linenums="1"
#include <iostream>
#include <set>

using namespace std;

void toWords(string &text, set<string> &words)
{
    int i = 0;
    string b = "";

    while (text.length() > 0)
    {
        if (!isalpha(text[0]) && b.length() > 0)
        {
            words.insert(b);
            b = "";
        }
        else if (isalpha(text[0]))
        {
            b += tolower(text[0]);
        }

        text.erase(0, 1);
    }

    if (b.length() > 0)
    {
        words.insert(b);
    }
}

int main()
{
    string text;
    set<string> words;
    while (cin >> text && !cin.eof())
    {
        toWords(text, words);
    }
    
    for (auto &word : words)
    {
        cout << word << endl;
    }

    return 0;
}
```
