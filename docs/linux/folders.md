# Katalogi

## Wstęp

Aby sprawnie posługiwać się terminalem, musimy wiedzieć, jak poruszać się po strukturze katalogów.
Omówimy więc podstawowe polecenia pozwalające na poruszanie się po drzewie katalogów, a także na tworzenie nowych katalogów i usuwanie ich.

## Obecna ścieżka: pwd

W trakcie przechodzenia po różnych katalogach łatwo się pogubić.
Aby sprawdzić, pod jaką ścieżką się aktualnie znajdujemy, użyjemy polecenia **pwd** (ang. __print working directory__).

### Składnia

```
pwd
```

## Zmiana katalogu: cd

Do poruszania się po systemie niezbędne będzie polecenie zmiany katalogu: **cd** (ang. __change directory__).

### Składnia

```
cd <nazwa katalogu lub ścieżka>
```

## Utworzenie katalogu: mkdir

Czasem bywa tak, że potrzebujemy utworzyć nowy katalog.
Przyda nam się wtedy polecenie **mkdir** (ang. __make directory__).

### Składnia

```
mkdir <nazwa katalogu>
```

## Usuwanie katalogu: rmdir

Skoro tworzymy katalogi, to powinniśmy także wiedzieć, jak je usuwać.
Użyjemy do tego polecenia **rmdir** (ang. __remove directory__).

{% hint style="warning" %}
Domyślnie za pomocą polecenia ``rmdir`` możemy usuwać tylko puste katalogi.
{% endhint %}

### Składnia

```
rmdir <nazwa katalogu>
```

## Wyświetlenie zawartości katalogu: ls

Wiemy już jak tworzyć i usuwać, czas więc dowiedzieć się, jak podejrzeć zawartość obecnego katalogu.
Do tego wykorzystamy polecenie **ls** (ang. __list__).
Opcjonalnie do polecenia możemy podać ścieżkę do katalogu, którego zawartość chcemy wyświetlić.

### Składnia

```
ls [ścieżka]
```

### Opcje

Polecenie ``ls`` posiada kilka przydatnych opcji. Opiszemy niektóre z nich.

#### Wyświetlenie wszystkich plików: -a

Opcja ``-a`` (ang. __all__) powoduje wyświetlenie także ukrytych plików, czyli takich, których nazwa zaczyna się od kropki.

#### Wyświetlenie szczegółów: -l

Opcja ``-l`` powoduje wyświetlenie bardziej szczegółowej listy plików.

#### Rekursywne wylistowanie: -R

Opcja ``-R`` (ang. __recursive__) powoduje wyświetlenie nie tylko zawartości podanego katalogu, ale także zawartości katalogów w nim zawartych, a także zawartości katalogów w nich zawartych itd.
Jest to rekursywne przeglądanie drzewa katalogów.