# ONP

## Opis problemu

{% content-ref url="../../../../algorithms/text/odwrotna-notacja-polska.md" %}
[odwrotna-notacja-polska.md](../../../../algorithms/text/odwrotna-notacja-polska.md)
{% endcontent-ref %}

## Implementacja

```python
def compute(a: float, b: float, op: str) -> float:
	if op == "+":
		return a + b
	elif op == "-":
		return a - b
	elif op == "*":
		return a * b
	elif op == "/":
		return a / b


def calculate_rpn(rpn: str) -> float:
	rpn_stack = []
	
	for symbol in rpn:
		if symbol.isdigit():
			rpn_stack.append(int(symbol))
		else:
			b = rpn_stack[-1]
			a = rpn_stack[-2]
			rpn_stack.pop()
			rpn_stack.pop()
			result = compute(a, b, symbol)
			rpn_stack.append(result)
				
	return rpn_stack[0]
	

rpn = "27+3/13-4*+2/"
result = calculate_rpn(rpn)
print(result)
```

### Link do implementacji

{% embed url="https://ideone.com/RuReCs" %}
Obliczanie wartości wyrażenia ONP
{% endembed %}

### Opis implementacji

TODO
