# Pakowanie na wakacje

Nadeszły wyczekiwane wakacje i planujesz wyjazd. Przed Tobą jednak wyzwanie spakowania się. Masz do dyspozycji jedną walizkę w kształcie prostopadłościanu o wymiarach $20cm\times20cm\times20cm$. Zdołałeś skompilować wszystkie niezbędne rzeczy w jeden mały pakunek, również o kształcie prostopadłościanu. Wobec tego, pytanie brzmi: czy zmieści się on w Twojej walizce? Zależy Ci na bezpieczeństwie rzeczy, więc pakunek nie może wystawać poza walizkę i musi być ułożony tak, aby jego boki były równoległe do boków walizki.

Źródło: [https://onlinejudge.org/external/123/12372.pdf](https://onlinejudge.org/external/123/12372.pdf)

## Specyfikacja

### Dane

* $a, b, c$ - liczby naturalne, wymiary pakunku, wszystkie z zakresu $[1, 50]$

### Wynik

* Komunikat "TAK", jeżeli pakunek zmieści się walizce, lub komunikat "NIE" w przeciwnym przypadku

## Przykład 1

### Dane

```
a := 20
b := 20
c := 20
```

**Wynik**: "TAK"

## Przykład 2

### Dane

```
a := 1
b := 2
c := 21
```

**Wynik**: "NIE"
