# Rozwiązania

## Zadanie 1

```python linenums="1"
def exercise1():
    path = "parentheses.txt"
    result = 0
    pairs = {"(": ")", "{": "}", "[": "]"}
    with open(path) as file:
        parentheses = file.read().split()
        for par in parentheses:
            stack = []
            ok = True
            for char in par:
                if char in ["[", "(", "{"]:
                    stack.append(char)
                    continue

                if len(stack) == 0:
                    ok = False
                    break

                top = stack.pop(-1)
                if pairs[top] != char:
                    ok = False
                    break
                    
            if ok and len(stack) == 0:
                result += 1

    return result
```

## Zadanie 2

```python linenums="1"
def exercise2():
    path = "parentheses.txt"
    with open(path) as file:
        parentheses = file.read().split()
        parentheses.sort(key=lambda el : (el.count("(") + el.count(")"), el.count("[") + el.count("]"), el.count("{") + el.count("}")))
        return parentheses
```

## Zadanie 3

```python linenums="1"
def exercise3():
    path = "parentheses.txt"
    with open(path) as file:
        parentheses = file.read().split()
        for par in parentheses:
            max_opening_length = 0
            max_closing_length = 0
            current_opening_length = 0
            current_closing_length = 0
            for char in par:
                if char in ["[", "(", "{"]:
                    current_closing_length = 0
                    current_opening_length += 1
                    max_opening_length = max(max_opening_length, current_opening_length)
                else:
                    current_opening_length = 0
                    current_closing_length += 1
                    max_closing_length = max(max_closing_length, current_closing_length)

            print(max_opening_length, max_closing_length)
```
