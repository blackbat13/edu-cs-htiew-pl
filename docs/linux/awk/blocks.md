# Bloki

### Przykład 1

```awk
#!/usr/bin/awk -f

# Blok operacji poczatkowych
BEGIN {
   print "*****Poczatek Pliku******"
}

# Blok operacji biezacych (wykonywanych na kazdej linii tekstu)
{
   print $0 
}

# Blok operacji koncowych
END {
   print "*****Koniec Pliku*****"
}
```

### Przykład 2

```awk
#!/usr/bin/awk -f

# Blok operacji poczatkowych
BEGIN {
   OFS="\t"
   print "username IP"
}

# Blok operacji biezacych (wykonywanych na kazdej linii tekstu)
{
   print $1,$5 
}

# Blok operacji koncowych
END {
   print "*****Koniec Pliku*****"
}
```

### Przykład 3

```awk
#!/usr/bin/awk -f

# Skrypt zliczajacy liczbe osob zalogowanych na serwerze / liczbe linii w pliku wejsciowym

# Blok operacji poczatkowych
BEGIN {
   print "username IP"
   # Tworzymy nowa zmienna: licznik wszystkich linii
   licznik=0
}

# Blok operacji biezacych (wykonywanych na kazdej linii tekstu)
{
   print $1,$5

   # Zwiekszamy licznik o 1 dla kazdej przetworzonej linii
   licznik++
}

# Blok operacji koncowych
END {
   print "\n\nLiczba osob zalogowanych: " licznik
}
```

### Przykład 4

```awk
#!/usr/bin/awk -f

# Skrypt zliczajacy liczbe osob zalogowanych na serwerze / liczbe linii w pliku wejsciowym
# Skrypt numeruje kazda linie

# Blok operacji poczatkowych
BEGIN {
   print "username IP"
   # Tworzymy nowa zmienna: licznik wszystkich linii
   licznik=0
}

# Blok operacji biezacych (wykonywanych na kazdej linii tekstu)
{
   # Zwiekszamy licznik o 1 dla kazdej przetworzonej linii
   licznik++

   print licznik ": " $1,$5
}

# Blok operacji koncowych
END {
   print "\n\nLiczba osob zalogowanych: " licznik
}
```