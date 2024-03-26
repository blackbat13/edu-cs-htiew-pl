# Operacje bitowe

Na bitach możemy wykonywać różne operacje, podobnie jak na liczbach czy też cyfrach.
Jest jednak pewna grupa operacji, tzw. __operacje bitowe__, które są specjalnymi operacjami wykonywanymi na bitach, czyli na wartościach $0$ i $1$.
Są to w większości operacje logiczne, w których wartość $0$ interpretujemy jako **Fałsz**, a wartość $1$ interpretujemy jako **Prawda**.

## AND

Operacja wykonywana na dwóch bitach. Zwraca $1$ tylko wtedy, gdy obie wartości są równe $1$.
W programowaniu ta operacja jest często reprezentowana za pomocą znaku **&**.

### Tabelka

|  X  |  Y  | X AND Y |
| :-: | :-: | :-----: |
|  0  |  0  |    0    |
|  0  |  1  |    0    |
|  1  |  0  |    0    |
|  1  |  1  |    1    |

## OR

Operacja wykonywana na dwóch bitach. Zwraca $1$ wtedy, gdy co najmniej jedna z wartości jest równa $1$.
W programowaniu ta operacja jest często reprezentowana za pomocą znaku **|**.

### Tabelka

|  X  |  Y  | X OR Y |
| :-: | :-: | :----: |
|  0  |  0  |   0    |
|  0  |  1  |   1    |
|  1  |  0  |   1    |
|  1  |  1  |   1    |

## XOR - Exclusive OR

Operacja wykonywana na dwóch bitach. Zwraca $1$ wtedy, gdy dokładnie jedna z wartości jest równa $1$.
W programowaniu ta operacja jest często reprezentowana za pomocą znaku **^**.

### Tabelka

|  X  |  Y  | X XOR Y |
| :-: | :-: | :-----: |
|  0  |  0  |    0    |
|  0  |  1  |    1    |
|  1  |  0  |    1    |
|  1  |  1  |    0    |

## NOT

Operacja wykonywana na jednym bicie. Zwraca wartość przeciwną bitu.
W programowaniu ta operacja jest często reprezentowana za pomocą znaku **!**.

### Tabelka

|  X  | NOT X |
| :-: | :---: |
|  0  |   1   |
|  1  |   0   |
