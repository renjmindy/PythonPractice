# Write your MySQL query statement below
WITH CTE AS (SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary, DENSE_RANK() OVER(PARTITION BY e.departmentId ORDER BY e.salary DESC) AS ranking FROM Employee AS e INNER JOIN Department AS d ON e.departmentId = d.id) 

SELECT Department, Employee, Salary
FROM CTE
WHERE ranking <= 3
