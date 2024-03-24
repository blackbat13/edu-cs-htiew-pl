# Typy danych

Podobnie jak w programowaniu, w bazach danych także mamy różne typy danych. Poszczególne typy mogą różnić się w zależności od silnika bazodanowego, na którym pracujemy. My skupimy się na plikowych bazach danych **SQLite**.

W silniku SQLite wszystkie danych przynależą do jednego z pięciu typów:

- **NULL** - wartość pusta,
- **INTEGER** - liczba całkowita zajmująca od $$0$$ do $$8$$ bajtów w zależności od wielkości wartości,
- **REAL** - liczba rzeczywista, zapisana na $$8$$ bajtach,
- **TEXT** - ciąg znaków używający kodowania bazy danych (UTF-8, UTF-16B lub UTF-16LE),
- **BLOB** - zestaw danych, przechowywanych dokładnie tak jak zostały wprowadzone.

Dodatkowo istnieje także określenie **NUMERIC**. Pola z tym oznaczeniem mogą zawierać wartości wykorzystujące **wszystkie** powyższe typy.