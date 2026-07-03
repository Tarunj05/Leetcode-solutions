# Write your MySQL query statement below
SELECT  customer_id , count(customer_id) as count_no_trans
FROM Visits
left join
transactions
on Visits.visit_id = transactions.visit_id
where transaction_id is NULL
group by customer_id;