# Snort

Snort to darmowe narzędzie do wykrywania włamań (**IDS** - *Intrusion Detection System*) i zapobiegania włamaniom (**IPS** - *Intrusion Prevention System*), które jest powszechnie stosowane w środowiskach bezpieczeństwa sieciowego. Narzędzie to jest zdolne do przeprowadzania analizy ruchu sieciowego w czasie rzeczywistym oraz wykrywania różnych rodzajów ataków, takich jak ataki typu buffer overflow, stealth port scans, CGI ataki, SMB próbki, OS fingerprinting attempts i inne.

Snort jest systemem wykrywania i zapobiegania włamaniom w czasie rzeczywistym. Jest oparty na regułach, co oznacza, że działanie Snort jest sterowane zestawem reguł, które definiują, jakie działania mają być podejmowane w przypadku wykrycia określonego typu ruchu sieciowego.

Reguły Snort są bardzo konfigurowalne i umożliwiają definiowanie różnych typów alertów na podstawie różnych kryteriów, takich jak adresy IP, porty, typy pakietów i inne.

## Przykłady użycia

### Przechwytywanie i analiza ruchu sieciowego

Podstawowe użycie Snort polega na przechwytywaniu i analizie ruchu sieciowego. Poniższe polecenie uruchamia Snort w trybie przechwytywania i analizy pakietów na interfejsie eth0:

```bash
snort -i eth0 -c /etc/snort/snort.conf
```

Gdzie:

- `-i eth0` to interfejs, na którym Snort ma przechwytywać pakiety.
- `-c /etc/snort/snort.conf` to ścieżka do pliku konfiguracyjnego Snort.
  
### Generowanie alertów

Snort może generować alerty na podstawie zdefiniowanych reguł. Na przykład, poniższa reguła generuje alert, gdy Snort wykryje próbę skanowania portów:

```bash
alert tcp any any -> $HOME_NET any (msg:"Possible port scan detected"; flags: S; threshold: type threshold, track by_src, count 1, seconds 60; sid:10001;)
```

Gdzie:

- `alert` oznacza, że ta reguła generuje **alert**.
- `tcp any any -> $HOME_NET any` definiuje, że reguła dotyczy wszystkich pakietów **TCP** kierowanych do jakiejkolwiek sieci zdefiniowanej jako `HOME_NET`.
- `msg:"Possible port scan detected"` to wiadomość wyświetlana, gdy reguła jest spełniona.
- `flags: S` oznacza, że reguła dotyczy pakietów **TCP** z flagą **SYN**.
- `threshold: type threshold, track by_src, count 1, seconds 60` definiuje, że alert jest generowany, gdy reguła jest spełniona co najmniej raz w ciągu $60$ sekund.
- `sid:10001` to unikalny identyfikator reguły.

Powyższy przykład jest bardzo prostym przykładem użycia Snort. W praktyce reguły Snort mogą być znacznie bardziej skomplikowane i precyzyjne, co pozwala na bardzo dokładną kontrolę nad tym, co jest wykrywane i jak na to reagować.

## Ściąga

[Ściąga](https://cdn.comparitech.com/wp-content/uploads/2019/07/Snort-Cheat-Sheet.pdf)
