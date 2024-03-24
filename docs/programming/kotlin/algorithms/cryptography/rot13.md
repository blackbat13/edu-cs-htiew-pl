# Szyfr ROT13

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/rot13.md" %}
[rot13.md](../../../../algorithms/cryptography/rot13.md)
{% endcontent-ref %}

## Szyfrowanie

### Implementacja

```python
def is_letter(letter: str) -> bool:
    return ord('a') <= ord(letter) <= ord('z')


def encode(message: str) -> str:
    encoded = ""
    letter = 0
    
    for i in range(len(message)):
        if not is_letter(message[i]):
            encoded += message[i]
            continue
            
        letter = ord(message[i]) + 13
        
        if letter > ord('z'):
            letter = ord('a') + letter - ord('z')

        encoded += chr(letter)

    return encoded


message = "computer science"

encoded = encode(message)

print(f"Encoded: {encoded}")
```

### Link do implementacji

{% embed url="https://ideone.com/k1CQdI" %}
Szyfrowanie szyfrem ROT13
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
    letter = 0
    
    for i in range(len(message)):
        if not is_letter(message[i]):
            decoded += message[i]
            continue
            
        letter = ord(message[i]) - 13
        
        if letter < ord('a'):
            letter = ord('z') - (ord('a') - letter)

        decoded += chr(letter)

    return decoded


message = "pczdihrf gpvrbpr"

decoded = decode(message)

print(f"Decoded: {decoded}")
```

### Link do implementacji

{% embed url="https://ideone.com/iXANLs" %}
Deszyfrowanie szyfrem ROT13
{% endembed %}

### Opis implementacji

TODO
