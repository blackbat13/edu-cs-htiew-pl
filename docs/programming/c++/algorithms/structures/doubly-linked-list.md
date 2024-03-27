# Lista dwukierunkowa

## [Opis problemu](../../../../algorithms/structures/doubly-linked-list.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

class DoublyLinkedList {
  struct element {
    int value;
    element *next;
    element *previous;
  };

  element *first, *last;
  int count;

public:
  DoublyLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
  }

  int size() { return count; }

  void push(int value) {
    element *new_element = new element();
    new_element->value = value;
    new_element->next = nullptr;
    new_element->previous = nullptr;
    count++;
    if (first == nullptr) {
      first = new_element;
      last = new_element;
      return;
    } else if (first == last) {
      last = new_element;
      first->next = last;
      last->previous = first;
      return;
    }

    element *tmp = last;
    last = new_element;
    last->previous = tmp;
    last->previous->next = last;
  }

  void pop() {
    if (count == 0) {
      throw out_of_range("List is empty");
    }

    if (count == 1) {
      delete first;
      first = nullptr;
      delete last;
      last = nullptr;
      count = 0;
      return;
    }

    element *tmp = last->previous;
    delete last;
    last = tmp;
    last-> next = nullptr;
    
    count--;
  }

  int operator[](int index) {
    if (index < 0 || index >= count) {
      throw out_of_range("Out of range");
    }

    element *current = first;
    int current_index = 0;
    while (current_index < index) {
      current_index++;
      current = current->next;
    }

    return current->value;
  }

  void replace(int index, int value) {
    if (index < 0 || index >= count) {
      throw out_of_range("Out of range");
    }

    element *current = first;
    int current_index = 0;
    while (current_index < index) {
      current_index++;
      current = current->next;
    }

    current->value = value;
  }

  void clear() {
    element *current = first, *tmp;
    while (current != nullptr) {
      tmp = current->next;
      delete current;
      current = tmp;
    }

    count = 0;
  }

  ~DoublyLinkedList() { clear(); }
};

int main() {
  DoublyLinkedList list = DoublyLinkedList();

  list.push(1);
  list.push(2);
  list.push(3);
  
  list.pop();

  list.replace(1, 10);

  list.push(4);

  for (int i = 0; i < list.size(); i++) {
    cout << list[i] << " ";
  }

  cout << endl;

  return 0;
}
```
