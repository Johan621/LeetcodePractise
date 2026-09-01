# Write your MySQL query statement below
SELECT email FROM Person p
GROUP BY email
HAVING COUNT(*)>1