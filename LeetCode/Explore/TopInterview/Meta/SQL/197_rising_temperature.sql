# Write your MySQL query statement below
SELECT DISTINCT w2.id AS id 
FROM Weather AS w1
JOIN Weather AS w2
ON DATEDIFF(w2.recordDate, w1.recordDate) = 1 
WHERE w2.temperature > w1.temperature

# Write your MySQL query statement below
SELECT DISTINCT w2.id AS id 
FROM Weather AS w1, Weather AS w2
WHERE DATEDIFF(w2.recordDate, w1.recordDate) = 1 AND w2.temperature > w1.temperature
