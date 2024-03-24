# Python

## Implementacja

```python
liczbaBierek = int(input())

bierki = [int(input()) for _ in range(liczbaBierek)]

bierki = sorted(bierki)

ogon = 0
glowa = 2
wynik = 0

while glowa < liczbaBierek:
    dlugosc = glowa - ogon + 1
    
    if dlugosc < 3:
        glowa += 1
        continue
    
    min1 = bierki[ogon]
    min2 = bierki[ogon + 1]
    mx = bierki[glowa]

    if min1 + min2 <= mx:
        ogon += 1
    else:
        if dlugosc > wynik:
            wynik = dlugosc

        glowa += 1

print(wynik)
```