# Schemat Hornera

## Opis problemu

{% content-ref url="../../../../algorithms/numerical-methods/horner.md" %}
[horner.md](../../../../algorithms/numerical-methods/horner.md)
{% endcontent-ref %}

## Implementacja

```python
def horner_polynomial(coef: [], x: float, n: float) -> float:
    """
    Computes value of the n-th degree polynomial for the given coefficients 
    and x value using Horner method
    
    :param coef: list of n+1 coefficients, where coef[i] is coefficient for the x^i
    :param x:
    :param n: degree of the polynomial
    
    :return: value of the polynomial
    """
    result = 0
    for i in range(n, -1, -1):
        result *= x
        result += coef[i]
        
    return result


def print_polynomial(coef: [], n: int):
    """
    Prints given polynomial
    
    :param coef: array of n+1 coefficients, where coef[i] is coefficient for the x^i
    :param n: degree of the polynomial
    """
    print(f"f(x) = {coef[0]}", end = "")
    for i  in range(1, n+1):
        print(f" + {coef[i]}x^i", end="") 
    
    print()


coef = [1, 2, 3]
x = 2
n = 2

print_polynomial(coef, n)
result = horner_polynomial(coef, x, n)
print(f"f({x}) = {result}")
```

### Link do implementacji

{% embed url="https://ideone.com/6PEgGA" %}
Obliczanie wartości wielomianu za pomocą schematu Hornera
{% endembed %}

### Opis implementacji

Zacznijmy od funkcji pomocniczej `print_polynomial` (**linia 20**), której celem jest wyświetlenie wielomianu w czytelnej formie na ekranie. Nie jest ona niezbędną częścią algorytmu, ale może być pomocna przy weryfikacji poprawności wyniku. Funkcja przyjmuje dwa parametry: listę współczynników wielomianu `coef`, oraz stopień wielomianu `n`. W tablicy znajduje się dokładnie $$n+1$$** **liczb. Współczynniki są zapisane w kolejności od najmniejszej potęgi ( $$0$$ ) do największej ( $$n$$ ).

Na początku funkcji wypisujemy pierwszy współczynnik (**linia 27**). Następnie przechodzimy pętlą przez kolejne elementy tablicy (**linia 28**), wypisując współczynnik przy $$i$$-tej potędze przemnożony przez $$x$$ podniesione do potęgi $$i$$.  Dbając o czytelność reprezentacji podajemy przy funkcji `print` opcjonalny argument `end`, dzięki czemu możemy zastąpić domyślny koniec linii dowolnym znakiem (w tym wypadku znakiem pustym), dzięki czemu kolejne wywołania funkcji `print` będą wyświetlać tekst w tej samej linii.

Przejdźmy teraz do właściwej implementacji algorytmu obliczania wartości wielomianu za pomocą schematu Hornera, czyli do funkcji `horner_polynomial` (**linia 1**). Funkcja ta przyjmuje podobne parametry jak pomocnicza funkcja `print_polynomial`, ale ponadto przyjmuje także wartość $$x$$, którą mamy przyjąć podczas obliczeń. Współczynniki i stopień wielomianu podane są w takiej samej formie jak wcześniej.

Na początku tworzymy zmienną `result`, w której będziemy zapisywać wyniki obliczeń, i przypisujemy jej wartość $$0$$ (**linia 12**). Następnie przechodzimy pętlą przez kolejne współczynniki wielomianu, poczynając od współczynnika przy najwyższej potędze (**linia 13**). Zauważ, że korzystamy tutaj z pętli malejącej, dlatego konieczne jest podanie trzeciego argumentu funkcji `range` - **kroku pętli**, który w tym wypadku jest ujemny. W pętli wykonujemy dwie operacje: przemnażamy wynik dotychczasowych obliczeń przez wartość `x` **(linia 14**), a następnie dodajemy do wyniku wartość kolejnego współczynnika (**linia 15**). Po przejściu przez wszystkie współczynniki wystarczy zwrócić wynik obliczeń (**linia 17**).

W części głównej definiujemy wartości parametrów naszych obliczeń (**linie 34-36**), wypisujemy wielomian w czytelnej formie korzystając z pomocniczej funkcji `print_polynomial` (**linia 38**), obliczamy wartość wielomianu za pomocą funkcji `horner_polynomial` (**linia 39**) i wypisujemy wynik na ekranie (**linia 40**).
