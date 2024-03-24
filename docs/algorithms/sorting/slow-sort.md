---
description: Slowsort
---

# Sortowanie wolne

Sortowanie wolne (ang. *Slowsort*) to jeden z humorystycznych i niepraktycznych algorytmów sortowania.

## Animacja

{% embed url="https://www.youtube.com/watch?v=QbRoyhGdjnA" %}
[Animacja sortowania wolnego](https://www.youtube.com/watch?v=QbRoyhGdjnA)
{% endembed %}

## Pseudokod

```
procedura SortowanieWolne(A, pocz, kon):
    1. Jeżeli pocz >= kon, to:
        2. Zakończ

    3. srodek := (pocz + kon) div 2
    4. SortowanieWolne(A, pocz, srodek)
    5. SortowanieWolne(A, srodek + 1, kon)
    
    6. Jeżeli A[kon] < A[srodek], to:
        7. Zamień(A[srodek], A[kon])

    8. SortowanieWolne(A, pocz, kon - 1)
```

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/sorting/slow-sort.md" %}
[slow-sort.md](../../programming/c++/algorithms/sorting/slow-sort.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/sorting/slow-sort.md" %}
[slow-sort.md](../../programming/python/algorithms/sorting/slow-sort.md)
{% endcontent-ref %}
