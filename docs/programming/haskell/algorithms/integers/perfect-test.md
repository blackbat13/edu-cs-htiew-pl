# Test doskonałości

## [Opis problemu](../../../../algorithms/integers/perfect-test.md)

## Implementacja

```haskell linenums="1"
isPerfect n = sum ([x | x <- [1..sqrtN], n `mod` x == 0] ++ [n `div` x | x <- [sqrtN, sqrtN - 1 .. 2], (n `mod` x == 0) && (n `div` x /= x)]) == n
  where
    sqrtN = floor $ sqrt $ fromIntegral n

main = do
    let n = 6

    print $ isPerfect n
```

## Opis

Funkcja `isPerfect` przyjmuje jeden argument: liczbę `n`, którą chcemy sprawdzić pod kątem bycia liczbą doskonałą.

1. **Generowanie dzielników:** najpierw funkcja generuje listę dzielników `n`, wykorzystując dwa wyrażenia list składanych. Pierwsze z nich znajduje dzielniki od 1 do pierwiastka kwadratowego z `n`, a drugie od pierwiastka kwadratowego do 2, z dodatkowym warunkiem eliminującym powtórzenia i wyłączającym samą liczbę `n`.
2. **Sumowanie dzielników:** następnie obliczana jest suma tych dzielników za pomocą funkcji `sum`.
3. **Porównanie z liczbą `n`:** funkcja sprawdza, czy suma dzielników jest równa liczbie `n`. Jeśli tak, oznacza to, że `n` jest liczbą doskonałą i funkcja zwraca `True`. W przeciwnym razie zwraca `False`.

W części `main` programu, definiujemy liczbę `n` (w tym przypadku 6) i sprawdzamy za pomocą funkcji `isPerfect`, czy jest to liczba doskonała. Wynik jest wyświetlany, informując, czy `n` spełnia kryteria liczby doskonałej.
