# Szyfr Vigenere"a

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/symmetric/vigenere.md" %}
[vigenere.md](../../../../algorithms/cryptography/symmetric/vigenere.md)
{% endcontent-ref %}

## Szyfrowanie

{% code overflow="wrap" lineNumbers="true" %}
```python
def encrypt_vigenere(message: str, key: str) -> str:
    encrypted = ""
    key_index = 0
    
    for letter in message:            
        k = ord(key[key_index]) - ord("a")
        encrypted_letter = ord(letter) + k
        
        if encrypted_letter > ord("z"):
            encrypted_letter = ord("a") + encrypted_letter - ord("z")

        encrypted += chr(encrypted_letter)
        key_index += 1
        key_index %= len(key)

    return encrypted


message = "computerscience"
key = "cat"

encrypted = encrypt_vigenere(message, key)

print(encrypted)
```
{% endcode %}

## Deszyfrowanie

{% code overflow="wrap" lineNumbers="true" %}
```python
def decrypt_vigenere(message: str, key: str) -> str:
    decrypted = ""
    key_index = 0
    
    for letter in message:
        k = ord(key[key_index]) - ord("a")
        decrypted_letter = ord(letter) - k
        
        if decrypted_letter < ord("a"):
            decrypted_letter = ord("z") - (ord("a") - decrypted_letter)

        decrypted += chr(decrypted_letter)
        key_index += 1
        key_index %= len(key)

    return decrypted


message = "eogrungrmeixpcx"
key = "cat"

decrypted = decrypt_vigenere(message, key)

print(decrypted)
```
{% endcode %}
