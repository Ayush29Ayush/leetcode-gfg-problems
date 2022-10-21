# Write your MySQL query statement below
# refer this if needed => https://www.youtube.com/watch?v=RjabLgrQN5Y&list=PLtfxzVLWb-B_V2BPwlXOmrbO4a-a43Eg5&index=33
# inner and left join koi bhi use kar sakte

SELECT u.name, SUM(amount) AS balance
FROM Transactions t
LEFT JOIN Users u
ON t.account = u.account
GROUP BY t.account
HAVING SUM(amount) > 10000;