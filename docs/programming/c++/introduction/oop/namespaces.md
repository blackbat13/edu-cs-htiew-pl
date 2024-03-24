# Przestrzenie nazw

## Wstęp

Przestrzenie nazw (ang. *namespace*) w języku C++ pozwalają na lepszą organizację kodu.
Dzięki zastosowaniu przestrzeni nazw, możemy wydzielić fragment implementacji w postaci spójnego w semantycznym znaczeniu lub przeznaczeniu bloku.
Pozwala to nam między innymi na używanie funkcji, klas o tych samych nazwach, ale różnym znaczeniu i umieszczenie ich w różnych przestrzeniach nazw.
Jest to także dobry sposób na upewnienie się, że tworzona przez nas biblioteka nie spowoduje konfliktu nazw, gdy zostanie użyta w innym projekcie.

### Przykład 1

Rozważmy bardzo prosty, a nawet naiwny przykład. 
Mamy dwie funkcje, których zadaniem jest wyświetlenie komunikatu "pomocy".
Jedna z nich dotyczy biblioteki, którą tworzymy do obsługi ułamków, a druga dotyczy biblioteki liczb zespolonych.
Możemy oczywiście nazwać je np. *helpFractions* i *helpComplex*, ale lepiej będzie używać spójnych nazw w każdej bibliotece.
Tutaj z pomocą przychodzą nam właśnie przestrzenie nazw.

```cpp
#include <iostream>

namespace fractions {
    void help() {
        std::cout << "Help for fractions" << std::endl;
    }
}

namespace complex {
    void help() {
        std::cout << "Help for complex numbers" << std::endl;
    }
}

int main() {

    fractions::help();

    complex::help();

    return 0;
}
```

### Przykład 2

Przestrzenie nazw możemy bez problemu rozbijać na wiele definicji, dzięki czemu mogą być używane w wielu plikach bez obaw o nadpisanie.

```cpp
#include <iostream>

namespace messages {
  void hello() {
    std::cout << "Hello World!" << std::endl;
  }
}

namespace messages{
  void warning() { 
    std::cout << "WARNING!" << std::endl;
  }
}

int main() {
  
  messages::hello();
  messages::warning();

  return 0;
} 
```

## Używanie przestrzeni nazw

Czasem chcemy korzystać z przestrzeni nazw bez podawania jej nazwy przy każdym wywołaniu.
Do tego służy nam polecenie **using namespace**.
Za pomocą tego polecenia możemy "włączyć" całą przestrzeń nazw do obecnego pliku.

Bywa jednak też tak, że nie potrzebujemy całej przestrzeni nazw, a jedynie jej fragment, np. konkretną funkcję.
Wtedy możemy skorzystać z samego polecenia **using**. 

Przyjrzyjmy się poniższym przykładom.

### Przykład 1

```cpp
#include <iostream>

namespace fractions {
    void help() {
        std::cout << "Help for fractions" << std::endl;
    }
}

namespace complex {
    void help() {
        std::cout << "Help for complex numbers" << std::endl;
    }
}


using namespace fractions;

int main() {

    help();

    complex::help();

    return 0;
}
```

W powyższej implementacji niejako "załączamy" przestrzeń nazw **fractions** za pomocą polecenia `using namespace fractions;`.
Dzięki temu, aby wywołać funkcję *help* z przestrzeni *fractions* nie trzeba już podawać nazwy tej przestrzeni nazw.
Zwróć uwagę na to, że przestrzeń nazw musi być wcześniej zdefiniowana.

### Przykład 2

```cpp
#include <iostream>

using std::cout, std::endl;

namespace fractions {
    void help() {
        cout << "Help for fractions" << endl;
    }
}

namespace complex {
    void help() {
        cout << "Help for complex numbers" << endl;
    }
}

int main() {

    fractions::help();

    complex::help();

    return 0;
}
```

W tym przykładnie używamy dwóch poleceń z przestrzeni **std**: *cout* i *endl*.
Nie musimy więc załączać całej przestrzeni *std*, tak jak to często robimy.
Wystarczą nam jej dwa składniki, które załączamy za pomocą polecenia `using std::cout, std::endl`.

## Zagnieżdżanie

Przestrzenie nazw możemy także bez problemu zagnieżdżać.
Spójrzmy na poniższy przykład.

### Przykład

```cpp
#include <iostream>

namespace numbers {

  namespace fractions {
      void help() {
          std::cout << "Help for fractions" << std::endl;
      }
  }

  namespace complex {
      void help() {
          std::cout << "Help for complex numbers" << std::endl;
      }
  }

}

int main() {

    numbers::fractions::help();

    numbers::complex::help();

    return 0;
}
```