# Palindrom

## [Opis problemu](../../../../algorithms/text/palindrome.md)


## Implementacja

```python
def is_palindrome(a: str) -> bool:
    return a == a[::-1]


a = "kajak"

if is_palindrome(a):
    print(f'{a} jest palindromem')
else:
    print(f'{a} nie jest palindromem')
```

### Link do implementacji

[Test palindromu](https://ideone.com/nsapMq)

### Opis implementacji

TODO
