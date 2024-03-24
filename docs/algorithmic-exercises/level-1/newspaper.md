# Gazeta

Gazeta "Bitek" z Bajtkowa jest niezwykle popularna, nawet w swoim tradycyjnym, papierowym formacie. W związku z tym wiele osób przesyła do redakcji swoje ogłoszenia, które mają zostać umieszczone w następnym wydaniu. Do tej pory stawka była prosta: stała opłata za każde ogłoszenie, zależna od liczby znaków. Wydawca "Bitek" zauważył jednak, że różne znaki zużywają różne ilości tuszu, co oznacza, że koszty druku dla każdego z nich również są różne! Dlatego postanowił zaktualizować cennik i ustalić koszt druku każdego znaku. Teraz opłata za ogłoszenie jest równa sumie kosztów wszystkich znaków zawartych w danym ogłoszeniu.

Twoje zadanie polega na obliczeniu, ile wyniesie opłata za określone ogłoszenie według nowego cennika.

Źródło: [https://onlinejudge.org/external/113/11340.pdf](https://onlinejudge.org/external/113/11340.pdf)

## Specyfikacja

### Dane

* $$n$$ - liczba znaków
* $$(z_1, c_1), (z_2, c_2), ..., (z_n, c_n)$$ - cennik: pary znak oraz cena znaku, podana w groszach
* $$wyraz$$ - ciąg znaków, małych i/lub wielkich liter alfabetu angielskiego, bez spacji i innych białych znaków

### Wynik

* Opłata za $$wyraz$$, podana w złotówkach, wedle nowego cennika. Zakładamy, że każdy znak z wyrazu pojawi się w cenniku.

## Przykład

### Dane

```
6
a 5
l 25
m 30
k 50
o 10
t 1
alamakota
```

### Wynik

```
1.36
```

{% hint style="info" %}
#### Wyjaśnienie

W wyrazie **alamakota** możemy wyróżnić:

* $$4$$ litery **a**
* $$1$$ literę **l**
* $$1$$ literę **m**
* $$1$$ literę **k**
* $$1$$ literę **o**
* $$1$$ literę **t**

Daje nam to: $$4*5+1*25+1*30+1*50+1*10+1*1=136$$ groszy, czyli $$1.36$$ złoty.
{% endhint %}
