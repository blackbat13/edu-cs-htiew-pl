# Rozwiązania

## Zadanie 1

TODO

## Zadanie 2

TODO

## Zadanie 3

TODO

## Zadanie 4

### 4.1

{% tabs %}

{% tab title="Python" %} 

{% code overflow="wrap" lineNumbers="true" %}
```python
with open("liczby.txt") as input_file:
  input_list = input_file.read().split()

result = 0
first = ""

for el in input_list:
  if el[0] == el[-1]:
    result += 1
    if first == "":
      first = el

print(result, first)
```
{% endcode %}

{% endtab %}

{% endtabs %}

### 4.2

{% tabs %}

{% tab title="Python" %} 

{% code overflow="wrap" lineNumbers="true" %}
```python
def compute_prime_factors(number):
  prime = 2
  result = []
  while number > 1:
    if number % prime == 0:
      number //= prime
      result.append(prime)
    else:
      prime += 1

  return result


with open("liczby.txt") as input_file:
  numbers_list = list(map(int, input_file.read().split()))

max_prime_factors = 0
max_prime_factors_number = 0

max_unique_prime_factors = 0
max_unique_prime_factors_number = 0

for number in numbers_list:
  prime_factors_list = compute_prime_factors(number)
  prime_factors_set = set(prime_factors_list)

  prime_factors_count = len(prime_factors_list)
  unique_prime_factors_count = len(prime_factors_set)

  if prime_factors_count > max_prime_factors:
    max_prime_factors = prime_factors_count
    max_prime_factors_number = number

  if unique_prime_factors_count > max_unique_prime_factors:
    max_unique_prime_factors = unique_prime_factors_count
    max_unique_prime_factors_number = number

print(max_prime_factors_number, max_prime_factors, max_unique_prime_factors_number, max_unique_prime_factors)
```
{% endcode %}

{% endtab %}

{% endtabs %}

### 4.3

TODO

## Zadanie 5

TODO

## Zadanie 6

TODO
