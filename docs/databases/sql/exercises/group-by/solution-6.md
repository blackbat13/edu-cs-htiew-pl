# Zadanie 6 - rozwiązanie

```SQL
SELECT FirstName, LastName, ROUND(SUM(Total), 2) AS TotalCost FROM Customer JOIN Invoice USING(CustomerId) GROUP BY Customer.CustomerId ORDER BY LastName ASC;
```
