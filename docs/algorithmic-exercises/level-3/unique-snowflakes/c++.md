# C++ - rozwiązanie

```cpp linenums="1"
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    unsigned int cases, n, maxSnowflakes, startIndex, index;
    map<unsigned int, unsigned int> lastIndex;
    vector<unsigned int> snowflakes;

    scanf("%u", &cases);

    for (int testCase = 1; testCase <= cases; ++testCase)
    {
        scanf("%u", &n);

        lastIndex.clear();
        maxSnowflakes = 0;
        startIndex = 1;
        snowflakes = vector<unsigned int>(n);

        for (int i = 1; i <= n; i++)
        {
            scanf("%u", &snowflakes[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            index = lastIndex[snowflakes[i]];
            if (index != 0)
            {
                while (startIndex <= index)
                {
                    lastIndex[snowflakes[startIndex]] = 0;
                    ++startIndex;
                }
            }

            lastIndex[snowflakes[i]] = i;
            maxSnowflakes = max(maxSnowflakes, i - startIndex + 1);
        }

        printf("%u\n", maxSnowflakes);
    }

    return 0;
}
```

