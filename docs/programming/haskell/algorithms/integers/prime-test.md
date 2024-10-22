# Test pierwszości

## [:link: Opis problemu](../../../../algorithms/integers/prime-test.md)

## Implementacja

```haskell linenums="1"
isPrime n
  | n < 2 = False
  | otherwise = not $ any (`divides` n) [2 .. sqrtN]
  where
    sqrtN = floor $ sqrt $ fromIntegral n

divides x n = n `mod` x == 0

main = do
    let n = 13

    print $ isPrime n
```

### Opis

Funkcja `isPrime` przyjmuje jeden argument: liczbę `n`, którą chcemy sprawdzić pod kątem bycia liczbą pierwszą.

1. **Sprawdzenie warunków wstępnych:** Najpierw funkcja sprawdza, czy `n` jest mniejsze niż 2. Liczby mniejsze niż 2 nie są liczbami pierwszymi, więc w takim przypadku funkcja zwraca `False`.
2. **Weryfikacja dzielników:** następnie, funkcja używa wyrażenia `any` w połączeniu z funkcją pomocniczą `divides`, aby sprawdzić, czy jakakolwiek liczba z zakresu od 2 do pierwiastka kwadratowego z `n` jest dzielnikiem `n`. Jeśli tak jest, to `n` nie jest liczbą pierwszą i funkcja zwraca `False`.
3. **Optymalizacja:** sprawdzanie dzielników jest ograniczone do pierwiastka kwadratowego z `n`, co jest znaczącą optymalizacją. Dzięki temu algorytm działa szybciej, nie tracąc na dokładności.

Definiujemy również pomocniczą funkcję `divides`, która przyjmuje dwa argumenty: `x` i `n`. Sprawdza ona, czy `x` jest dzielnikiem `n`, co jest realizowane przez sprawdzenie, czy reszta z dzielenia `n` przez `x` wynosi zero.

W części `main` programu, definiujemy liczbę `n` (w tym przypadku 13) i używamy funkcji `isPrime`, aby sprawdzić, czy jest to liczba pierwsza. Wynik jest następnie wyświetlany.

- Jeśli funkcja zwraca `True`, oznacza to, że `n` jest liczbą pierwszą.
- Jeśli funkcja zwraca `False`, liczba ta nie jest liczbą pierwszą.
