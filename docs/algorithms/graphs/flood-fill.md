---
description: Wypełnianie obszarów
---

# Flood fill

Algorytm Flood Fill jest techniką używaną do wypełniania połączonych, podobnych kolorami obszarów w dwuwymiarowej siatce lub obrazie. Jest często używany w narzędziach graficznych, takich jak programy do tworzenia obrazów i gier, do wypełniania zamkniętych obszarów kolorem lub wzorem.

## Opis algorytmu

Algorytm Flood Fill rozpoczyna działanie od danego punktu (nazywanego "źródłem") i następnie "zalewa" obszar wokół źródła, przechodząc do sąsiednich punktów, które są tego samego koloru, i zmieniając je na kolor "wypełnienia". Proces ten kontynuowany jest, aż cały obszar zostanie wypełniony.

Najpopularniejszymi wariantami algorytmu Flood Fill są:

- **Algorytm czterosąsiadowy** (*Four-Connected*): Przechodzi do sąsiadów na górze, na dole, na lewo i na prawo od danego punktu.
- **Algorytm ośmiosąsiadowy** (*Eight-Connected*): Przechodzi do sąsiadów na górze, na dole, na lewo, na prawo, a także do czterech sąsiadów po przekątnych.

## Przykład 1 - wariant czterosąsiadowy

![By André Karwath aka Aka - Own work, CC BY-SA 2.5, https://commons.wikimedia.org/w/index.php?curid=481651](../../.gitbook/assets/Recursive\_Flood\_Fill\_4\_\(aka\).gif)

## Przykład 2 - wariant ośmiosąsiadowy

![By André Karwath aka Aka - Own work, CC BY-SA 2.5, https://commons.wikimedia.org/w/index.php?curid=481652](../../.gitbook/assets/Recursive\_Flood\_Fill\_8\_\(aka\).gif)

## Pseudokod - wariant czterosąsiadowy

```
funkcja FloodFill(x, y, staryKolor, nowyKolor, obraz):
    1. Jeżeli pole (x, y) znajduje się poza obszarem (obrazu), to:
        2. Zakończ

    3. Jeżeli obraz[x][y] != staryKolor, to:
        4. Zakończ 

    5. obraz[x][y] = nowyKolor
    
    6. FloodFill(x + 1, y, staryKolor, nowyKolor, obraz)
    7. FloodFill(x - 1, y, staryKolor, nowyKolor, obraz)
    8. FloodFill(x, y + 1, staryKolor, nowyKolor, obraz)
    9. FloodFill(x, y - 1, staryKolor, nowyKolor, obraz)
```

Pamiętaj, że powyższy pseudokod jest rekurencyjny i może prowadzić do przekroczenia limitu głębokości stosu w przypadku bardzo dużych obszarów. Istnieją jednak techniki, takie jak algorytm z użyciem stosu lub kolejki, które pozwalają uniknąć tego problemu.

## Złożoność obliczeniowa

Złożoność obliczeniowa algorytmu Flood Fill to $$O(n)$$, gdzie $$n$$ to liczba pikseli, które muszą zostać zmienione. W praktyce wydajność algorytmu zależy od wielu czynników, takich jak wielkość obszaru do wypełnienia, kształt obszaru i wybrana strategia (np. czterosąsiadowa czy ośmiosąsiadowa).

## Podsumowanie

Algorytm Flood Fill to podstawowe narzędzie w grafice komputerowej, używane do wypełniania zamkniętych obszarów kolorem lub wzorem. Jest łatwy do zrozumienia i implementacji, a jego efektywność można znacznie poprawić za pomocą różnych technik, takich jak stosy czy kolejki.

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/graphs/flood-fill.md" %}
[flood-fill.md](../../programming/c++/algorithms/graphs/flood-fill.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/graphs/flood-fill.md" %}
[flood-fill.md](../../programming/python/algorithms/graphs/flood-fill.md)
{% endcontent-ref %}
