# Warunek trójkąta

## Opis problemu

{% content-ref url="../../../../algorithms/2d-geometry/triangle-condition.md" %}
[triangle-condition.md](../../../../algorithms/2d-geometry/triangle-condition.md)
{% endcontent-ref %}

## Implementacja

```python
def can_create_triangle(a: int, b: int, c: int) -> bool:
    return a < b + c and b < a + c and c < a + b


a = 3
b = 8
c = 9

if can_create_triangle(a, b, c):
    print(f'Z odcników od długościach {a}, {b} oraz {c} można zbudować trójkąt')
else:
    print(f'Z odcników od długościach {a}, {b} oraz {c} nie można zbudować trójkąta')
```

### Link do implementacji

{% embed url="https://ideone.com/2anTf3" %}
Warunek trójkąta
{% endembed %}

### Opis implementacji

TODO
