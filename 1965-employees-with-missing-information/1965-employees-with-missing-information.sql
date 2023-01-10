# Write your MySQL query statement below
SELECT employee_id FROM Employees WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION 
SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)

ORDER BY 1 ASC
# ORDER BY 1 ASC simply means sorting the view or table by 1st column of query's result in ascending order!