# Szyfr Beauforta

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/beaufort.md" %}
[beaufort.md](../../../../algorithms/cryptography/beaufort.md)
{% endcontent-ref %}

## Szyfrowanie i deszyfrowanie

### Implementacja

```python
def is_letter(character: str) -> bool:
    """
    Checks if given character is a (small) letter
    :param character: character to check
    :return: True if character is a (small) letter, False otherwise
    """
    return ord('a') <= ord(character) <= ord('z')


def encode(message: str, key: str) -> str:
    encoded = ""
    letter = 0
    key_index = 0
    k = 0
    
    for i in range(len(message)):
        if not is_letter(message[i]):
            encoded += message[i]
            continue
            
        k = 26 - (ord(message[i]) - ord('a')) + (ord(key[key_index]) - ord('a'))
        k %= 26
        letter = ord('a') + k
        
        if letter > ord('z'):
            letter = ord('a') + letter - ord('z')

        encoded += chr(letter)
        key_index += 1
        key_index %= len(key)

    return encoded


message = "computer science"
key = "cat"

encoded = encode(message, key)
decoded = encode(encoded, key)

print(f"Encoded: {encoded}")
print(f"Decoded: {decoded}")
```

### Link do implementacji

{% embed url="https://ideone.com/bbGaVQ" %}
Szyfr Beauforta
{% endembed %}

### Opis implementacji

TODO
