# Pliki

## Czytanie plików

### Przykład

```perl
#!/usr/bin/perl

# Skrypt otwiera plik tekstowy
# i wyswietla jego zawartosc na ekranie

# Podajemy scieke do pliku
$plik = "katalog.perl";

# Otwieramy plik do odczytu

open(WEJ, "<", $plik) or die "Nie mozna otworzyc pliku!";

# Czytamy plik linia po linii az do EOF (End Of File - koniec pliku)
while(<WEJ>) {
	# Wypisujemy przeczytana linie na ekranie
	print $_;
}

# Zamykamy plik
close(WEJ);

print "Koniec operacji na pliku\n";
```

## Pisanie do plików

### Przykład

```perl
#!/usr/bin/perl

# Skrypt zapisuje kilka liniii tekstu do pliku

# Podajemy sciezke do pliku
$plik = "wynik.txt";

# Otwieramy plik do zapisu
open(WYJ, ">", $plik) or die "Nie mozna otworzyc pliku!";

# Zapisujemy komunikaty do pliku
print WYJ "Ala ma kota\n";
print WYJ "a kot\n";
print WYJ "ma Ale\n";


# Zamykamy plik
close(WYJ);

print "Koniec operacji na pliku\n";
```

## Katalogi

### Przykład

```perl
#!/usr/bin/perl

# Skrypt wypisuje zawartosc katalogu domowego

# Zapisujemy sciezke do katalogu
# A takze wyrazenie, ktore okresla, jakie pliki nas interesuja
# * - chcemy wypisac wszystko
$dir = "~/*";

@pliki = glob($dir);

foreach $el (@pliki) {
	print "$el\n";
}
```