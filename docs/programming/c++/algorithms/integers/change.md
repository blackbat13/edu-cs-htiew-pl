# Wydawanie reszty

## [:link: Opis problemu](../../../../algorithms/integers/atm-problem/README.md)

## Podejście zachłanne

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int changeGreedy(int amount, int coins[]) {
    int result = 0;
    int i = 0;

    while (amount > 0) {
        result += amount / coins[i];
        amount %= coins[i];
        i++;
    }

    return result;
}

int main() {
    int amount = 589;
    int coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    
    int result = changeGreedy(amount, coins);

    cout << "Greedy algorithm result: " << result << endl;

    return 0;
}
```

### Link do implementacji

[Zachłanne wydawanie reszty](https://ideone.com/PQmCHG)

## Podejście dynamiczne

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void printUsedCoins(int usedCoins[], int amount) {
	while (amount > 0) {
        cout << usedCoins[amount] << " ";
        amount -= usedCoins[amount];
    }

    cout << endl;
}

void changeDynamic(int amount, int numberOfCoins, int coins[]) {
    int partialResults[amount + 1];
    int usedCoins[amount + 1];
    int coinValue;
    int infinity = 1000000;
    
    partialResults[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        partialResults[i] = infinity;
    }

    for (int j = 0; j < numberOfCoins; j++) {
        coinValue = coins[j];
        for (int i = 0; i <= amount - coinValue; i++) {
            if (partialResults[i] + 1 < partialResults[i + coinValue]) {
                partialResults[i + coinValue] = partialResults[i] + 1;
                usedCoins[i + coinValue] = coinValue;
            }
        }
    }

    if (partialResults[amount] == infinity) {
        cout << "Cannot give out specified value using given coins." << endl;
        return;
    }

    cout << "Amount " << amount << " can be given out using " << partialResults[amount] << " coins." << endl;
    cout << "Used coins: ";
    
    printUsedCoins(usedCoins, amount);
}

int main() {
    int amount = 14;
    int numberOfCoins 5;
    int coins[5] = {1, 2, 7, 10};

    cout << "Dynamic algorithm result:" << endl;
    changeDynamic(amount, numberOfCoins, coins);

    return 0;
}
```
