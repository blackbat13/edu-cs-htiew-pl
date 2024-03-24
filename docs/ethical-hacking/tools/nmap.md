# Nmap (Network Mapper)

Nmap to wolne oprogramowanie używane do analizy bezpieczeństwa sieci i zarządzania sieciami. Narzędzie to jest zdolne do odkrywania hostów i usług w sieci, tworzenia map sieci, skanowania portów oraz sprawdzania dostępnych usług i ich wersji. Nmap jest przydatny zarówno dla administratorów sieci jak i osób testujących bezpieczeństwo sieci.

{% embed url="https://nmap.org" %}
Nmap
{% endembed %}

## Podstawowe funkcje i zastosowania

Poniżej przedstawimy kilka różnych funkcji i zastosowań narzędzia Nmap.

### Skanowanie portów

Jednym z podstawowych zastosowań Nmap jest skanowanie portów. Poniższe polecenie skanuje 1000 najczęściej używanych portów na danym hoście (np. 192.168.1.1):

```bash
nmap 192.168.1.1
```

Możemy także skanować wiele hostów jednocześnie, wystarczy podać kilka adresów IP oddzielonych spacją:

```bash
nmap 192.168.1.1 192.168.1.2 192.168.1.3
```

Innym sposobem jest użycie zakresu:

```bash
nmap 192.168.1.1-3
```

Możemy także określić porty, które chcemy przeskanować. W tym celu należy skorzystać z opcji `-p`. Dla przykładu, żeby zeskanować porty od $$20$$ do $$25$$ na hoście $$192.168.1.1$$ napiszemy:

```bash
nmap -p 20-25 192.168.1.1
```

### Wykrywanie wersji usług

Nmap potrafi również wykryć wersje usług działających na poszczególnych portach. Do tego celu służy opcja `-sV`:

```bash
nmap -sV 192.168.1.1
```

### Skanowanie z użyciem TCP SYN

Standardowe skanowanie Nmapa może być łatwo wykryte przez systemy IDS/IPS. Skanowanie z użyciem TCP SYN (zwane również półotwartym skanowaniem) jest bardziej dyskretne. Używamy do tego opcji `-sS`:

```bash
nmap -sS 192.168.1.1
```

## Ściąga

{% embed url="https://cdn.comparitech.com/wp-content/uploads/2019/06/Nmap-Cheat-Sheet.pdf" %}
Ściąga
{% endembed %}
