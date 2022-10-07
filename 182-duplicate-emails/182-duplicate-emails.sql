# Write your MySQL query statement below

# Always start your query using FROM  
# Think of department wala example where show something respective to each department

SELECT email 
FROM Person
GROUP BY email
HAVING COUNT(DISTINCT id) > 1; 

# distinct naa bhi likho toh chalega since id is primary key which is always unique