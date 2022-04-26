# Write your MySQL query statement below
WITH CTE AS (SELECT *, DENSE_RANK() OVER(ORDER BY score DESC) AS ranking FROM Scores)
SELECT score, ranking AS `rank` 
FROM CTE
