# Rozwiązania - C++

## Zadanie 1

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names_list;
    ifstream file("names.txt");
    string name;

    while (file >> name && !file.eof())
    {
        names_list.push_back(name);
    }

    file.close();

    int count = 0;
    for (auto name : names_list)
    {
        if (name[0] == 'B')
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
```

## Zadanie 2

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names_list;
    ifstream file("names.txt");
    string name;

    while (file >> name && !file.eof())
    {
        names_list.push_back(name);
    }

    file.close();

    int count = 0;
    for (auto name : names_list)
    {
        if (name.back() == 'a')
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
```

## Zadanie 5

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names_list;
    ifstream file("names.txt");
    string name;

    while (file >> name && !file.eof())
    {
        names_list.push_back(name);
    }

    file.close();

    int count = 0;
    for (auto name : names_list)
    {
        for (int i = 1; i < name.size() - 1; ++i)
        {
            if (name[i] == 'e')
            {
                count++;
                break;
            }
        }
    }

    cout << count << endl;
    return 0;
}
```

## Zadanie 9

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_vowels(string text)
{
    string vowels = "aeiouy";
    int count = 0;
    for (auto character : text)
    {
        if (vowels.find(character) != string::npos)
        {
            count++;
        }
    }

    return count;
}

int main() {
    vector<string> names_list;
    ifstream file("names.txt");
    string name;

    while (file >> name && !file.eof())
    {
        names_list.push_back(name);
    }
    
    file.close();

    vector<int> vowels_counters;
    for (auto name : names_list)
    {
        vowels_counters.push_back(count_vowels(name));
    }

    int max_vowels = *max_element(vowels_counters.begin(), vowels_counters.end());
    vector<string> max_vowels_names;
    for (int i = 0; i < vowels_counters.size(); i++)
    {
        if (vowels_counters[i] == max_vowels)
        {
            max_vowels_names.push_back(names_list[i]);
        }
    }

    sort(max_vowels_names.begin(), max_vowels_names.end());
    for (auto name : max_vowels_names)
    {
        cout << name << endl;
    }
    
    return 0;
}
```

## Zadanie 10

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> names_list;
    ifstream file("names.txt");
    string name;

    while (file >> name && !file.eof())
    {
        names_list.push_back(name);
    }

    file.close();

    vector<int> names_lengths;
    for (auto name : names_list)
    {
        names_lengths.push_back(name.size());
    }

    int min_length = *min_element(names_lengths.begin(), names_lengths.end());
    int max_length = *max_element(names_lengths.begin(), names_lengths.end());

    vector<string> min_names;
    for (auto name : names_list)
    {
        if (name.size() == min_length)
        {
            min_names.push_back(name);
        }
    }

    vector<string> max_names;
    for (auto name : names_list)
    {
        if (name.size() == max_length)
        {
            max_names.push_back(name);
        }
    }

    cout << "Najkrotsze imiona:" << endl;
    cout << "Dlugosc: " << min_length << endl;
    cout << "Imiona: ";
    for (auto name : min_names)
    {
        cout << name << " ";
    }

    cout << endl
         << endl;
    cout << "Najdluzsze imiona:" << endl;
    cout << "Dlugosc: " << max_length << endl;
    cout << "Imiona: ";
    for (auto name : max_names)
    {
        cout << name << " ";
    }

    cout << endl;
    return 0;
}
```
