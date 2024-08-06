# Suma dwóch liczb

## [:material-link: Opis problemu](../../../../algorithms/searching/sum-of-two.md)

## Rozwiązanie optymalne

### Implementacja

```haskell linenums="1"
sumOfTwo :: Int -> [Int] -> Int -> IO ()
sumOfTwo n tab sum = do
    let result = findPair 0 (n - 1) tab
    case result of
        Just (x, y) -> putStrLn $ show x ++ ", " ++ show y
        Nothing     -> putStrLn "-1"
  where
    findPair :: Int -> Int -> [Int] -> Maybe (Int, Int)
    findPair left right tab
        | left >= right = Nothing
        | tab !! left + tab !! right == sum = Just (tab !! left, tab !! right)
        | tab !! left + tab !! right < sum = findPair (left + 1) right tab
        | otherwise = findPair left (right - 1) tab

main :: IO ()
main = do
    let n = 10
    let tab = [1, 2, 4, 6, 8, 9, 10, 12, 13, 15]
    let sum = 18
    sumOfTwo n tab sum
```
