# Instrukcje warunkowe

### Przykład 1

```bash
#!/bin/bash

# gt : greater than
if [ 150 -gt 25 ]
then
    echo "Warunek wiekszosci spelniony"
fi

# lt: less than
if [ 25 -lt  150 ]
then
    echo "Warunek mniejszosci spelniony"
fi

# eq: equal
if [ 25 -eq  25 ]
then
    echo "Warunek rownosci spelniony"
fi
```

### Przykład 2

```bash
#!/bin/bash

# gt : greater than
if [ 4 -gt 25 ]
then
    echo "Warunek wiekszosci spelniony"
else
    echo "Warunek wiekszosci nie jest spelniony"
fi

# lt: less than
if [ 180 -lt  150 ]
then
    echo "Warunek mniejszosci spelniony"
else
    echo "Warunek mniejszosci nie jest spelniony"
fi

# eq: equal
if [ 4 -eq  25 ]
then
   echo "Warunek rownosci spelniony"
else
   echo "Warunek rownosci nie jest spelniony"
fi
```

### Przykład 3

```bash
#!/bin/bash

if [ $(($1 % 4)) -eq 0 ] && [ ! $(($1 % 100)) -eq 0 ]
then
    echo "Rok jest przestepny"
elif [ $(($1 % 400)) -eq 0 ]
then
    echo "Rok jest przestepny"
else
    echo "Rok nie jest przestepny"
fi
```