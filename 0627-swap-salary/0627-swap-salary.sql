# Write your MySQL query statement below
# refer this if needed => https://www.youtube.com/watch?v=2AnzabKXZRs&list=PLtfxzVLWb-B_V2BPwlXOmrbO4a-a43Eg5&index=16

UPDATE Salary
SET sex = CASE WHEN sex = 'f' THEN 'm'    WHEN sex = 'm' THEN 'f' END;