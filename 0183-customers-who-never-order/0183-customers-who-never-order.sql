# Write your MySQL query statement below
# hamesha FROM se likhna start karo

SELECT c.name AS Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerid
WHERE o.customerid IS NULL