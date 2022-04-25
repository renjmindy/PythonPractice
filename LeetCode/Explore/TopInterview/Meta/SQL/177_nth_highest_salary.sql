CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      WITH CTE AS (SELECT *, DENSE_RANk() OVER(ORDER BY salary DESC) AS ranking FROM Employee)
      SELECT MAX(salary) 
      FROM CTE
      WHERE ranking = N
  );
END
