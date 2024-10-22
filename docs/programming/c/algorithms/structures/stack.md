# Stos

## [:link: Opis problemu](../../../../algorithms/structures/stack.md)

## Implementacja

```c linenums="1"
#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
  int value;
  struct Element *next;
} Element;

Element *top_el;
int el_count;

void init_stack() {
  top_el = NULL;
  el_count = 0;
}

void push(int value) {
  Element *new_el = malloc(sizeof(Element));
  new_el->value = value;
  new_el->next = top_el;
  top_el = new_el;
  el_count++;
}

int top() {
  if (top_el != NULL) {
    return top_el->value;
  }
}

void pop() {
  if (top_el != NULL) {
    Element *tmp = top_el->next;
    free(top_el);
    top_el = tmp;
    el_count--;
    return;
  }
}

void clear() {
  Element *tmp;
  while (top_el != NULL) {
    tmp = top_el->next;
    free(top_el);
    top_el = tmp;
  }
}

int is_empty() { return top_el == NULL; }

int count() { return el_count; }

int main() {
  int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};

  for (int i = 0; i < 10; i++) {
    push(array[i]);
  }

  printf("Number of elements on the stack: %d\n", count());

  while (!is_empty()) {
    printf("Top element: %d\n", top());
    pop();
  }

  clear();

  return 0;
}
```
