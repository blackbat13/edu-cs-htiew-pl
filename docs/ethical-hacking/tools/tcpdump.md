# Tcpdump

Tcpdump to potężne narzędzie linii poleceń używane do przechwytywania i analizy ruchu sieciowego. Pozwala użytkownikowi *podglądać* ruch sieciowy, który przechodzi przez system. Tcpdump jest najczęściej używane do diagnozowania problemów z siecią oraz do monitorowania aktywności sieciowej.

Tcpdump umożliwia przechwytywanie pakietów, które przemieszczają się przez określony interfejs sieciowy. Po przechwyceniu pakietów, Tcpdump może zapisywać je do pliku do późniejszej analizy lub wyświetlać je w czasie rzeczywistym. Tcpdump oferuje możliwość filtrowania ruchu sieciowego na podstawie różnych kryteriów, takich jak typ protokołu, adres IP, port i inne.

## Przykłady użycia

### Przechwytywanie ruchu sieciowego

Podstawowe użycie Tcpdump polega na przechwytywaniu ruchu sieciowego przechodzącego przez określony interfejs. Poniższe polecenie przechwytuje ruch na interfejsie `eth0`:

```bash
tcpdump -i eth0
```

### Przechwytywanie pakietów TCP

Tcpdump można skonfigurować, aby przechwytywać tylko określone typy pakietów. Poniższe polecenie przechwytuje tylko pakiety **TCP**:

```bash
tcpdump -i eth0 tcp
```

### Przechwytywanie pakietów od/na określonego adresu IP

Można również filtrować pakiety na podstawie adresu **IP**. Poniższe polecenie przechwytuje tylko pakiety pochodzące lub kierujące się do adresu `192.168.1.100`:

```bash
tcpdump -i eth0 host 192.168.1.100
```

### Zapisywanie i odtwarzanie ruchu sieciowego

Tcpdump umożliwia zapisywanie przechwyconych pakietów do pliku, który może być później odtwarzany. Poniższe polecenie zapisuje przechwycone pakiety do pliku `output.pcap`:

```bash
tcpdump -i eth0 -w output.pcap
```

Można później odtworzyć przechwycony ruch z pliku za pomocą polecenia:

```bash
tcpdump -r output.pcap
```

## Ściąga

{% embed url="https://cdn.comparitech.com/wp-content/uploads/2019/06/tcpdump-cheat-sheet-2.pdf" %}
Ściąga
{% endembed %}
