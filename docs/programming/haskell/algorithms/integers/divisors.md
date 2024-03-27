# Wszystkie dzielniki

## [Opis problemu](../../../../algorithms/integers/divisors.md)

## Implementacja

```haskell linenums="1"
divisors n = [x | x <- [1..sqrtN], n `mod` x == 0] ++ [n `div` x | x <- [sqrtN, sqrtN - 1 .. 1], (n `mod` x == 0) && (n `div` x /= x)]
  where
    sqrtN = floor $ sqrt $ fromIntegral n

main = do
    let n = 16

    print $ divisors n
```

## Opis

Funkcja `divisors` przyjmuje jeden argument: liczbę `n`, dla której chcemy znaleźć dzielniki.

1. **Znalezienie dzielników:** w pierwszej części funkcji, generowana jest lista dzielników `n` od 1 do pierwiastka kwadratowego z `n`. Używane jest tutaj wyrażenie list składanych, które sprawdza, czy `n` dzieli się przez `x` bez reszty (``n `mod` x == 0``).
2. **Komplementarne dzielniki:** w drugiej części, funkcja znajduje dzielniki `n` będące wynikiem dzielenia `n` przez `x` w odwrotnym zakresie, od pierwiastka kwadratowego z `n` do 1. Dodatkowo, warunek ``(n `div` x /= x)`` zapobiega powtórzeniom, gdy `n` jest kwadratem jakiejś liczby naturalnej.
3. **Połączenie wyników:** wyniki obu części są łączone za pomocą operatora `++`, tworząc pełną listę dzielników `n`.

Kluczowym aspektem tej funkcji jest jej optymalizacja. Poprzez ograniczenie wyszukiwania do pierwiastka kwadratowego liczby `n`, znacznie redukuje się ilość wymaganych obliczeń. Jest to standardowa technika w algorytmach związanych z dzielnikami, która znacząco zwiększa ich wydajność.

W części `main` programu, definiujemy liczbę `n` (w tym przykładzie 16) i używamy funkcji `divisors`, aby znaleźć jej dzielniki. Następnie lista dzielników jest wyświetlana.
