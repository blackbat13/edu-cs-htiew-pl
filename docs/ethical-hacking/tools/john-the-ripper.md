# John the Ripper

John the Ripper, zwany również **JtR**, to jedno z najpopularniejszych narzędzi do łamania haseł. Używa różnych technik do łamania haseł, w tym ataków słownikowych (sprawdzanie haseł z listy), ataków brute force (sprawdzanie wszystkich możliwych kombinacji znaków) oraz ataków hybrydowych (mieszanina ataków słownikowych i brute force). Obsługuje wiele formatów haseł i jest dostępny dla wielu systemów operacyjnych, w tym Linux, Windows i MacOS. Narzędzie to jest często używane do odzyskiwania utraconych haseł i testowania ich siły.

{% embed url="https://www.openwall.com/john/" %}
John the Ripper
{% endembed %}

## Przykłady użycia

### Atak słownikowy

Atak słownikowy polega na próbie odgadnięcia hasła za pomocą słów z wcześniej przygotowanej listy (słownika). Poniższe polecenie uruchamia atak słownikowy na plik *hashes.txt* za pomocą słownika *dictionary.txt*:

```bash
john --format=descrypt --wordlist=dictionary.txt hashes.txt
```

### Atak brute force

Atak brute force polega na sprawdzeniu wszystkich możliwych kombinacji znaków. Poniższe polecenie uruchamia atak brute force na plik *hashes.txt*, sprawdzając wszystkie kombinacje małych liter alfabetu łacińskiego o długości do $$4$$ znaków:

```bash
john --format=descrypt --incremental=Lower hashes.txt
```

### Wyświetlanie wyników

Aby wyświetlić złamane hasła, używamy polecenia `--show`:

```bash
john --show hashes.txt
```
