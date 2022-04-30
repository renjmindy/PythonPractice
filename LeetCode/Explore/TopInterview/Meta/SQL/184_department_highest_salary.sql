# Write your MySQL query statement below
WITH CTE AS (SELECT *, DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS ranking FROM Employee) 

SELECT d.name AS Department, c.name AS Employee, c.salary AS Salary
FROM CTE AS c
JOIN Department AS d
ON c.departmentId = d.id
WHERE ranking = 1
