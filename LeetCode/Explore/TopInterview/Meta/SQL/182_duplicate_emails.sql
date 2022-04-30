# Write your MySQL query statement below
SELECT email AS Email FROM Person GROUP BY email HAVING count(*) > 1

# Write your MySQL query statement below
SELECT DISTINCT p1.email AS Email
FROM Person AS p1, Person AS p2
WHERE p1.email = p2.email and p1.id != p2.id

# Write your MySQL query statement below
SELECT email AS Email
FROM (SELECT email, COUNT(*) AS num FROM Person GROUP BY email) AS temp
WHERE num > 1
