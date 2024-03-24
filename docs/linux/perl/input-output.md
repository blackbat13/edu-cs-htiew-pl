# Obsługa wejścia/wyjścia

## Obsługa wyjścia

### Przykład 1

```perl
#!/usr/bin/perl

print "Hello World!\n";
```

### Przykład 2

```perl
#!/usr/bin/perl

# Tworzymy zmienna
$hello = "Hello World!";

# Wypisujemy wartosc zmiennej i znak nowej linii
print "$hello\n";

# \U - Upper - zmienia wszystkie litery z linii na drukowane
$hello = "\UHello World!";

print "$hello\n";

# \E - End - konczy dzialanie \U
$hello = "\UHello\E World!";

print "$hello\n";
```