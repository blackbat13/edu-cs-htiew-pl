# Kolejka

Kolejka (ang. *Queue*) to podstawowa struktura danych, która, podobnie jak stos, organizuje elementy w sposób liniowy. Kluczową cechą kolejki jest zasada FIFO (ang. *First In, First Out*), co oznacza, że pierwszy element dodany do kolejki jest pierwszym elementem, który zostanie z niej usunięty. Jest to zachowanie analogiczne do rzeczywistej kolejki, na przykład w sklepie - pierwsza osoba, która dołączyła do kolejki, jest pierwszą osobą, która opuszcza kolejkę.

Podstawowe operacje wykonywane na kolejce to:

- **Enqueue** (dodaj do kolejki): dodaje element na koniec kolejki.
- **Dequeue** (usuń z kolejki): usuwa element z początku kolejki.

Dodatkowe operacje, które mogą być dostępne w niektórych implementacjach kolejki, to:

- **Front/Peek**: zwraca pierwszy element kolejki bez usuwania go.
- **IsEmpty**: sprawdza, czy kolejka jest pusta.
- **Size**: zwraca liczbę elementów w kolejce.

## Zastosowania

Kolejki znajdują szerokie zastosowanie w informatyce, w tym:

- **Synchronizacja danych**: kolejki są często używane do synchronizacji danych między procesami. Mogą być np. używane do bezpiecznego przesyłania żądań z wątku producenta do wątku konsumenta.
- **Buforowanie danych**: kolejki mogą służyć jako bufory dla danych przesyłanych między dwoma jednostkami procesora lub pomiędzy urządzeniem peryferyjnym a procesorem.
- **Planowanie CPU**: systemy operacyjne często używają kolejek do zarządzania procesami, które oczekują na dostęp do zasobów, takich jak procesor, pamięć, dysk, etc.
- **Algorytmy grafowe**: kolejki są używane w algorytmach przeszukiwania grafu, takich jak przeszukiwanie wszerz (BFS).

Znając podstawy kolejek, możemy zrozumieć wiele kluczowych aspektów zarządzania danymi w informatyce, zarówno w systemach operacyjnych, jak i w bardziej złożonych algorytmach.

## Implementacja

Kolejki mogą być zaimplementowane za pomocą różnych struktur danych, w tym tablic i list połączonych. Wybór struktury danych do implementacji kolejki zależy od konkretnych wymagań, takich jak efektywność operacji, zużycie pamięci i łatwość implementacji.

Poniżej znajdziesz przykładowe implementacje kolejki w wybranych językach programowania.

### [:simple-cplusplus: C++](../../programming/c++/algorithms/structures/queue.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/structures/queue.md){ .md-button }
