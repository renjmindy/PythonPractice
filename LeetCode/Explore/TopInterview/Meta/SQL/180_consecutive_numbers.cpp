# Write your MySQL query statement below
WITH CTE AS (SELECT *, LAG(num) OVER(ORDER BY id ASC) AS prev, LEAD(num) OVER(ORDER BY id ASC) AS next FROM Logs)

SELECT DISTINCT num AS ConsecutiveNums
FROM CTE
WHERE num = prev and num = next
