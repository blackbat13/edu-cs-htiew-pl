# ONP

## [Opis problemu](../../../../algorithms/text/rpn.md)


## Implementacja

```python linenums="1"
from queue import LifoQueue


def calculate_rpn(rpn: str) -> float:
	rpn_stack = LifoQueue()
	
	for symbol in rpn:
		if symbol.isdigit():
			rpn_stack.put(int(symbol))
		else:
			b, a = rpn_stack.get(), rpn_stack.get()
			result = eval(f"{a} {symbol} {b}")
			rpn_stack.put(result)
				
	return rpn_stack.get()
	

rpn = "27+3/13-4*+2/"

result = calculate_rpn(rpn)

print(result)
```
