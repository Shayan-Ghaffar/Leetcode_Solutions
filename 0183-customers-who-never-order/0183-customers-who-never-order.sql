# Write your MySQL query statement below
SELECT name AS Customers from Customers
WHERE id NOT IN (
SELECT c.id FROM Customers c, Orders o
where c.id = o.customerID) 