# Hashcat

Hashcat jest jednym z najpotężniejszych narzędzi do łamania haseł dostępnych na rynku. Umożliwia przeprowadzanie bardzo szybkich operacji ataku na hasła, wykorzystując moc obliczeniową procesorów CPU, jak również GPU. Obsługuje wiele różnych typów algorytmów hashujących, takich jak MD5, SHA1, SHA256, SHA512, NTLM i wiele innych.

Hashcat dokonuje tzw. ataku siłowego lub ataku słownikowego na hasła, próbując odgadnąć je na podstawie dostarczonych mu danych wejściowych. Może to zrobić na wiele różnych sposobów, w tym:

- **Brute force**: próbuje wszystkich możliwych kombinacji znaków.
- **Atak słownikowy**: próbuje haseł z wcześniej przygotowanej listy (np. z popularnych haseł).
- **Atak maskowy**: próbuje haseł na podstawie określonego wzorca.
- **Atak hybrydowy**: kombinacja powyższych technik.

{% embed url="https://hashcat.net/hashcat/" %}
Hashcat
{% endembed %}

## Przykłady użycia

### Atak słownikowy

Poniższe polecenie wykonuje atak słownikowy na hash MD5:

```bash
hashcat -m 0 -a 0 hash.txt dictionary.txt
```

W tym przypadku `-m 0` oznacza, że używamy algorytmu **MD5**, `-a 0` oznacza atak słownikowy. `hash.txt` to plik z hashem do złamania, a `dictionary.txt` to plik ze słownikiem haseł.

### Atak siłowy

Poniższe polecenie wykonuje atak siłowy na hash MD5, próbując wszystkich kombinacji małych liter i cyfr o długości do $$5$$ znaków:

```bash
hashcat -m 0 -a 3 hash.txt ?l?d?d?d?d
```

Tutaj `-a 3` oznacza atak siłowy, a `?l?d?d?d?d` to maska określająca próbowane kombinacje.

### Atak hybrydowy

Poniższe polecenie wykonuje atak hybrydowy, korzystając z listy słów i dodając do każdego słowa od jednej do dwóch cyfr:

```bash
hashcat -m 0 -a 6 hash.txt dictionary.txt ?d?d
```
