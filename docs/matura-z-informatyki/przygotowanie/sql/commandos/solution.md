# Rozwiązanie

## Zadanie 1

```sql
SELECT imie, nazwisko 
    FROM Komandosi 
    WHERE stopien = "Porucznik";
```

## Zadanie 2

```sql
SELECT COUNT(*) 
    FROM Misje 
    WHERE datamisji LIKE '%-05-%';
```

## Zadanie 3

```sql
SELECT imie, nazwisko 
    FROM Misje 
        Join Komandosi ON numerdowodcy=Komandosi.id;
```

## Zadanie 4

```sql
SELECT imie, nazwisko, nazwa 
    FROM Komandosi 
        JOIN UmiejetnosciKomandosow ON Komandosi.id = UmiejetnosciKomandosow.NumerKomandosa
        JOIN UmiejetnosciSpecjalne ON UmiejetnosciSpecjalne.id = UmiejetnosciKomandosow.NumerUmiejetnosci;
```

## Zadanie 5

```sql
SELECT nazwa, datamisji, count(Komandosi.id) 
    FROM Misje
        JOIN KomandosiNaMisji ON Misje.id = KomandosiNaMisji.NumerMisji
        JOIN Komandosi ON Komandosi.id = KomandosiNaMisji.NumerKomandosa
    GROUP BY Misje.id;
```

## Zadanie 6

```sql
SELECT imie, nazwisko, SUM(Misje.iloscdnimisji) 
    FROM Misje
        JOIN KomandosiNaMisji ON Misje.id = KomandosiNaMisji.NumerMisji
        JOIN Komandosi ON Komandosi.id = KomandosiNaMisji.NumerKomandosa
    GROUP BY Komandosi.id;
```

## Zadanie 7

```sql
SELECT Misje.nazwa, COUNT(UmiejetnosciSpecjalne.id) 
    FROM Komandosi 
        JOIN KomandosiNaMisji ON Komandosi.id = KomandosiNaMisji.NumerKomandosa
        JOIN Misje ON KomandosiNaMisji.NumerMisji = Misje.id 
        JOIN UmiejetnosciKomandosow ON UmiejetnosciKomandosow.NumerKomandosa = Komandosi.id
        JOIN UmiejetnosciSpecjalne ON UmiejetnosciKomandosow.NumerUmiejetnosci = UmiejetnosciSpecjalne.id 
    WHERE UmiejetnosciSpecjalne.nazwa = "Saper"
    GROUP BY Misje.id;
```
