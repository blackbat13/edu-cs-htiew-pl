# Wydawanie reszty

## [Opis problemu](../../../../algorithms/integers/atm-problem/README.md)

## Podejście zachłanne

```python linenums="1"
def change_greedy(amount: int, coins: list) -> int:
    result = i = 0
    
    while amount > 0:
        result += amount // coins[i]
        amount %= coins[i]
        i += 1

    return result

coins = [200, 100, 50, 20, 10, 5, 2, 1]
amount = 589

result = change_greedy(amount, coins)

print("Greedy algorithm")
print(f"Amount {amount} can be given out using {result} coins")
```

## Podejście dynamiczne

```python linenums="1"
from math import inf

def change_dynamic(amount: int, coins: list):
    partial_results = [inf] * (amount + 1)
    used_coins = [inf] * (amount + 1)

    partial_results[0] = 0

    for coin_value in coins:
        for i in range(0, amount - coin_value + 1):
            if partial_results[i] + 1 < partial_results[i + coin_value]:
                partial_results[i + coin_value] = partial_results[i] + 1
                used_coins[i + coin_value] = coin_value

    if partial_results[amount] == inf:
        print("Cannot give out specified value using given coins")
        return

    print(f"Amount {amount} can be given out using {partial_results[amount]} coins")
    print("Used coins:")
    
    i = amount
    while i > 0:
        print(used_coins[i])
        i -= used_coins[i]

coins = [1, 2, 7, 10]
amount = 14

print("Dynamic algorithm")
change_dynamic(amount, coins)
```

### Opis implementacji

Funkcja `change_dynamic` przyjmuje dwa parametry: kwotę do wydania (`amount`) i listę dostępnych nominałów (`coins`).

Na początku funkcji przygotowujemy stosowne listy do przechowywania wartości częściowych wyników i wykorzystanych nominałów. 

Następnie przechodzimy pętlą przez wszystkie nominały. 

Dla każdego nominału przechodzimy przez odpowiednie pola tablicy. W zależności od wartości pola, dokonujemy zmiany.

Jeżeli po przetworzeniu wszystkich nominałów ostatnie pole tablicy wciąż ma wartość równą nieskończoności, to wypisujemy odpowiedni komunikat o braku możliwości wydania podanej kwoty i kończymy działanie funkcji.
