SELECT 
	[customerNumber],
    [customerName],
    [contactLastName],
    [contactFirstName],
    [phone],
    [address],
    [city],
    [state],
    [postalCode],
    [country],
    [salesRepEmployeeNumber],
    [creditLimit]
FROM [customers]
WHERE [state] = 'CA' AND [country] = 'USA';