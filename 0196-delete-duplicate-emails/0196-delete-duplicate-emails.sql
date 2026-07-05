# Write your MySQL query statement below
DELETE p FROM Person p, Person q
WHERE p.email = q.email AND p.id > q.id