# Obsługa wejścia i wyjścia

## Wyjście

Wypisanie prostego komunikatu:

```python
print("Witaj Świecie!")
```

### Tekst formatowany

Gdy chcemy w komunikacie umieścić wartości zmiennych, najłatwiej jest to zrobić używając tekstu formatowanego.
W tym celu przed cudzysłowem umieszczamy literę `f`, a w samym tekście używamy nawiasów klamrowych w miejscach, gdzie chcemy wstawić wartości zmiennych.

#### Przykład

```python
temp = 10

print(f"Dzisiaj jest {temp} stopni Celsjusza")
```

### Formatowanie liczb rzeczywistych

Często wypisując liczbę rzeczywistą potrzebujemy zobaczyć określoną liczbę cyfr po przecinku. W tym celu możemy skorzystać z dodatkowych opcji tekstu formatowanego, podawanych po dwukropku po zmiennej zamkniętej w nawiasach klamrowych. Np. jeżeli chcemy wypisać liczbę rzeczywistą z dokładnością do dwóch miejsc po przecinku, to napiszemy `:.2f`. Kropka określa wartości po przecinku, $$2$$ to liczba cyfr, które chcemy wypisać, a *f* określa format rzeczywisty (*float*).

#### Przykład

```python
temp = 9.79347832

print(f"Dzisiaj jest {temp:.2f} stopni Celsjusza")
```

## Wejście

### Wczytanie tekstu

```python
name = input("Podaj swoje imie: ")
```

Jak widać na powyższym przykładzie, do wczytania tekstu od użytkownika służy funkcja `input()`. Do funkcji możemy przekazać opcjonalny parametr: tekst, jaki zostanie wyświetlony użytkownikowi. Jako wynik funkcja zwraca całą linię tekstu wczytaną z wejścia.

### Wczytanie liczby

Za pomocą funkcji `input()` możemy wczytać linię tekstu z konsoli. Jeżeli chcemy, aby użytkownik podał nam liczbę, to nie możemy tego co prawda wymusić, ale możemy przetworzyć wczytany tekst na liczbę za pomocą funkcji `int()`.

#### Przykład

```python
age = int(input("Podaj swój wiek: "))
```

### Wczytanie dwóch wyrazów z jednej linii

Za pomocą polecenia `input` wczytujemy całą linię tekstu. Jeżeli więc w linii podane będą dwa wyrazy rozdzielone spacją, to wczytamy je oba razem ze spacją w formie jednego tekstu. Zazwyczaj jednak chcemy mieć każdy wyraz zapisany w osobnej zmiennej. W tym celu możemy skorzystać z funkcji `split`, która dzieli tekst na fragmenty. Podział wykonywany jest na podstawie podanego ogranicznika tekstu. Domyślnym ogranicznikiem jest znak spacji.

#### Przykład 1

```python
w1, w2 = input("Podaj dwa wyrazy oddzielone spacją: ").split()
```

#### Przykład 2

```python
w1, w2 = input("Podaj dwa wyrazy oddzielone przecinkiem: ").split(",")
```

### Wczytanie dwóch liczb z jednej linii

Wczytanie dwóch wyrazów z jednej linii jest proste, co jednak gdy zamiast wyrazów mamy liczby? Wówczas musimy dokonać konwersji za pomocą odpowiedniej funkcji, np. `int`. Możemy to zrobić ręcznie, tzn. najpierw wczytać dwa wyrazy, a potem zamienić je na liczby. Istnieje jednak inny, zautomatyzowany sposób. Możemy skorzystać z funkcji `map`. Funkcja ta przyjmuje dwa argumenty: funkcję oraz zbiór, a jej efektem jest zastosowanie podanej funkcji na każdym elemencie podanego zbioru. Dzięki temu możemy zastosować funkcję `int` na każdym wczytanym wyrazie.

#### Przykład

```python
num1, num2 = map(int, input("Podaj dwie liczby całkowite oddzielone spacją: ").split())
```

### Wczytanie listy wyrazów z jednej linii

Nie zawsze wiemy, ile elementów będzie podanych w jednej linii, ale to żaden problem. Polecenie split zwraca nam listę wyrazów, z której możemy skorzystać.

#### Przykład

```python
words_list = input("Podaj wyrazy oddzielone spacją: ").split()
```

### Wczytanie listy liczb z jednej linii

Wczytanie listy liczb jest bardzo podobne do wczytania dwóch liczb z jednej linii. Tym razem jednak chcemy mieć listę. Polecenie `map` nie zwraca nam listy jako wynik, więc sami przekonwertujemy wynik polecenia na listę za pomocą funkcji `list`.

#### Przykład

```python
num_list = list(map(int, input("Podaj wyrazy oddzielone spacją: ").split()))
```
