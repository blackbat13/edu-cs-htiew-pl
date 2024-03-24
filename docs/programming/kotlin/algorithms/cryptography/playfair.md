# Szyfr Playfaira

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/playfair.md" %}
[playfair.md](../../../../algorithms/cryptography/playfair.md)
{% endcontent-ref %}

## Szyfrowanie

### Implementacja

```python
def find(letter, tab):
    for i in range(6):
        for j in range(6):
            if letter == tab[i][j]:
                return i, j


def encode(key: str, message: str):
    alphabet = ["a", "ą", "b", "c", "ć", "d", "e", "ę", "f", "g", "h", "i", "j", "k", "l", "ł", "m", "n", "ń", "o", "ó",
                "p", "q", "r", "s", "ś", "t", "u", "v", "w", "x", "y", "z", "ź", "ż", " "]
    tab = [["" for _ in range(6)] for _ in range(6)]
    order = []
    for letter in key:
        if letter in alphabet:
            alphabet.remove(letter)
            order.append(letter)

    for letter in alphabet:
        order.append(letter)

    k = 0
    for i in range(6):
        for j in range(6):
            tab[i][j] = order[k]
            k += 1

    if len(message) % 2 == 1:
        message += " "

    result = ""
    for i in range(0, len(message), 2):
        letter1 = message[i]
        letter2 = message[i + 1]
        x1, y1 = find(letter1, tab)
        x2, y2 = find(letter2, tab)
        crypto1 = ""
        crypto2 = ""

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

### Link do implementacji

{% embed url="https://ideone.com/axOimk" %}
Szyfrowanie szyfrem Playfaira
{% endembed %}

### Opis implementacji

TODO

## Deszyfrowanie

### Implementacja

```python
def find(letter, tab):
    for i in range(6):
        for j in range(6):
            if letter == tab[i][j]:
                return i, j


def decode(key: str, message: str):
    alphabet = ["a", "ą", "b", "c", "ć", "d", "e", "ę", "f", "g", "h", "i", "j", "k", "l", "ł", "m", "n", "ń", "o", "ó",
                "p", "q", "r", "s", "ś", "t", "u", "v", "w", "x", "y", "z", "ź", "ż", " "]
    tab = [["" for _ in range(6)] for _ in range(6)]
    order = []
    for letter in key:
        if letter in alphabet:
            alphabet.remove(letter)
            order.append(letter)

    for letter in alphabet:
        order.append(letter)

    k = 0
    for i in range(6):
        for j in range(6):
            tab[i][j] = order[k]
            k += 1

    if len(message) % 2 == 1:
        message += " "

    result = ""
    for i in range(0, len(message), 2):
        letter1 = message[i]
        letter2 = message[i + 1]
        x1, y1 = find(letter1, tab)
        x2, y2 = find(letter2, tab)
        crypto1 = ""
        crypto2 = ""

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

### Link do implementacji

{% embed url="https://ideone.com/wzq3j7" %}
Deszyfrowanie szyfrem Playfaira
{% endembed %}

### Opis implementacji

TODO
