# Wyszukiwanie minimum i maksimum

## [Opis problemu](../../../../algorithms/searching/min-or-max.md)


## Wyszukiwanie wartości minimum i maksimum

### Implementacja

```haskell linenums="1"
findMin [element] = element
findMin (element:rest) = min element (findMin rest)

findMax [element] = element
findMax (element:rest) = max element (findMax rest)

main = do
  let lst = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]

  let minValue = findMin lst
  let maxValue = findMax lst

  putStrLn $ "Min: " ++ show minValue
  putStrLn $ "Max: " ++ show maxValue
```


### Opis implementacji

Obie funkcje działają na podobnym mechanizmie, ale z różnym celem: `findMin` szuka najmniejszej wartości, a `findMax` największej. W przypadku, gdy lista zawiera tylko jeden element, funkcja zwraca ten element, ponieważ nie ma z czym go porównywać. Jednak gdy lista ma więcej elementów, funkcje wykorzystują podejście rekurencyjne. Porównują pierwszy element listy z wynikiem, który otrzymują, wywołując się rekurencyjnie na pozostałej części listy. Dla `findMin`, wybierają mniejszą wartość, natomiast dla `findMax` - większą.

W sekcji `main`, definiujemy listę `lst`, która zawiera zestaw liczb całkowitych. Następnie, aby znaleźć wartość minimalną i maksymalną na tej liście, stosujemy nasze funkcje `findMin` i `findMax`. Po znalezieniu tych wartości, wyniki są prezentowane użytkownikowi za pomocą prostego wydruku tekstowego.
