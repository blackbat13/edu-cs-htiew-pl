# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$rok$$ - liczba naturalna

#### Wynik

* Komunikat określający, czy podany rok jest przestępny czy też nie

## Rozwiązanie

```python
rok = int(input("Podaj rok: "))

if (rok % 4 == 0 and rok % 100 != 0) or rok % 400 == 0:
    print(f"{rok} jest przestępny")
else:
    print(f"{rok} nie jest przestępny")
```
