select      employee_id
from        Employees
where       employee_id
not in      (
    select  S.employee_id
    from    Salaries as S
)

union

select      employee_id
from        Salaries
where       employee_id
not in      (
    select  E.employee_id
    from    Employees as E
)

order by    employee_id;