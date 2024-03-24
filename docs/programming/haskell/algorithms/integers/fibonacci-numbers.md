# Liczby Fibonacciego

## Opis problemu

{% content-ref url="../../../../algorithms/integers/fibonacci-numbers.md" %}
[fibonacci-numbers.md](../../../../algorithms/integers/fibonacci-numbers.md)
{% endcontent-ref %}

## Podejście naiwne

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```haskell
fib 1 = 1
fib 2 = 1
fib n = fib (n-1) + fib (n-2)

main = do
    print $ fib 10
```
{% endcode %}

### Opis

Funkcja `fib` przyjmuje jeden argument: numer `n` w ciągu Fibonacciego, dla którego ma zostać obliczona wartość.

1. **Warunki bazowe:** funkcja definiuje wartości dla pierwszego (1) i drugiego (2) elementu ciągu jako 1. To niezbędne warunki bazowe dla rekurencji.
2. **Rekurencyjne wywołanie:** dla każdej wartości `n` większej niż 2, funkcja oblicza wartość wywołując się rekurencyjnie dwa razy: `fib (n-1)` i `fib (n-2)`, a następnie sumując otrzymane wyniki. To właśnie tworzy ciąg Fibonacciego.

W głównym programie (`main`) wywołujemy funkcję `fib` dla konkretnej wartości `n`, w tym przypadku 10. Wynik, czyli dziesiąty element ciągu Fibonacciego, jest następnie wyświetlany.

## Podejście dynamiczne

### Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```haskell
fib n = fibs !! (n - 1)
    where fibs = 1 : 1 : zipWith (+) fibs (tail fibs)

main = do
    print $ fib 10
```
{% endcode %}

### Opis

Funkcja `fib` przyjmuje jeden argument: numer `n` w ciągu Fibonacciego, dla którego ma zostać obliczona wartość.

1. **Wykorzystanie leniwych list:** funkcja definiuje nieskończoną listę `fibs`, która zawiera ciąg Fibonacciego. Lista jest tworzona za pomocą operatora `:` (cons) i funkcji `zipWith`, która sumuje kolejno elementy listy `fibs` i jej ogona (`tail fibs`). Dzięki leniwemu obliczaniu Haskell wyliczy tylko te elementy listy, które są faktycznie potrzebne.
2. **Dostęp do elementu ciągu:** główna funkcja `fib` dostaje dostęp do konkretnego elementu ciągu, korzystając z operatora `!!` i indeksując listę `fibs` (z uwzględnieniem, że Haskell używa indeksowania od zera, stąd `n - 1`).

W głównym programie (`main`) wywołujemy funkcję `fib` dla konkretnej wartości `n`, tutaj dla 10. Wynik, czyli dziesiąty element ciągu Fibonacciego, jest następnie wyświetlany.
