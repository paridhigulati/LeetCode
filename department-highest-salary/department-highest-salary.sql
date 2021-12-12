# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.Salary
from Employee e, Department d
where e.Departmentid = d.id
and e.salary = (select max(salary) from Employee e2 where e2.departmentid =d.id)


