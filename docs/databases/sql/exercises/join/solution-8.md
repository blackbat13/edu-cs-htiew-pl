# Zadanie 8 - rozwiązanie

```SQL
SELECT Customer.FirstName AS CustomerFirstName, Customer.LastName AS CustomerLastName, Employee.FirstName AS EmployeeFirstName, Employee.LastName AS EmployeeLastName FROM Customer JOIN Employee ON(Customer.SupportRepId=Employee.EmployeeId);
```
