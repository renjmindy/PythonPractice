# Write your MySQL query statement below
WITH CTE AS (SELECT *, DENSE_RANK() OVER (ORDER BY salary DESC) AS ranking FROM Employee)
SELECT MAX(salary) AS SecondHighestSalary
FROM CTE
WHERE ranking = 2
