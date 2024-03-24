# Najdłuższy spójny podciąg rosnący

## Opis problemu

{% content-ref url="../../../../algorithms/searching/longest-growing-substring.md" %}
[longest-growing-substring.md](../../../../algorithms/searching/longest-growing-substring.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def longest_growing_substring_length(tab: list) -> int:
    mx = length = 1
    
    for i in range(1, len(tab)):
        if tab[i] > tab[i - 1]:
            length += 1
            mx = max(length, mx)
        else:
            length = 1
    
    return mx


tab = [4, 9, 7, 2, 4, 7, 9, 3, 8, 6]

result = longest_growing_substring_length(tab)

print(result)
```
{% endcode %}

Funkcja `longest_growing_substring_length` przyjmuje jako argument listę `tab` (lista liczb) i zwraca długość najdłuższego rosnącego podciągu.

Na początku ustawiamy zmienne `mx` i `length` na $$1$$. `mx` będzie przechowywać maksymalną długość rosnącego podciągu, a `length` aktualną długość bieżącego rosnącego podciągu.

W pętli `for` iterujemy po indeksach od $$1$$ do `len(tab)-1`.
W każdej iteracji sprawdzamy, czy bieżący element `tab[i]` jest większy od poprzedniego elementu `tab[i-1]`. Jeśli tak, oznacza to, że podciąg się powiększa, więc inkrementujemy `length` o $$1$$.
Dodatkowo, jeśli `length` jest większe od `mx`, aktualizujemy `mx` na `length`, ponieważ znaleźliśmy dłuższy rosnący podciąg.
Jeśli bieżący element `tab[i]` nie jest większy od poprzedniego elementu, oznacza to, że rosnący podciąg się kończy. Resetujemy `length` na $$1$$.
Po zakończeniu pętli, zwracamy wartość `mx`, która reprezentuje długość najdłuższego rosnącego podciągu.

W przykładzie podana jest konkretna lista `tab`. Funkcja `longest_growing_substring_length` jest wywoływana z tą listą, a wynikowa długość najdłuższego rosnącego podciągu jest wyświetlana przy użyciu funkcji `print`.

W wyniku wykonania tego kodu zostanie wyświetlona wartość $$4$$, ponieważ najdłuższy rosnący podciąg to $$[2, 4, 7, 9]$$, który ma długość $$4$$.
