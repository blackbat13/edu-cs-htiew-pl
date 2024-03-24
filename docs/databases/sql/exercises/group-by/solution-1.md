# Zadanie 1 - rozwiązanie

```SQL
SELECT Title, SUM(Milliseconds) AS TracksLengthsSum FROM Album JOIN Track USING(AlbumId) GROUP BY Album.AlbumId ORDER BY TracksLengthsSum DESC;
```
