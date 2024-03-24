# Tablice

W języku Perl zmienne tablicowe podczas ich definiowania poprzedzamy znakiem @, zamiast znaku dolara jak przy standardowych zmiennych.
Zawartość tablicy definiujemy za pomocą nawiasów okrągłych.
Elementy tablicy indeksowane są od zera, a do poszczególnych elementów odwołujemy się korzystając z klasycznej notacji nawiasów kwadratowych.

### Przykład

```perl
#!/usr/bin/perl

@liczby = (1, 2, 3);

print "$liczby[0]\n";
print "$liczby[1]\n";
print "$liczby[2]\n";

$rozmiar = @liczby;

print "Rozmiar tablicy: $rozmiar\n";
```