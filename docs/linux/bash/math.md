# Obliczenia

W celu wykonania obliczeń arytmetycznych zamykamy je w podwójne nawiasy okrągłe opatrzone z przodu znakiem dolara: `$(( ))`.

### Przykład

```bash
#!/bin/bash

suma=$((3+8))
echo $suma

a=1
b=7

iloczyn=$((a*b))
echo $iloczyn

modulo=$((10%3))
echo $modulo
```