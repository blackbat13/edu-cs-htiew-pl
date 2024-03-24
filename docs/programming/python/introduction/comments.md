# Komentarze

Jak i w innych językach, także w języku Python możemy dodawać komentarze, zarówno klasyczne jak i dokumentacyjne.

## Jednolinijkowe

Komentarze jednolinijkowe w języku Python zaczynają się od znaku `#`

### Przykład

```python
# To jest komentarz
zmienna = 5  # To jest kolejny komentarz
```

## Wielolinijkowe

W języku Python nie ma typowych komentarzy wielolinijkowych.
Zamiast tego używamy wielu komentarzy jednolinijkowych.
Alternatywnie można skorzystać ze składni pozwalającej na tworzenie wielolinijkowych tekstów.
Jeżeli nie przypiszemy ich do żadnej zmiennej, ich wartość zostanie zignorowana, to znaczy potraktowana jak komentarz.

### Przykład

```python
"""
To jest tekst wielolinijkowy,
który może zostać potraktowany również jako komentarz.
"""
```

## Komentarze dokumentacyjne

W języku Python komentarze dokumentacyjne mogą być zarówno jednolinijkowe jak i wielolinijkowe. W obu przypadkach tworzymy je tak samo. To, co może odróżniać Python od innych języków to fakt, że dokumentując funkcję czy klasę, komentarze umieszczamy wewnątrz definicji, a nie przed nią.

Istnieje co najmniej kilka różnych formatów pisania dokumentacji. Jak to zwykle bywa, należy wybrać jeden i się go trzymać w całym projekcie.

### Przykład (format Sphinx)

```python
def add(a: int, b: int) -> int :
    """Computes sum of two integers.

    :param a: The first integer
    :param b: The second integer

    :returns: The sum of a and b
    """

    return a + b
```
