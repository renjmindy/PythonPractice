# Write your MySQL query statement below
WITH CTE AS (SELECT *, DENSE_RANK() OVER(PARTITION BY player_id ORDER BY event_date ASC) AS ranking FROM Activity)

SELECT player_id, event_date AS first_login
FROM CTE
WHERE ranking = 1
