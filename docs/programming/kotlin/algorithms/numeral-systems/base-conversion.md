# Konwersja pomiędzy systemami liczbowymi

## Opis problemu

{% content-ref url="../../../../algorithms/numeral-systems/README.md" %}
[Systemy liczbowe](../../../../algorithms/numeral-systems/README.md)
{% endcontent-ref %}

## Konwersja z dziesiętnego

```python
def from_dec(number: int, new_base: int) -> str:
    converted = ""
    remainder = 0
    
    while number > 0:
        remainder = number % new_base
        number = number // new_base
        
        if remainder > 9:
            converted = chr(ord('A') + remainder - 10) + converted
        else:
            converted = str(remainder) + converted

    return converted


number = 241
base = 16

converted = from_dec(number, base)

print(f'{number} (10) = {converted} ({base})')
```

### Link do implementacji

{% embed url="https://ideone.com/Olpjrr" %}
Konwersja z dziesiętnego
{% endembed %}

## Konwersja na dziesiętny

```python
def to_dec(number: str, base: int) -> int:
    converted = 0
    power = 1
    i = len(number) - 1
    
    while i >= 0:
        if ord(number[i]) <= ord('9'):
            converted += int(number[i]) * power
        else:
            value = ord(number[i]) - ord('A') + 10
            converted += value * power
            
        power *= base
        i -= 1

    return converted


number = "AF2"
base = 16

converted = to_dec(number, base)

print(f'{number} ({base}) = {converted} (10)')
```

### Link do implementacji

{% embed url="https://ideone.com/KxEbY6" %}
Konwersja na dziesiętny
{% endembed %}