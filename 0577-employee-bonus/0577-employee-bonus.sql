# Write your MySQL query statement below
SELECT e.name, b.bonus FROM EMPLOYEE e left outer join BONUS b
on e.empId = b.empId WHERE IFNULL(b.bonus, 0) < 1000