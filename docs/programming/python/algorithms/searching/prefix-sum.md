# Sumy prefiksowe

## [Opis problemu](../../../../algorithms/searching/prefix-sum.md)

## Implementacja

```python linenums="1"
def compute_prefix_sum(numbers_list: list) -> list:
  prefix_sum_list = [0]
  for num in numbers_list:
    prefix_sum_list.append(prefix_sum_list[-1] + num)

  return prefix_sum_list

def answer_queries(numbers_list: list, queries_list: list):
  prefix_sum_list = compute_prefix_sum(numbers_list)
  for q_begin, q_end in queries_list:
    result = prefix_sum_list[q_end + 1] - prefix_sum_list[q_begin]
    print(f"sum({q_begin}:{q_end}) = {result}")

numbers_list = [8, 4, 1, 5, 8, 0, 12, 9, 26, 3]
queries_list = [(1, 5), (0, 3), (6, 9)]

answer_queries(numbers_list, queries_list)
```
