# Sumy prefiksowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/prefix-sum.md" %}
[prefix-sum.md](../../../../algorithms/searching/prefix-sum.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

void computePrefixSum(int numbersCount, int numbersArray[],
                      int prefixSumArray[]) {
  prefixSumArray[0] = 0;
  for (int i = 1; i <= numbersCount; i++) {
    prefixSumArray[i] = prefixSumArray[i - 1] + numbersArray[i - 1];
  }
}

void answerQueries(int numbersCount, int numbersArray[], int queriesCount,
                   int queriesArray[][2]) {
  int prefixSumArray[numbersCount + 1];
  computePrefixSum(numbersCount, numbersArray, prefixSumArray);
  for (int i = 0; i < queriesCount; i++) {
    int result = prefixSumArray[queriesArray[i][1] + 1] -
                 prefixSumArray[queriesArray[i][0]];
    cout << "sum(" << queriesArray[i][0] << ":" << queriesArray[i][1]
         << ") = " << result << endl;
  }
}

int main() {
  int numbersCount = 10;
  int numbersArray[10] = {8, 4, 1, 5, 8, 0, 12, 9, 26, 3};
  int queriesCount = 3;
  int queriesArray[3][2] = {{1, 5}, {0, 3}, {6, 9}};

  answerQueries(numbersCount, numbersArray, queriesCount, queriesArray);

  return 0;
}
```
{% endcode %}
