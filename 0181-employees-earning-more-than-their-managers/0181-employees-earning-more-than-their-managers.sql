# Write your MySQL query statement below
Select e.name as Employee from employee e
WHERE (e.managerId is NOT NULL) AND e.salary > (SELECT salary from employee
WHERE id = e.managerId)