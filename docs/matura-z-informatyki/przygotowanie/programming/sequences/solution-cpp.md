# Rozwiązanie - C++

## Zadanie 1

```cpp linenums="1"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("sequences_test.txt");
    for (int line = 0; line < 10; line++)
    {
        int n, sum = 0, num;
        file >> n;
        for (int i = 0; i < n; i++)
        {
            file >> num;
            sum += num;
        }

        cout << sum << endl;
    }

    file.close();

    return 0;
}
```

## Zadanie 2

```cpp linenums="1"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("sequences_test.txt");
    for (int line = 0; line < 10; line++)
    {
        int n, min_val = 2000, max_val = 0, num;
        file >> n;

        for (int i = 0; i < n; i++)
        {
            file >> num;

            if (num > max_val)
            {
                max_val = num;
            }
            else if (num < min_val)
            {
                min_val = num;
            }
        }

        cout << "Minimum: " << min_val;
        cout << ", Maksimum: " << max_val << endl;
    }

    file.close();

    return 0;
}
```

## Zadanie 3

```cpp linenums="1"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream file("sequences_test.txt");
    for (int line = 0; line < 10; line++)
    {
        int n, num;
        vector<int> primes;
        file >> n;
        for (int i = 0; i < n; i++)
        {
            file >> num;
            if (is_prime(num))
            {
                primes.push_back(num);
            }
        }

        cout << "Ile pierwszych: " << primes.size();
        cout << ", Liczby pierwsze: ";
        for (auto num : primes)
        {
            cout << num << " ";
        }

        cout << endl;
    }

    file.close();

    return 0;
}
```

## Zadanie 4

```cpp linenums="1"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("sequences_test.txt");
    for (int line = 0; line < 10; line++)
    {
        int n, current_length = 1, max_length = 1;
        int current_start = 0, max_start = 0;
        file >> n;
        int seq[n];
        file >> seq[0];
        for (int i = 1; i < n; i++)
        {
            file >> seq[i];
            if (seq[i] > seq[i - 1])
            {
                current_length++;
                if (current_length > max_length)
                {
                    max_length = current_length;
                    max_start = current_start;
                }
            }
            else
            {
                current_length = 1;
                current_start = i;
            }
        }

        cout << "Dlugosc: " << max_length;
        cout << ", Sekwencja: ";
        for (int i = max_start; i < max_start + max_length; i++)
        {
            cout << seq[i] << " ";
        }

        cout << endl;
    }

    file.close();

    return 0;
}
```

## Zadanie 5

```cpp linenums="1"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("sequences_test.txt");
    for (int line = 0; line < 10; line++)
    {
        int n;
        file >> n;
        int seq[n];
        for (int i = 0; i < n; i++)
        {
            file >> seq[i];
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (__gcd(seq[i], seq[j]) == 1)
                {
                    count++;
                }
            }
        }

        cout << count << endl;
    }

    file.close();

    return 0;
}
```
