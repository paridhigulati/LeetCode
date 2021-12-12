# Write your MySQL query statement below
SELECT max(salary) as secondhighestsalary
from Employee 
where salary < (select max(salary) from employee)

