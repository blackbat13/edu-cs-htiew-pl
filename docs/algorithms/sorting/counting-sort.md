# Sortowanie przez zliczanie

Masz nietypowe hobby: zbierasz kamyki z liczbami. Dokładnie, niektóre kamyki mają wzory, które przypominają liczby. Udało Ci się zebrać dość dużą kolekcję z wartościami rozciągającymi się od $$1$$ do $$100$$. Niestety, półka na której trzymałeś swoje kamyki, skrupulatnie ułożone względem swoich wartości, nie wytrzymała i załamała się pod ciężarem Twojej kolekcji. W efekcie wszystkie kamyki spadły na podłogę i trzeba je ponownie uporządkować. Zabierasz się więc do pracy. W twojej kolekcji jest wiele kamyków z takimi samymi liczbami, postanawiasz więc podzielić je na osobne kupki. Przeglądasz kamyki jeden po drugim i odkładasz je na właściwą kupkę, razem z innymi kamykami z taką samą liczbą. Po godzinie pracy masz już kilkadziesiąt kupek z kamykami o tych samych wartościach, pozostało je przełożyć na nową, bardziej wytrzymałą półkę. Najpierw układasz wszystkie kamyki z liczbą jeden. Następnie układasz te z liczbą dwa. Teraz przyszła pora na trzecią kupkę: kamyki z liczbą pięć (niestety, liczb trzy i cztery nie ma w Twojej kolekcji). Tak układasz swoje kamyki, kupka po kupce przekładając je na półkę. W ten sposób zastosowałeś algorytm **sortowania przez zliczanie**

{% hint style="warning" %}
W tym algorytmie bardzo ważne jest, by znać **zakres wartości**, które będziemy sortować. Założymy, że będziemy sortować wartości od $$0$$ do $$m$$, a samo $$m$$ będzie wartością podaną w danych wejściowych do naszego algorytmu.
{% endhint %}

Poniżej znajdziesz animację przedstawiającą ideę omawianego algorytmu.

## Animacja

{% embed url="https://www.cs.usfca.edu/~galles/visualization/CountingSort.html" %}

## Rozwiązanie

Sortowanie przez zliczanie składa się z dwóch faz: fazy zliczania i fazy sortowania. Na początku potrzebujemy stworzyć miejsce, w którym będziemy zliczać liczebności poszczególnych wartości z tablicy. Tworzymy więc nową tablicę, tablicę liczników, którą na początku wypełnimy samymi zerami. Potrzebujemy mieć po jednym liczniku na każdą z możliwych wartości od $$1$$ do $$m$$.

Następnie przechodzimy przez kolejne elementy naszej tablicy i zwiększamy licznik dla każdej napotkanej wartości. Po zliczeniu wszystkich elementów pozostało nam je ponownie ułożyć w tablicy, teraz już we właściwej kolejności. Przechodzimy więc przez tablicę liczników i zapisujemy elementy do naszej tablicy $$A$$. Daną wartość zapisujemy tyle razy, ile wskazuje jej licznik.

### Pseudokod

```
procedura SortowaniePrzezZliczanie(A, n, m):
    1. liczniki := tablica [0..m] wypełniona zerami
    2. Od i := 1 do n, wykonuj:
        3. liczniki[A[i]] := liczniki[A[i]] + 1

    4. pozycja := 1
    5. Od i := 1 do m, wykonuj:
        6. Od j := 1 do liczniki[i], wykonuj:
            7. A[pozycja] := i
            8. pozycja := pozycja + 1  

    9. Zwróc A
```

### Złożoność

$$O(n+m)$$ — liniowa

Mamy tutaj do czynienia z dwoma liniowymi przejściami. Najpierw przechodzimy raz przez całą tablicę, co daje nam $$n$$ operacji. Następnie przechodzimy przez cały zakres wartości z tablicy, co daje nam $$m$$ operacji. Sumujemy i dostajemy złożoność liniową.

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/sorting/counting-sort.md" %}
[counting-sort.md](../../programming/c++/algorithms/sorting/counting-sort.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/sorting/counting-sort.md" %}
[counting-sort.md](../../programming/python/algorithms/sorting/counting-sort.md)
{% endcontent-ref %}

### Blockly

{% content-ref url="../../programming/blockly/algorithms/sorting/counting-sort.md" %}
[counting-sort.md](../../programming/blockly/algorithms/sorting/counting-sort.md)
{% endcontent-ref %}

### Kotlin

{% content-ref url="../../programming/kotlin/algorithms/sorting/counting-sort.md" %}
[counting-sort.md](../../programming/kotlin/algorithms/sorting/counting-sort.md)
{% endcontent-ref %}