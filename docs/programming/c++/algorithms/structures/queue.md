# Kolejka

## [:link: Opis problemu](../../../../algorithms/structures/queue.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

class Queue {

    struct element {
        int value;
        element *next;
    };

    element *front_el;
    int el_count;
    
public:

    Queue() {
        front_el = nullptr;
        el_count = 0;
    }

    void push(int value) {
        element *new_el = new element();
        
        new_el->value = value;
        new_el->next = nullptr;
        
        if (front_el == nullptr) {
            front_el = new_el;
            el_count++;
            return;
        }

        element *last_el = front_el;
        while (last_el->next != nullptr) {
            last_el = last_el->next;
        }

        last_el->next = new_el;
        el_count++;
    }

    int front() {
        if (front_el != nullptr) {
            return front_el->value;
        }

        throw nullptr;
    }

    void pop() {
        if (front_el != nullptr) {
            element *tmp = front_el->next;
            delete front_el;
            front_el = tmp;
            el_count--;
            return;
        }

        throw nullptr;
    }

    void clear() {
        element *tmp;
        while (front_el != nullptr) {
            tmp = front_el->next;
            delete front_el;
            front_el = tmp;
        }
    }

    bool is_empty() {
        return front_el == nullptr;
    }

    int count() {
        return el_count;
    }

    ~Queue() {
        clear();
    }
};

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    Queue queue = Queue();
    
    for (int i = 0; i < 10; i++) {
        queue.push(array[i]);
    }

    cout << queue.count() << endl;

    while (!queue.is_empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }

    cout << endl;
    
    return 0;
}
```
