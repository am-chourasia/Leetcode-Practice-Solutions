select          name as 'Customers'
from            Customers
where not exists(
    select      1
    from        Orders
    where       Customers.id = Orders.customerId
);