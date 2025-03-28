# Enumeracje

Enumeracja to specjalny rodzaj struktury danych.
Pozwala nam na zdefiniowanie pewnej listy nazw, które później możemy interpretować jako wartości liczbowe.
Najlepiej to omówić na przykładzie.

## Przykład

Rozważmy sytuacje, w której tworzymy aplikację webową obsługującą konta użytkowników o różnym poziomie dostępu.
Możemy mieć zwykłego użytkownika, który ma dostęp tylko do podstawowych funkcjonalności, ale także moderatora i administratora.
Każdy z nich będzie miał inne uprawnienia i ich role muszą być brane pod uwagę w wielu miejscach naszej implementacji.
W tym celu utworzymy enumerację tych ról.

### Implementacja

```c
#include <stdio.h>

typedef enum role {
  user, moderator, admin
} role;

int main() {
  role currentRole = admin;

  switch(currentRole) {
    case user:
        printf("User role: %d\n", currentRole);
        break;
    case moderator:
        printf("Moderator role: %d\n", currentRole);
        break;
    case admin:
        printf("Admin role: %d\n", currentRole);
        break;
  }

  return 0;
} 
```

### Opis

Na początku tworzymy enumerację roli: `enum role`.
Następnie w kodzie głównym przypisujemy wybraną rolę do zmiennej `currentRole`.
Dzięki wykorzystaniu enumeracji możemy w prosty i czytelny sposób skorzystać z operacji `switch` i uzależnić działanie programu od przypisanej roli.
Po uruchomieniu programu można zaobserwować, że do każdej zdefiniowanej przez nas roli została przypisana liczba całkowita, ponieważ domyślnie pod enumeracjami kryją się właśnie kolejne liczby całkowite.
Tak więc nasza rola *user* ma przypisaną wartość $0$, *moderator* ma wartość $1$, a *admin* ma wartość $2$.