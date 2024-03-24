# Zadanie 7 - rozwiązanie

```SQL
SELECT Title, Track.Name FROM Artist JOIN Album USING(ArtistId) JOIN Track USING(AlbumId) WHERE Artist.Name='Black Sabbath';
```
