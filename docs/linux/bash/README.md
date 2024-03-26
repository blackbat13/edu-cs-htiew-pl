# Bash

Bash to powłoka systemowa, jedna z najpopularniejszych w systemach uniksowych. W większości dystrybucji jest domyślną powłoką, dlatego warto wiedzieć, jak z niej poprawnie korzystać i jak wykorzystać jej możliwości, w szczególności pod względem skryptów.

## Tworzenie skryptów

Utwórzmy plik **skrypt.sh** o zawartości takiej jak pokazano poniżej.

```bash
#!/bin/bash

echo "Hello World!"
```

Teraz należy nadać plikowi prawa do wykonywania, by móc go uruchomić:

```
chmod u+x skrypt.sh
```

W końcu uruchamiamy nasz skrypt:

```
./skrypt.sh
```

W konsoli powinien wyświetlić się nam komunikat *Hello World!*.

## Ściąga

[Ściąga](https://quickref.me/bash)