# Polecenia

W skryptach bash możemy wywoływać polecenia powłoki bash.
W tym celu wystarczy wpisać do skryptu zadane polecenie.
Możemy także przechwycić wynik polecenia i zapisać go w zmiennej.
Wówczas polecenie należy zapisać w apostrofach (znak pod tyldą).

### Przykład 1

```bash
#!/bin/bash

dzisiaj=`date`

echo $dzisiaj

miesiac=`date +%m`
echo "Miesiac: $miesiac"

rok=`date +%Y`
echo "Rok: $rok"

data=`date +%d-%m-%Y`
echo "Data: $data"

data2=`date '+%d %m %Y'`
echo "Data2: $data2"
```

### Przykład 2

```bash
#!/bin/bash

# Definiujemy polecenie, zapamietujemy w zmiennej
polecenie="ls -la"

# Wypisujemy tekst polecenia
echo $polecenie
echo

# Uruchamiamy polecenie, jego wynik zobaczymy w terminalu
$polecenie

wynik=`ls -la`

echo
echo "Wynik polecenia:"
echo $wynik
```