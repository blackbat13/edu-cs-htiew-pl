# Ćwiczenie 5

Zapoznaj się z poniższą specyfikacją oraz pseudokodem, a następnie rozwiąż zadania.

## Specyfikacja

### Dane

* $a$ - liczba rzeczywista
* $n$ - liczba naturalna, $n \neq 0$ 

### Wynik

* Liczba rzeczywista $p=a^n$ 

## Pseudokod

```
1. p := 1
2. b := a
3. Dopóki n > 0, wykonuj:
    4. Jeżeli n mod 2 = 1, to
        5. p := p * b
    6. b := b * b
    7. n := n div 2
```

## Zadanie 1

Przeanalizuj powyższy algorytm i uzupełnij poniższą tabelę wartościami zmiennych $p$, $b$ oraz $n$ po kolejnych wykonaniach kroku **3** dla dowolnej początkowej wartości $a$ oraz początkowej wartości zmiennej $n$ równej $12$.

|  p  |     b    |  n  |
| :-: | :------: | :-: |
|  1  |     a    |  12 |
|  1  | $a^2$  |     |
|     |          |     |
|     |          |     |
|     |          |     |

## Zadanie 2

Uzupełnij poniższą tabelę wpisując liczby **wszystkich mnożeń** wykonywanych przez powyższy algorytm dla podanych wartości $n$, tzn. liczby wykonanych instrukcji `p:=p*b` i `b:=b*b`

| `n` | liczba mnożeń |
| :-: | :-----------: |
|  2  |               |
|  3  |               |
|  4  |               |
|  5  |               |
|  6  |               |
|  7  |               |

## Zadanie 3

Jaka jest złożoność powyższego algorytmu?
