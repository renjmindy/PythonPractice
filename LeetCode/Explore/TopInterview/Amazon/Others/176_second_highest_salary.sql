# Write your MySQL query statement below
WITH CTE AS (SELECT *, DENSE_RANK() OVER (ORDER BY Salary DESC) AS ranking FROM Employee) 
SELECT MAX(Salary) SecondHighestSalary
FROM CTE
WHERE ranking = 2
