# Palindrom

## Opis problemu

{% content-ref url="../../../../algorithms/text/palindrome.md" %}
[palindrome.md](../../../../algorithms/text/palindrome.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def is_palindrome(a: str) -> bool:
    return a == a[::-1]


a = "kajak"

if is_palindrome(a):
    print(f'{a} jest palindromem')
else:
    print(f'{a} nie jest palindromem')
```
{% endcode %}
