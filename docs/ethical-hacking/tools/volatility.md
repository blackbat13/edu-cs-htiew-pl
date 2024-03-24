# Volatility

Volatility to otwartoźródłowe narzędzie do analizy pamięci w systemach operacyjnych. Umożliwia ekstrakcję informacji z obrazów pamięci RAM, co jest często używane w forensyce cyfrowej podczas badania incydentów bezpieczeństwa.

Volatility analizuje obrazy pamięci RAM, umożliwiając badaczom odtworzenie działania systemu w czasie bliskim incydentowi. Narzędzie to jest w stanie wydobyć wiele typów informacji, w tym listę procesów, otwartych gniazd sieciowych, załadowanych modułów jądra, plików cache, zawartości bufora i wiele innych.

{% embed url="https://www.volatilityfoundation.org" %}
Volatility
{% endembed %}

## Przykłady użycia

### Wyświetlenie listy procesów

Aby wyświetlić listę procesów z obrazu pamięci, można użyć polecenia `pslist`:

```bash
volatility -f memorydump.raw --profile=Win7SP1x64 pslist
```

### Wyświetlenie otwartych gniazd sieciowych

Aby wyświetlić otwarte gniazda sieciowe, można użyć polecenia `sockets`:

```bash
volatility -f memorydump.raw --profile=Win7SP1x64 sockets
```

### Wyświetlenie zawartości bufora

Aby wyświetlić zawartość bufora dla konkretnego procesu, można użyć polecenia `procdump`:

```bash
volatility -f memorydump.raw --profile=Win7SP1x64 procdump -p 1234 -D dump/
```

W powyższym przykładzie $$1234$$ to identyfikator procesu (**PID**), a `dump/` to katalog, w którym zostanie zapisany zrzut procesu.
