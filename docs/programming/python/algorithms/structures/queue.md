# Kolejka

## [Opis problemu](../../../../algorithms/structures/queue.md)

## Implementacja

```python linenums="1"
class Queue:
  class Element:
    def __init__(self, value):
      self._value = value
      self._next = None
      self._previous = None

    def clear_forward(self):
      if self._next is not None:
        self._next.clear()
        self._next = None
        self._previous = None
      
  def __init__(self):
    self._first_element = None
    self._last_element = None

  def push(self, value):
    new_element = Queue.Element(value)
    
    if self._first_element is None:
      self._first_element = new_element
      self._last_element = new_element
      return

    new_element._previous = self._last_element
    self._last_element._next = new_element
    self._last_element = new_element

  def front(self):
    return self._first_element._value

  def pop(self):
    if self._first_element is not None:
      self._first_element = self._first_element._next
      if self._first_element is not None:
        self._first_element._previous = None
      else:
        self._last_element = None

  def empty(self) -> bool:
    return self._first_element is None

  def clear(self):
    if self._first_element is not None:
      self._first_element.clear_forward()

if __name__ == "__main__":
  queue = Queue()

  for el in [5, 8, 3, 1, 9]:
    queue.push(el)

  while not queue.empty():
    print(queue.front())
    queue.pop()
```
