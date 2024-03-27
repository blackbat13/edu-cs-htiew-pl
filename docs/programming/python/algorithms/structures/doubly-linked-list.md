# Lista dwukierunkowa

## [Opis problemu](../../../../algorithms/structures/doubly-linked-list.md)

## Implementacja

```python linenums="1"
class DoublyLinkedList:

  class Element:

    def __init__(self, value):
      self._value = value
      self._next = None
      self._previous = None

    def clear(self):
      if self._next is not None:
        self._next.clear()
        self._next = None
        self._previous = None

  def __init__(self):
    self._first = None
    self._last = None
    self._count = 0

  def size(self):
    return self._count

  def push(self, value):
    if self._first is None:
      self._first = DoublyLinkedList.Element(value)
      self._last = self._first
      self._count += 1
      return

    if self._first == self._last:
        self._last = DoublyLinkedList.Element(value)
        self._first._next = self._last
        self._last._previous = self._first
        self._count += 1
        return

    tmp = self._last
    self._last = DoublyLinkedList.Element(value)
    self._last._previous = tmp
    self._last._previous._next = self._last
    self._count += 1

  def pop(self):
    if self._count == 0:
      return

    if self._count == 1:
      self._first = None
      self._last = None
      self._count = 0
      return

    self._last = self._last._previous
    self._last._next = None
    self._count -= 1

  def __getitem__(self, key):
    if key < 0 or key >= self._count:
      return None

    current = self._first
    current_index = 0

    while current_index < key:
      current_index += 1
      current = current._next

    return current._value

  def __setitem__(self, key, value):
    if key < 0 or key >= self._count:
      return None

    current = self._first
    current_index = 0

    while current_index < key:
      current_index += 1
      current = current._next

    current._value = value

  def clear(self):
    self._first.clear()
    self._first = None
    self._last = None
    self._count = 0

if __name__ == "__main__":
  lst = DoublyLinkedList()

  lst.push(1)
  lst.push(2)
  lst.push(3)

  lst.pop()

  lst[1] = 10

  lst.push(4)

  for i in range(lst.size()):
    print(lst[i])
```
