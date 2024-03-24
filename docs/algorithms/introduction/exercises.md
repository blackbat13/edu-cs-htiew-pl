# Ćwiczenia

Poznaliśmy podstawy algorytmiki i reprezentacji algorytmów, to teraz przyszła pora na proste ćwiczenia. Naszym zadaniem będzie poprowadzenie robota ze startu do mety. W tym celu stworzymy zestaw instrukcji dla robota: **algorytm**, który doprowadzi go do celu, czyli **rozwiąże zadany problem**.

## Podstawowe zasady

- Pole startowe oznaczone jest na niebiesko.
- Meta oznaczona jest na zielono.
- Robot zaczyna na polu startowym. Jego celem jest dotarcie do mety.
- W każdym kroku robot może przemieścić się o jedno pole.

Dostępne mamy następujące instrukcje:

- Prawo.
- Lewo.
- Góra.
- Dół.

Każda z instrukcji sprawia, że robot przemieszcza się o jedno pole we wskazanym kierunku.

## Ćwiczenie 1

![](../../.gitbook/assets/Mazes_alg1.png)

### Przykładowe rozwiązanie - algorytm liniowy

```
1. Prawo.
2. Prawo.
3. Prawo.
4. Prawo.
```

### Przykładowe rozwiązanie - algorytm z pętlą

```
1. Powtórz 4 razy:
    2. Prawo.
```

## Ćwiczenie 2

![](../../.gitbook/assets/Mazes_alg2.png)

## Ćwiczenie 3

**Nowa zasada**: **szare** bloki oznaczają ściany. Przez ściany nie można przechodzić, ani też stawać na nich, trzeba więc je omijać.

![](../../.gitbook/assets/Mazes_alg3.png)

## Ćwiczenie 4

![](../../.gitbook/assets/Mazes_alg4.png)

## Ćwiczenie 5

![](../../.gitbook/assets/Mazes_alg5.png)

## Ćwiczenie 6

**Nowa zasada**: **żółte** pola oznaczają skarb. Przed dotarciem na metę należy zebrać **wszystkie skarby**, tzn. odwiedzić każde żółte pole.

![](../../.gitbook/assets/Mazes_alg6.png)

## Ćwiczenie 7

Nowe zasady:

- Poruszamy się z perspektywy robota.
- Korzystamy z nowego zestawu instrukcji.
- Robot początkowo skierowany jest w **dół** (na południe).

Nowy zestaw instrukcji:

- Idź do przodu.
- Obróć się w lewo.
- Obróć się w prawo.

![](../../.gitbook/assets/Mazes_alg5.png)