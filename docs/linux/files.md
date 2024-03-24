# Pliki

## Wstęp

Pliki - bez nich ciężko pracować. 
Przybliżymy więc kilka podstawowych poleceń do operacji na plikach w systemie Linux.

## Utworzenie pustego pliku: touch

Do utworzenia pustego pliku skorzystamy z polecenia **touch**.

### Składnia

```
touch <nazwa pliku>
touch <nazwa pierwszego pliku> <nazwa drugiego pliku> ...
```

## Wyświetlenie zawartości pliku: cat

Jednym z przydatnych poleceń, które może posłużyć także do wyświetlenia zawartości plików, jest polecenie **cat**.

### Składnia

```
cat <nazwa pliku>
```

## Usuwanie pliku: rm

Aby usunąć plik skorzystamy z polecenia **rm**.

{% hint style="warning" %}
**Uwaga**

Pliki usunięte za pomocą polecenia ``rm`` nie trafiają do kosza, tylko są bezpowrotnie usuwane. Należy więc obchodzić się z tym poleceniem bardzo ostrożnie.
{% endhint %}

### Składnia

```
rm <nazwa pliku>
```

### Opcje

Polecenie ``rm`` posiada kilka przydatnych opcji. Opiszemy niektóre z nich.

#### Usuwanie bez potwierdzenia: -f

Opcja ``-f`` (ang. __force__) powoduje usunięcie plików bez pytania o potwierdzenie operacji.

#### Rekursywne usuwanie: -R

Opcja ``-R`` (ang. __recursive__) powoduje usunięcie podanego katalogu wraz z jego pełną zawartością.

## Kopiowanie plików: cp

Do skopiowania pliku skorzystamy z polecenia **cp** (ang. __copy__).

### Składnia

```
cp <ścieżka do istniejącego pliku> <ścieżka do nowego pliku>
```

## Przeniesienie pliku: mv

Nie zawsze chcemy kopiować pliki, czasem chcemy je po prostu przenieść, lub zmienić ich nazwę. Wykorzystamy do tego polecenie **mv** (ang. __move__).

### Składnia

```
mv <ścieżka do istniejącego pliku> <ścieżka do nowej lokalizacji>
```

## Określenie typu pliku: file

Ponieważ w systemie Linux rozszerzenia nie mają znaczenia, aby poznać typ pliku możemy skorzystać z polecenia **file**.

### Składnia

```
file <ścieżka do pliku>
```