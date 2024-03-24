# Zadanie 10 - rozwiązanie

```SQL
SELECT InvoiceDate, Name FROM Invoice JOIN InvoiceLine USING(InvoiceId) JOIN Track USING(TrackId);
```
