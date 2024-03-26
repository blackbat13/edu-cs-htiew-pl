# Pseudokod

```
1. Wczytaj a, b
2. Jeżeli a = b, to:
    3. Wypisz "="
4. W przeciwnym przypadku, jeżeli a < b, to:
    5. Wypisz "<"
6. W przeciwnym przypadku:
    7. Wypisz ">"
```

## Opis

Na początku wczytujemy dwie wartości od użytkownika (**krok 1**).

Następnie, korzystając z instrukcji warunkowej, sprawdzamy relację pomiędzy wczytanymi wartościami. Jeżeli wartości zmiennych `a` i `b` są sobie równe (**krok 2**) to wypisujemy znak równości (**krok 3**). W przeciwnym przypadku, jeżeli wartość zmiennej `a` jest mniejsza od wartości zmiennej `b` (**krok 4**), to wypisujemy znak mniejszości (**krok 5**). W przeciwnym przypadku (**krok 6**) wypisujemy znak większości (**krok 7**).

Zwróć uwagę na to, że w ostatniej części instrukcji warunkowej (**krok 6**), nie musimy już sprawdzać, czy wartość zmiennej `a` jest większa od wartości zmiennej `b`. Wynika to z poprzednich warunków. Jeżeli wartości zmiennych nie są sobie równe ani też `a` nie jest mniejsze od `b`, to wiemy, że `a` jest większe od `b`.
