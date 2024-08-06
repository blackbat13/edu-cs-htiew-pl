# Szyfr Beauforta

## [:link: Opis problemu](../../../../algorithms/cryptography/symmetric/beaufort.md)

## Szyfrowanie i deszyfrowanie

```python linenums="1"
def encode(message: str, key: str) -> str:
    encoded = ""
    letter = key_index = k = 0
    
    for character in message:
        k = 26 - (ord(character) - ord("a")) + (ord(key[key_index]) - ord("a"))
        k %= 26
        letter = ord("a") + k
        
        if letter > ord("z"):
            letter = ord("a") + letter - ord("z")

        encoded += chr(letter)
        key_index += 1
        key_index %= len(key)

    return encoded

message = "computerscience"
key = "cat"

encoded = encode(message, key)
decoded = encode(encoded, key)

print(f"Encoded: {encoded}")
print(f"Decoded: {decoded}")
```
