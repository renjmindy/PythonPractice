# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
WITH CTE AS (SELECT *, DENSE_RANK() OVER(PARTITION BY email ORDER BY id ASC) AS ranking FROM Person)

DELETE FROM Person WHERE id IN (SELECT id FROM CTE WHERE ranking > 1)
