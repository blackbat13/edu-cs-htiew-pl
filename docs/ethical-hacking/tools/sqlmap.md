# SQLmap

SQLmap to potężne narzędzie do testów penetracyjnych, które automatyzuje proces wykrywania i wykorzystywania luk w zabezpieczeniach **SQL Injection**. Narzędzie to jest otwartoźródłowe i dostępne dla wielu platform, w tym Linux, MacOS i Windows.

SQLmap automatyzuje proces wykrywania i wykorzystywania luk w zabezpieczeniach SQL Injection. Narzędzie to skanuje cele, identyfikuje potencjalne podatności, a następnie automatycznie wykorzystuje je do uzyskania dostępu do danych. SQLmap jest w stanie automatycznie rozpoznawać i obsługiwać różne bazy danych, takie jak MySQL, Oracle, PostgreSQL i wiele innych.

[SQLmap](https://sqlmap.org)

## Przykłady użycia

### Wykrywanie luk SQL Injection

Aby przeskanować określony URL pod kątem podatności na SQL Injection, można użyć poniższego polecenia:

```bash
sqlmap -u "http://example.com/index.php?id=1"
```

### Wykorzystywanie luk SQL Injection

Jeśli SQLmap znajduje podatność, może automatycznie ją wykorzystać. Poniższe polecenie przeskanuje URL, a następnie, jeśli znajdzie luki, automatycznie uzyska dane z bazy danych:

```bash
sqlmap -u "http://example.com/index.php?id=1" --dump
```

## Ściąga

[Ściąga](https://cdn.comparitech.com/wp-content/uploads/2021/07/sqlmap-Cheat-Sheet.pdf)
