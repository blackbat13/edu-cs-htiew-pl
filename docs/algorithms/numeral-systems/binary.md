# System binarny

## Wstęp

System binarny, zwany także systemem dwójkowym, to podstawowy system liczbowy dla komputerów. Liczby w tym systemie reprezentujemy korzystając z dwóch cyfr: $$0$$ i $$1$$. Pozwala to na stosunkowo łatwą techniczną interpretację przesyłanych danych, np. niskie i wysokie napięcie.

## Konwersja z dziesiętnego na binarny

Konwersja z systemu dziesiętnego na binarny polega na dzieleniu całkowitym liczby przez $$2$$ i zapisywaniu reszt z dzielenia tak długo, aż jako wynik dzielenia otrzymamy $$0$$. Następnie otrzymane reszty z dzielenia odczytujemy od końca i w ten sposób otrzymujemy zapis binarny liczby naturalnej. W celu lepszego zrozumienia opisanej procedury przeanalizujmy poniższy przykład.

### Przykład

Chcemy przekonwertować liczbę $$25$$ na system binarny. Na początku dzielimy więc całkowicie $$25$$ przez $$2$$ otrzymując wynik $$12$$ i reszty $$1$$. Teraz dzielimy $$12$$ całkowicie przez $$2$$ otrzymując wynik $$6$$ i reszty $$0$$. Następnie dzielimy $$3$$ otrzymując wynik $$1$$ i reszty $$1$$. Na koniec pozostało nam podzielić $$1$$ co daje nam wynik $$0$$ i reszty $$1$$. Teraz możemy spisać reszty **od końca**: $$11001$$. W ten sposób otrzymaliśmy zapis binarny liczby $$25$$. 

Dla ułatwienia tworzymy sobie tabelkę, w której zapisujemy kolejne reszty i wyniki dzielenia.

| **div** | **mod** |
| :-----: | :-----: |
| $$25$$  |  $$1$$  |
| $$12$$  |  $$0$$  |
|  $$6$$  |  $$0$$  |
|  $$3$$  |  $$1$$  |
|  $$1$$  |  $$1$$  |
|  $$0$$  |         |

$$
25_{10}=11001_2
$$

### Algorytm

Opiszemy teraz bardziej formalnie algorytm konwersji liczb naturalnych z systemu dziesiętnego na binarny. Zacznijmy od specyfikacji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna.

#### Wynik

* Reprezentacja liczby $$n$$ w systemie binarnym.

### Pseudokod

```
Funkcja DziesietnyNaBinarny(n):
    1. binarna := ""
    2. Dopóki n > 0, wykonuj:
        3. reszta := n mod 2
        4. Dopisz reszta na początek binarna
        5. n := n div 2
    6. Zwróc binarna
```

## Konwersja z binarnego na dziesiętny

W systemie binarnym, podobnie jak w innych systemach, do każdej cyfry przypisana jest potęga podstawy systemu: w tym wypadku potęga liczby dwa. Ostatniej cyfrze (tzw. najmniej znaczącemu bitowi) przypisujemy potęgę zerową ($$2^0$$). Przedostatniej: pierwszą potęgę ($$2^1$$). Kolejnej: $$2^2$$ itd. W celu obliczenia wartości liczby binarnej w systemie dziesiętnym, każdą cyfrę przemnażamy przez przypisaną do niej potęgę dwójki i wynik sumujemy, tak jak pokazano na poniższym przykładzie.

### Przykład

$$
11001_2=1*2^4+1*2^3+0*2^2+0*2^1+1*2^0=2^4+2^3+2^0=16+8+1=25_{10}
$$
