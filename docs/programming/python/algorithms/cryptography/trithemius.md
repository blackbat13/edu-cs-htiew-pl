# Szyfr Trithemius"a

## Opis problemu

{% content-ref url="../../../../algorithms/cryptography/symmetric/trithemius.md" %}
[trithemius.md](../../../../algorithms/cryptography/symmetric/trithemius.md)
{% endcontent-ref %}

## Szyfrowanie

{% code overflow="wrap" lineNumbers="true" %}
```python
def encrypt_trithemius(message: str) -> bool:
    encrypted = ""
    k = 0
    
    for letter in message:
        encrypted_letter = ord(letter) + k
        
        if encrypted_letter > ord("z"):
            encrypted_letter = ord("a") + encrypted_letter - ord("z")

        encrypted += chr(encrypted_letter)
        k += 1
        k %= 26

    return encrypted


message = "computerscience"

encrypted = encrypt_trithemius(message)

print(encrypted)
```
{% endcode %}

## Deszyfrowanie

{% code overflow="wrap" lineNumbers="true" %}
```python
def decrypt_trithemius(message: str) -> str:
    decrypted = ""
    k = 0
    
    for letter in message:   
        decrypted_letter = ord(letter) - k
        
        if decrypted_letter < ord("a"):
            decrypted_letter = ord("z") - (ord("a") - decrypted_letter)

        decrypted += chr(decrypted_letter)
        k += 1
        k %= 26

    return decrypted


message = "cposyykyblspzps"

decrypted = decrypt_trithemius(message)

print(decrypted)
```
{% endcode %}
