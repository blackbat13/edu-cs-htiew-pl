# Rozkład na czynniki pierwsze

## Opis problemu

{% content-ref url="../../../../algorithms/integers/prime-factors.md" %}
[prime-factors.md](../../../../algorithms/integers/prime-factors.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```haskell
primeFactors n i
  | i > n = []
  | n `mod` i == 0 = i : primeFactors (n `div` i) i
  | otherwise = primeFactors n (i + 1)

main = do
    let n = 18

    print $ primeFactors n 2
```
{% endcode %}

### Opis

Funkcja `primeFactors` przyjmuje dwa argumenty: liczbę `n`, której czynniki pierwsze chcemy znaleźć, oraz początkowy dzielnik `i`, zaczynając od 2.

1. **Warunek końca:** jeśli `i` jest większe niż `n`, oznacza to, że wszystkie możliwe czynniki pierwsze zostały już znalezione, więc funkcja zwraca pustą listę.
2. **Znalezienie czynnika pierwszego:** jeśli `n` dzieli się bez reszty przez `i` (``n `mod` i == 0``), to `i` jest jednym z czynników pierwszych `n`. W takim przypadku, `i` jest dodawane do listy wynikowej, a funkcja jest rekurencyjnie wywoływana dla `n `div` i`, aby znaleźć pozostałe czynniki.
3. **Przejście do kolejnego dzielnika:** jeśli `n` nie dzieli się przez `i`, funkcja jest wywoływana rekurencyjnie z inkrementowanym `i` (`i + 1`), aby sprawdzić kolejne potencjalne czynniki.

W głównym programie (`main`) definiujemy liczbę `n` (w tym przypadku 18) i wywołujemy funkcję `primeFactors`, aby znaleźć jej czynniki pierwsze. Wynik, który jest listą czynników pierwszych liczby `n`, jest następnie wyświetlany.
