select (
    select      distinct salary
    from        employee
    where       salary <> (
        select  max(salary)
        from    employee
    )
    order by    salary desc
    limit       1
) as 'SecondHighestSalary';