# Stos

## [Opis problemu](../../../../algorithms/structures/stack.md)

## Implementacja

```python linenums="1"
class Stack:
  class Element:
    def __init__(self, value):
      self._value = value
      self._next = None

    def clear(self):
      if self._next is not None:
        self._next.clear()
        self._next = None
      
  def __init__(self):
    self._top_element = None

  def push(self, value):
    if self._top_element is None:
      self._top_element = Stack.Element(value)
      return

    new_element = Stack.Element(value)
    new_element._next = self._top_element
    self._top_element = new_element

  def top(self):
    return self._top_element._value

  def pop(self):
    if self._top_element is not None:
      self._top_element = self._top_element._next

  def empty(self) -> bool:
    return self._top_element is None

  def clear(self):
    if self._top_element is not None:
      self._top_element.clear()

if __name__ == "__main__":
  stack = Stack()

  for el in [5, 8, 3, 1, 9]:
    stack.push(el)

  while not stack.empty():
    print(stack.top())
    stack.pop()
```
