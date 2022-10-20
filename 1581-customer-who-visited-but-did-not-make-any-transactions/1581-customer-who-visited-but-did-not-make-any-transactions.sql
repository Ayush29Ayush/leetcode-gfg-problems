# Write your MySQL query statement below
# refer this if needed => https://www.youtube.com/watch?v=QjlRRBca3XE&list=PLtfxzVLWb-B_V2BPwlXOmrbO4a-a43Eg5&index=32
# left join gives all the left data and the matching data from right side so we use left join

SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE transaction_id IS NULL
GROUP BY v.customer_id # GROUP BY v.visit_id bhi use kar sakte they