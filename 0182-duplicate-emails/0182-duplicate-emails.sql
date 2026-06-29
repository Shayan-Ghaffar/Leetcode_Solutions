# Write your MySQL query statement below
SELECT distinct p.email from Person p, Person q
WHERE p.email = q.email AND p.id != q.id