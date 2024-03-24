# Zadanie 5 - rozwiązanie

```SQL
SELECT Playlist.Name, SUM(Track.Milliseconds) AS MillisecondsTotalLength FROM Playlist JOIN PlaylistTrack USING(PlaylistId) JOIN Track USING(TrackId) GROUP BY Playlist.PlaylistId ORDER BY MillisecondsTotalLength ASC LIMIT 1;
```
