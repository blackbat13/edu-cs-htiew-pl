# Pliki

## Czytanie plików

### Przykład

```bash
#!/bin/bash

wynik=`cat wynik.txt`
echo "$wynik"
```

## Pisanie do plików

### Przykład

```bash
#!/bin/bash

plik=wynik.txt

# Przekierowujemy wynik polecenia ls do pliku
ls -la> $plik

cat $plik
```