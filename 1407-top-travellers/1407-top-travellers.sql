# Write your MySQL query statement below

SELECT u.name , IFNULL(SUM(r.distance), 0) AS travelled_distance  
From Users u  LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id # r.id bhi use kar sakte hai
ORDER BY travelled_distance DESC, u.name;