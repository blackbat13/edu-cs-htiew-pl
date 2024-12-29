# Stos

## [:link: Opis problemu](../../../../algorithms/structures/stack.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

class Stack {

    struct element {
        int value;
        element *next;
    };

    element *top_el;
    int el_count;
    
public:

    Stack() {
        top_el = nullptr;
        el_count = 0;
    }

    void push(int value) {
        element *new_el = new element();
        new_el->value = value;
        new_el->next = top_el;
        top_el = new_el;
        el_count++;
    }

    int top() {
        if (top_el != nullptr) {
            return top_el->value;
        }

        throw nullptr;
    }

    void pop() {
        if (top_el != nullptr) {
            element *tmp = top_el->next;
            delete top_el;
            top_el = tmp;
            el_count--;
            return;
        }

        throw nullptr;
    }

    void clear() {
        element *tmp;
        while (top_el != nullptr) {
            tmp = top_el->next;
            delete top_el;
            top_el = tmp;
        }
    }

    bool is_empty() {
        return top_el == nullptr;
    }

    int count() {
        return el_count;
    }

    ~Stack() {
        clear();
    }
};

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    Stack stack = Stack();
    
    for (int i = 0; i < 10; i++) {
        stack.push(array[i]);
    }

    cout << stack.count() << endl;

    while (!stack.is_empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }

    cout << endl;
    
    return 0;
}
```
