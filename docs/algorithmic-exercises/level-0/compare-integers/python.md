# Python

```python linenums="1"
a = int(input("Podaj a: "))
b = int(input("Podaj b: "))

if a == b:
    print("=")
elif a < b:
    print("<")
else:
    print(">")
```

## Opis

Na początku wczytujemy dwie wartości od użytkownika (**linie 1 i 2**). Ponieważ spodziewamy się liczb całkowitych, to poza funkcją `input` do wczytania wartości używamy także funkcji `int` do zamiany wczytanych wartości (które są przechowywane w postaci ciągów znaków typu `string`) na liczby całkowite.

Następnie, korzystając z instrukcji warunkowej, sprawdzamy relację pomiędzy wczytanymi wartościami. Jeżeli wartości zmiennych `a` i `b` są sobie równe (**linia 4**) to wypisujemy znak równości (**linia 5**). W przeciwnym przypadku, jeżeli wartość zmiennej `a` jest mniejsza od wartości zmiennej `b` (**linia 6**), to wypisujemy znak mniejszości (**linia 7**). W przeciwnym przypadku (**linia 8**) wypisujemy znak większości (**linia 9**).

Zwróć uwagę na to, że w ostatniej części instrukcji warunkowej (**linia 8**), nie musimy już sprawdzać, czy wartość zmiennej `a` jest większa od wartości zmiennej `b`. Wynika to z poprzednich warunków. Jeżeli wartości zmiennych nie są sobie równe ani też `a` nie jest mniejsze od `b`, to wiemy, że `a` jest większe od `b`.
