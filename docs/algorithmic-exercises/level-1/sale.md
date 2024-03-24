# Promocja

W Topolandii mieszka farmer o imieniu Włodzimir, który zajmuje się sprzedażą mleka, pozyskiwanego od swoich zdrowych krów pasących się na bujnych łąkach tej krainy. Niedawno wprowadził specjalną promocję: za oddanie $$3$$ pustych butelek po mleku, otrzymujesz $$1$$ pełną butelkę mleka gratis! Ile butelek mleka jesteś w stanie skonsumować korzystając z tej promocji, jeżeli już zakupiłeś $$n$$ butelek mleka?

PS. Włodzimir z chęcią pożyczy Ci puste butelki, pod warunkiem, że potem je zwrócisz.

Źródło: [https://onlinejudge.org/external/111/11150.pdf](https://onlinejudge.org/external/111/11150.pdf)

## Specyfikacja

### Dane

* $$n$$ - liczba zakupionych butelek mleka z przedziału$$[1,200]$$

### Wynik

* Maksymalna liczba butelek mleka, które można wypić, korzystając z promocji.

## Przykład

### Dane

```
8
```

### Wynik

```
12
```

{% hint style="info" %}
#### Wyjaśnienie

Na początku mamy $$8$$ pełnych butelek mleka. Jeżeli pożyczymy jedną pustą butelkę, to możemy nasze $$9$$ pustych butelek wymienić na $$3$$ nowe. Wypijamy $$3$$ butelki mleka i wymieniamy je na jedną butelkę mleka. Wypijamy i ją, a na końcu oddajemy pustą butelkę. Wypiliśmy więc najpierw $$8$$, potem $$3$$ i na końcu $$1$$ butelkę mleka:

$$8+3+1=12$$
{% endhint %}
