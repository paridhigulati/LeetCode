# Write your MySQL query statement below
/* we want top 3 salaries of each department and name of all the employes which lie in that salary range*/

SELECT D.name as Department, E1.name as Employee, E1.Salary as Salary
from employee as E1, Department as D
WHERE 
(
    SELECT count(distinct E2.Salary) from Employee as E2
    where 
    e1.DepartmentId = e2.DepartmentId and e2.Salary > e1.Salary
) < 3
and 
E1.DepartmentId = D.Id