# Szyfr ROT13

## [Opis problemu](../../../../algorithms/cryptography/rot13.md)


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

[Szyfrowanie szyfrem ROT13](https://ideone.com/k1CQdI)

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

[Deszyfrowanie szyfrem ROT13](https://ideone.com/iXANLs)

### Opis implementacji

TODO
