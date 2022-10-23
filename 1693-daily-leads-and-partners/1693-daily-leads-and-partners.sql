# Write your MySQL query statement below
# refer this if needed => https://www.youtube.com/watch?v=eQrT3aOqI9E&list=PLtfxzVLWb-B_V2BPwlXOmrbO4a-a43Eg5&index=35

SELECT date_id, make_name, COUNT(DISTINCT lead_id) AS unique_leads, COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id, make_name
