# Szyfr Playfaira

## [Opis problemu](../../../../algorithms/cryptography/symmetric/playfair.md)


## Szyfrowanie

```python linenums="1"
def find(letter: str, tab: list) -> (int, int):
    for i in range(6):
        for j in range(6):
            if letter == tab[i][j]:
                return i, j


def create_order(key: str) -> list:
    alphabet = ["a", "ą", "b", "c", "ć", "d", "e", "ę", "f", "g", "h", "i", "j", "k", "l", "ł", "m", "n", "ń", "o", "ó",
                "p", "q", "r", "s", "ś", "t", "u", "v", "w", "x", "y", "z", "ź", "ż", " "]
    order = []
    for letter in key:
        if letter in alphabet:
            alphabet.remove(letter)
            order.append(letter)

    order.extend(alphabet)

    return order


def encode(key: str, message: str):
    order = create_order(key)

    tab = [[order[i * 6 + j] for j in range(6)] for i in range(6)]

    if len(message) % 2 == 1:
        message += " "

    result = ""
    for i in range(0, len(message), 2):
        letter1, letter2 = message[i], message[i + 1]
        x1, y1 = find(letter1, tab)
        x2, y2 = find(letter2, tab)

        if y1 == y2:
            crypto1 = tab[x1][(y1 + 1) % 6]
            crypto2 = tab[x2][(y2 + 1) % 6]
        elif x1 == x2:
            crypto1 = tab[(x1 + 1) % 6][y1]
            crypto2 = tab[(x2 + 1) % 6][y2]
        else:
            crypto1 = tab[x1][y2]
            crypto2 = tab[x2][y1]

        result += crypto1 + crypto2

    return result


key = "computer"
message = "science"

encoded = encode(key, message)

print(encoded)
```


## Deszyfrowanie

```python linenums="1"
def find(letter: str, tab: list) -> (int, int):
    for i in range(6):
        for j in range(6):
            if letter == tab[i][j]:
                return i, j


def create_order(key: str) -> list:
    alphabet = ["a", "ą", "b", "c", "ć", "d", "e", "ę", "f", "g", "h", "i", "j", "k", "l", "ł", "m", "n", "ń", "o", "ó",
                "p", "q", "r", "s", "ś", "t", "u", "v", "w", "x", "y", "z", "ź", "ż", " "]
    order = []
    for letter in key:
        if letter in alphabet:
            alphabet.remove(letter)
            order.append(letter)

    order.extend(alphabet)

    return order


def decode(key: str, message: str):
    order = create_order(key)

    tab = [[order[i * 6 + j] for j in range(6)] for i in range(6)]

    if len(message) % 2 == 1:
        message += " "

    result = ""
    for i in range(0, len(message), 2):
        letter1, letter2 = message[i], message[i + 1]
        x1, y1 = find(letter1, tab)
        x2, y2 = find(letter2, tab)

        if y1 == y2:
            crypto1 = tab[x1][y1 - 1]
            crypto2 = tab[x2][y2 - 1]
        elif x1 == x2:
            crypto1 = tab[x1 - 1][y1]
            crypto2 = tab[x2 - 1][y2]
        else:
            crypto1 = tab[x1][y2]
            crypto2 = tab[x2][y1]

        result += crypto1 + crypto2

    return result


key = "computer"
message = "ómdćjućx"

decoded = decode(key, message)

print(decoded)
```

