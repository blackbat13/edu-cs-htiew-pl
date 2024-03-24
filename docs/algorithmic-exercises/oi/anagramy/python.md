# Python

## Implementacja

```python
anagrams = dict()
anagramsSorted = dict()

n = int(input())

for i in range(n):
    word = input()
    wordSorted = "".join(sorted(word))

    if wordSorted in anagrams:
        anagrams[wordSorted].add(word)
    else:
        anagrams[wordSorted] = {word}

for key in anagrams:
    valueSorted = sorted(anagrams[key])
    anagramsSorted[valueSorted[0]] = valueSorted

for key in sorted(anagramsSorted):
    for word in anagramsSorted[key]:
        print(word, end = " ")

    print()
```