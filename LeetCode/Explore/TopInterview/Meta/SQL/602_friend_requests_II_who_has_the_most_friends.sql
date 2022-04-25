# Write your MySQL query statement below
WITH CTE AS (SELECT id, COUNT(*) AS num FROM (
  SELECT requester_id AS id FROM RequestAccepted
  UNION ALL
  SELECT accepter_id AS id FROM RequestAccepted
) AS TEMP GROUP BY id)

SELECT id, num
FROM CTE
WHERE num = (SELECT MAX(num) FROM CTE)
