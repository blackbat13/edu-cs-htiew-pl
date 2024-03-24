# Szyfr ROT13

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/symmetric/rot13.md" %}
[rot13.md](../../../../algorithms/cryptography/symmetric/rot13.md)
{% endcontent-ref %}

## Szyfrowanie

{% code overflow="wrap" lineNumbers="true" %}
```python
def encrypt_rot13(message: str) -> str:
    encrypted = ""
    
    for letter in message:
        encrypted_letter = ord(letter) + 13
        
        if encrypted_letter > ord("z"):
            encrypted_letter = ord("a") + encrypted_letter - ord("z")

        encrypted += chr(encrypted_letter)

    return encrypted


message = "computerscience"

encrypted = encrypt_rot13(message)

print(encrypted)
```
{% endcode %}

## Deszyfrowanie

{% code overflow="wrap" lineNumbers="true" %}
```python
def decrypt_rot13(message: str) -> str:
    decrypted = ""
    
    for letter in message:
        decrypted_letter = ord(letter) - 13
        
        if decrypted_letter < ord("a"):
            decrypted_letter = ord("z") - (ord("a") - decrypted_letter)

        decrypted += chr(decrypted_letter)

    return decrypted


message = "pczdihrfgpvrbpr"

decrypted = decrypt_rot13(message)

print(decrypted)
```
{% endcode %}
