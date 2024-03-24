# Python - rozwiązanie

{% code overflow="wrap" lineNumbers="true" %}
```python
dictionary = dict()

while True:
    line = input()
    if len(line) <= 1:
        break

    translation, word = line.split(" ")
    dictionary[word] = translation


while True:
    try:
        word = input()
    except EOFError:
        break

    if word not in dictionary:
        print("eh")
    else:
        print(dictionary[word])
```
{% endcode %}
