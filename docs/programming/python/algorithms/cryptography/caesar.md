# Szyfr Cezara

## [Opis problemu](../../../../algorithms/cryptography/symmetric/caesar.md)


## Szyfrowanie

```python linenums="1"
def encrypt_caesar(message: str, key: int) -> str:
    encrypted = ""

    for letter in message:
        encrypted_letter = ord(letter) + key
        if encrypted_letter > ord("z"):
            encrypted_letter = ord("a") + encrypted_letter - ord("z")

        encrypted += chr(encrypted_letter)

    return encrypted


message = "computerscience"
key = 3

encrypted = encrypt_caesar(message, key)

print(encrypted)
```


## Deszyfrowanie

```python linenums="1"
def decrypt_caesar(message: str, key: int) -> str:
    decrypted = ""

    for letter in message:
        decrypted_letter = ord(letter) - key
        if decrypted_letter < ord("a"):
            decrypted_letter = ord("z") - (ord("a") - decrypted_letter)

        decrypted += chr(decrypted_letter)

    return decrypted


message = "frpsxwhuvflhqfh"
key = 3

decrypted = decrypt_caesar(message, key)

print(decrypted)
```

