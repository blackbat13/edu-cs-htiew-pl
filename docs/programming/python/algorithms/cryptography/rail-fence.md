# Szyfr płotkowy

## [:link: Opis problemu](../../../../algorithms/cryptography/symmetric/rail-fence.md)

## Szyfrowanie

```python linenums="1"
def encrypt_rail_fence(message: str, key: int) -> str:
    encrypted = ""

    for k in range(key):
        if k == key - 1:
            jump = (key - 1) * 2
        else:
            jump = (key - (k + 1)) * 2

        for i in range(k, len(message), jump):
            encrypted += message[i]

    return encrypted

message = "computer science"
key = 3

encrypted = encrypt_rail_fence(message, key)

print(encrypted)
```

## Deszyfrowanie

```python linenums="1"
def decrypt_rail_fence(message: str, key: int) -> str:
    decrypted = list(message)
    j = 0

    for k in range(key):
        if k == key - 1:
            jump = (key - 1) * 2
        else:
            jump = (key - (k + 1)) * 2

        for i in range(k, len(message), jump):
            decrypted[i] = message[j]
            j += 1
            
    return "".join(decrypted)

message = "cu eoptrsinemecc"
key = 3

decrypted = decrypt_rail_fence(message, key)

print(decrypted)
```
