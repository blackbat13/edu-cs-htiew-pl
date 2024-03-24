# Pętle

## Pętla iteracyjna for

W języku Perl mamy do dyspozycji standardową pętlę `for`, której składnia podobna jest do tej z języka C. Zaczynamy więc od inicjalizacji **licznika pętli**, następnie definiujemy **warunek pętli**, a na końcu określamy **krok pętli**.

### Przykład

```perl
#!/usr/bin/perl

@liczby = (1, 2, 3);

$rozmiar = @liczby;

for($i = 0; $i < $rozmiar; $i = $i + 1) {
	$el = @liczby[$i];
	print "$el\n";
}
```

## Pętla iteracyjna foreach

### Przykład

```perl
#!/usr/bin/perl

@liczby = (1, 2, 3);

# Petla przechodzi przez kazdy element tablicy
# Zmienna el przyjmuje wartosci kolejnych elementow
foreach $el (@liczby) {
	print "$el\n";
}	
```