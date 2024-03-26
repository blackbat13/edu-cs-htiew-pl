# Netcat

Netcat, często nazywane *scyzorykiem szwajcarskim* w dziedzinie sieci, to proste, ale niezwykle wszechstronne narzędzie używane do czytania i pisania danych przez połączenia sieciowe. Netcat jest w stanie tworzyć połączenia TCP lub UDP między dwoma komputerami i przesyłać dane między nimi.

Netcat oferuje wiele niezwykle przydatnych funkcji:

- Tworzenie serwerów i klientów TCP/UDP.
- Przesyłanie plików między maszynami.
- Skanowanie portów.
- Przekierowywanie portów.
- Tworzenie backdoorów i reverse shelli.
- Testowanie serwisów sieciowych.

## Przykłady użycia

### Tworzenie prostego serwera echo

Na jednym komputerze uruchom:

```bash
nc -l 1234
```

Na drugim komputerze połącz się z serwerem:

```bash
nc 192.168.1.100 1234
```

Teraz wszystko, co wpiszesz na jednym komputerze, zostanie przesłane do drugiego.

### Przesyłanie plików

Możesz użyć Netcat do przesyłania plików między komputerami. Na serwerze uruchom:

```bash
nc -l 1234 > file.txt
```

Na kliencie, aby przesłać plik, uruchom:

```bash
nc 192.168.1.100 1234 < file.txt
```

### Port scanning

Netcat może być używane do skanowania portów na zdalnej maszynie. Poniższe polecenie skanuje porty od 20 do 80 na zdalnym hostie:

```bash
nc -zv 192.168.1.100 20-80
```

## Ściąga

[Ściąga](https://cdn.comparitech.com/wp-content/uploads/2019/07/netcat-Cheat-Sheet.pdf)
