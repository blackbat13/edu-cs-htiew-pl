# Wydajność

## Tworzenie listy

Przyjrzyjmy się trzem poniższym sposobom na utworzenie listy liczb całkowitych od $0$ do $n-1$.

**Sposób 1**

```python
tab = []
for i in range(n):
    tab.append(i)
```

**Sposób 2**

```python
tab = [i for i in range(n)]
```

**Sposób 3**

```python
tab = list(range(n))
```

Pierwszy sposób, korzystający z metody *append*, jest najwolniejszym spośród trzech przedstawionych. Drugi sposób, korzystający z tzw. *list comprehension*, jest ok. dwukrotnie szybszy od pierwszego sposobu. Natomiast ostatni, trzeci sposób, w którym konwertujemy na listę wynik funkcji *range*, jest ok. dwukrotnie szybszy od drugiego sposobu i ok. czterokrotnie szybszy od pierwszego sposobu.

Poniżej możemy zobaczyć i przetestować program mierzący średni czas wykonania powyższych metod dla $n=100000$.

[Tworzenie listy - wydajność](https://replit.com/@damiankurpiewski/CreatingListPerformance#main.py)
