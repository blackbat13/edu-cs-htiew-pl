# Sito Eratostenesa

## Opis problemu

Liczby pierwsze odgrywają ważną rolę nie tylko w matematyce, ale także w informatyce, szczególnie w kryptografii. Potrzebne są więc metody efektywnego obliczania liczb pierwszych, a najlepiej całego ich zbioru. Jedną z takich metod jest właśnie **Sito Eratostenesa**, które pozwala nam na wydajne obliczenie wszystkich liczb pierwszych mniejszych bądź równych zadanej wartości. Zapoznaj się z poniższą prezentacją by zrozumieć działanie tego algorytmu.

{% file src="../../.gitbook/assets/Sito Eratostenesa.pdf" %}
Sito Eratostenesa — prezentacja
{% endfile %}

### Specyfikacja

#### Dane

* $$n$$ — liczba całkowita

#### Wynik

* Wszystkie liczby pierwsze od $$1$$ do $$n$$ włącznie.

### Przykład

#### Dane

```
n := 10
```

#### Wynik

$$2, 3, 5, 7$$ 

## Rozwiązanie

Na początku potrzebujemy stworzyć tablicę, w której będziemy zapamiętywać, czy dana liczba jest pierwsza, czy też nie. W takim razie tworzymy $$n$$-elementową tablicę wartości prawda/fałsz. Początkowo wypełniamy całą tablicę wartościami *prawda*. Wiemy, że liczba $$1$$ nie jest liczbą pierwszą, więc odznaczamy ją w tablicy wartością *fałsz*. Następnie przechodzimy pętlą od liczby $$2$$ do $$n$$. Dla każdej wartości będziemy sprawdzać, czy ma ona w tablicy przypisaną wartość *prawda*, tzn. czy jest liczbą pierwszą. Jeżeli tak jest, to przechodzimy przez wszystkie kolejne wielokrotności tej liczby (aż do $$n$$) i odznaczamy je w tablicy jako *fałsz*.

Gdy już przejdziemy przez wszystkie wartości z zadanego zakresu, nasza tablica jest gotowa. Możemy ponownie przejść pętlą od $$2$$ do $$n$$ i wypisać wszystkie liczby, które w tablicy mają przypisaną wartość *prawda*, czyli wszystkie liczby pierwsze.

### Pseudokod

```
funkcja SitoEratostenesa(n):
    1. A[1..n] := tablica wypełniona wartościami true
    2. A[1] := false
    3. Od i := 2 do n wykonuj:
        4. Jeżeli A[i] = true, to:
            5. j := i * 2
            6. Dopóki j <= n, wykonuj:
                7. A[j] := false
                8. j := j + i
    9. Od i := 2 do n, wykonuj:
        10. Jeżeli A[i] = true, to:
            11. Wypisz i
```

### Złożoność

$$O(n\log{n})$$ — liniowo logarytmiczna

## Implementacja

### C++

{% content-ref url="../../programming/c++/algorithms/integers/eratosthenes-sieve.md" %}
[eratosthenes-sieve.md](../../programming/c++/algorithms/integers/eratosthenes-sieve.md)
{% endcontent-ref %}

### Python

{% content-ref url="../../programming/python/algorithms/integers/eratosthenes-sieve.md" %}
[eratosthenes-sieve.md](../../programming/python/algorithms/integers/eratosthenes-sieve.md)
{% endcontent-ref %}
