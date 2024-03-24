# Wyjątki

Błędy są rzeczą ludzką - nie unikniemy ich.
Błędów nie unikniemy także w programowaniu, ale część z nich możemy przewidzieć i **obsłużyć**.
Zastanówmy się na przykład nad dzieleniem dwóch liczb przez siebie.
Możemy do tego napisać specjalną funkcję, która przyjmie dwa parametry: dzielną i dzielnik.
Co jednak, gdy spróbujemy podzielić przez zero?
Nasz program zakończy się błędem.
Możemy to przewidzieć i dodać instrukcję warunkową, która sprawdzi, czy nie chcemy podzielić przez zero.
Jaki jednak wynik powinna zwrócić nasza funkcja w takim przypadku?
Jak poinformować użytkownika/programistę, że próbowano wykonać niedozwoloną operację?
W takim przypadku, zamiast zwracać konkretną wartość, możemy **wyrzucić wyjątek**.

## throw

W momencie, gdy wewnątrz funkcji wykryjemy, że doszło do niedozwolonej sytuacji, możemy wyrzucić wyjątek.
Robimy to za pomocą słowa kluczowego `throw`.
Po wyrzuceniu wyjątku funkcja kończy swoje działanie.

### Przykład

```cpp
int divide(int a, int b) {
  if(b == 0) {
    throw "Dzielenie przez 0";
  }

  return a / b;
}
```

## try-catch

Do obsługi wyjątków posłuży nam blok `try{} catch() {}`.
W części `try` próbujemy wykonać _problematyczne_ operacje.
Takie operacje, które mogą zakończyć się błędem, a dokładniej: **wyjątkiem**.

Blok `catch` natomiast służy do _złapania_, czy też **przechwycenia** wyjątku.
Tutaj określamy, jakie operacje powinien wykonać program, po napotkaniu wyjątku.

Przyjrzyjmy się poniższemu przykładowi.

### Przykład

```cpp
int main() {
  int a = 2, b = 0, c;

  try {
    c = divide(a,b);
    cout << a << " / " << b << " = " << c << endl;
  } catch(const char* error) {
    cout << error << endl;
  }

  return 0;
} 
```

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/TryCatch#main.cpp" %}
Wyjątek - przykład
{% endembed %}
