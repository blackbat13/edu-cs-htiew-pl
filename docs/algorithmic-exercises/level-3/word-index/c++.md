# C++ - rozwiązanie

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

void computeWordsIndexes(string txt, int counter, char letter, int &currentWordIndex, map<string, int> &wordToIndex)
{
    if (letter > 'z')
    {
        return;
    }

    string word;

    if (counter == 1)
    {
        for (char c = letter; c <= 'z'; ++c)
        {
            word = txt + c;
            wordToIndex[word] = currentWordIndex;
            currentWordIndex++;
        }

        return;
    }

    for (char c = letter; c <= 'z'; ++c)
    {
        word = txt + c;
        computeWordsIndexes(word, counter - 1, c + 1, currentWordIndex, wordToIndex);
    }
}

int main()
{
    int currentWordIndex = 1;
    string str;
    map<string, int> wordToIndex;

    for (int i = 1; i <= 5; ++i)
    {
        computeWordsIndexes("", i, 'a', currentWordIndex, wordToIndex);
    }

    while (cin >> str && !cin.eof())
    {
        printf("%d\n", wordToIndex[str]);
    }

    return 0;
}
```
{% endcode %}
