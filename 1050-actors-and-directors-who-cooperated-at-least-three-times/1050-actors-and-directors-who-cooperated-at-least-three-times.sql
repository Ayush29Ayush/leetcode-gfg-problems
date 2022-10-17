# Write your MySQL query statement below
# refer this => https://www.youtube.com/watch?v=ZL-i7o-JPi0&list=PLtfxzVLWb-B_V2BPwlXOmrbO4a-a43Eg5&index=17

SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(timestamp)>=3;