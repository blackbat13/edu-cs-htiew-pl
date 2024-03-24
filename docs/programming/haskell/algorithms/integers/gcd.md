---
description: Największy Wspólny Dzielnik
---

# NWD

## Opis problemu

{% content-ref url="../../../../algorithms/integers/gcd.md" %}
[gcd.md](../../../../algorithms/integers/gcd.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```haskell
gcdModulo a b
  | b == 0 = a
  | otherwise = gcdModulo b (a `mod` b)

main = do
    print $ gcdModulo 32 12
```
{% endcode %}

## Opis

Funkcja `gcdModulo` przyjmuje dwa argumenty: liczby `a` i `b`, dla których ma zostać obliczony NWD.

1. **Warunek bazowy:** jeśli druga liczba (`b`) jest równa 0, to pierwsza liczba (`a`) jest wynikiem, ponieważ NWD liczby i zera to liczba.
2. **Rekurencyjne wywołanie:** w przeciwnym przypadku, funkcja jest wywoływana rekurencyjnie z `b` jako pierwszym argumentem, a resztą z dzielenia `a` przez `b` (``a `mod` b``) jako drugim. Jest to kluczowy krok algorytmu Euklidesa, który polega na redukowaniu problemu do coraz mniejszych par liczb.

W głównym programie (`main`) wywołujemy funkcję `gcdModulo` z konkretnymi liczbami, w tym przypadku 32 i 12. Wynik, czyli NWD tych liczb, jest następnie wyświetlany.
