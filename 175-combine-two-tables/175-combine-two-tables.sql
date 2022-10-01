# Write your MySQL query statement below
SELECT firstname, lastname, city, state
FROM person LEFT JOIN Address ON Person.personId = Address.personId