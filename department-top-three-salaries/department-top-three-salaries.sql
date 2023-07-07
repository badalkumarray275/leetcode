# Write your MySQL query statement below
select d.name as Department ,e1.name as Employee, e1.Salary from Employee as e1 inner join Department as d on d.id = e1.departmentId where  
(select count(distinct (salary)) from Employee as e2 where e1.salary<e2.salary and DepartmentId = e1.DepartmentId)<3 ;