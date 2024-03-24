# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wypisanie komunikatu powinno zostać zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$imie$$ - ciąg znaków, małych i wielkich liter alfabetu angielskiego

#### Wynik

* Komunikat powitania w formie "_Witaj \[**imie**]!_", np. "_Witaj Damian!_"

## Rozwiązanie

```python
def powitanie(imie: str):
    print(f"Witaj {imie}!")


imie = input("Podaj swoje imię: ")

powitanie(imie)
```