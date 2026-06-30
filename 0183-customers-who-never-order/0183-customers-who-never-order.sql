# Write your MySQL query statement below
SELECT name AS Customers from Customers
WHERE id NOT IN (
SELECT customerID FROM Orders) 