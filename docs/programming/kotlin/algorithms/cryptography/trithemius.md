# Szyfr Trithemius'a

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/trithemius.md" %}
[trithemius.md](../../../../algorithms/cryptography/trithemius.md)
{% endcontent-ref %}

## Szyfrowanie

### Implementacja

```python
def is_letter(letter: str) -> bool:
    return ord('a') <= ord(letter) <= ord('z')


def encode(message: str) -> bool:
    encoded = ""
    k = 0
    letter = 0
    
    for i in range(len(message)):
        if not is_letter(message[i]):
            encoded += message[i]
            continue
            
        letter = ord(message[i]) + k
        
        if letter > ord('z'):
            letter = ord('a') + letter - ord('z')

        encoded += chr(letter)
        k += 1
        k %= 26

    return encoded


message = "computer science"

encoded = encode(message)

print(f"Encoded: {encoded}")
```

### Link do implementacji

{% embed url="https://ideone.com/9W6PrX" %}
Szyfrowanie szyfrem Thithemius'a
{% endembed %}

### Opis implementacji

TODO

## Deszyfrowanie

### Implementacja

```python
def is_letter(letter: str) -> bool:
    return ord('a') <= ord(letter) <= ord('z')


def decode(message: str) -> str:
    decoded = ""
    k = 0
    letter = 0
    
    for i in range(len(message)):
        if not is_letter(message[i]):
            decoded += message[i]
            continue
            
        letter = ord(message[i]) - k
        
        if letter < ord('a'):
            letter = ord('z') - (ord('a') - letter)

        decoded += chr(letter)
        k += 1
        k %= 26

    return decoded


message = "cposyyky blspzps"

decoded = decode(message)

print(f"Decoded: {decoded}")
```

### Link do implementacji

{% embed url="https://ideone.com/PzZXD9" %}
Deszyfrowanie szyfrem Trithemius'a
{% endembed %}

### Opis implementacji

TODO
