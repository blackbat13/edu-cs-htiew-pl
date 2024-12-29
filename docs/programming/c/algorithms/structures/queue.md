# Kolejka

## [:link: Opis problemu](../../../../algorithms/structures/queue.md)

## Implementacja

```c linenums="1"
#include <stdio.h>
#include <stdlib.h>


typedef struct element {
    int value;
    struct element *next;
} element;

typedef struct Queue {
    element *front_el;
    int el_count;
} Queue;

void init(Queue *queue) {
    queue->front_el = NULL;
    queue->el_count = 0;
}

void push(int value, Queue *queue) {
    element *new_el = malloc(sizeof(element));

    new_el->value = value;
    new_el->next = NULL;

    if (queue->front_el == NULL) {
        queue->front_el = new_el;
        queue->el_count++;
        return;
    }

    element *last_el = queue->front_el;
    while (last_el->next != NULL) {
        last_el = last_el->next;
    }

    last_el->next = new_el;
    queue->el_count++;
}

int front(Queue *queue) {
    if (queue->front_el != NULL) {
        return queue->front_el->value;
    }
}

void pop(Queue *queue) {
    if (queue->front_el != NULL) {
        element *tmp = queue->front_el->next;
        free(queue->front_el);
        queue->front_el = tmp;
        queue->el_count--;
        return;
    }
}

void clear(Queue *queue) {
    element *tmp;
    while (queue->front_el != NULL) {
        tmp = queue->front_el->next;
        free(queue->front_el);
        queue->front_el = tmp;
    }
}

int is_empty(Queue *queue) {
    return queue->front_el == NULL;
}

int count(Queue *queue) {
    return queue->el_count;
}

int main() {
    int array[10] = {7, 3, 0, 1, 5, 2, 5, 19, 10, 5};
    Queue queue;

    init(&queue);

    for (int i = 0; i < 10; i++) {
        push(array[i], &queue);
    }

    printf("%d\n", count(&queue));

    while (!is_empty(&queue)) {
        printf("%d ", front(&queue));
        pop(&queue);
    }

    printf("\n");

    clear(&queue);

    return 0;
}
```

Ten kod zapewnia prostą implementację kolejki z podstawowymi operacjami, takimi jak inicjalizacja, wypychanie, wyskakiwanie, sprawdzanie, czy jest pusta, liczenie elementów i czyszczenie kolejki. Poniżej znajduje się krótki opis kluczowych komponentów i funkcji.

### Struktury

1. **element**: Reprezentuje węzeł na połączonej liście.

2. **Queue**: Reprezentuje samą kolejkę, zawierając wskaźnik do pierwszego elementu i liczbę elementów.

### Funkcje

1. **init**: Inicjalizuje kolejkę ustawiając przedni element na `NULL` i liczbę elementów na 0.

2. **push**: Dodaje nowy element o podanej wartości na koniec kolejki.

3. **front**: Zwraca wartość pierwszego elementu w kolejce.

4. **pop**: Usuwa przedni element z kolejki.

5. **clear**: Opróżnia kolejkę poprzez zwolnienie wszystkich elementów.

6. **is_empty**: Sprawdza, czy kolejka jest pusta.

7. **count**: Zwraca liczbę elementów w kolejce.

### Funkcja main

Funkcja `main` demonstruje użycie kolejki:

1. Inicjalizuje kolejkę.
2. Przesuwa elementy z tablicy do kolejki.
3. Wypisuje liczbę elementów w kolejce.
4. Iteruje przez kolejkę, drukując i wyskakując każdy element.
5. Czyści kolejkę.
