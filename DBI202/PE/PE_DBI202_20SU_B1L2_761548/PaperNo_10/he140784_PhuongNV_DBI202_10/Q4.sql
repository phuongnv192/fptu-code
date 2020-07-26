SELECT 
	[orderNumber],
	[orderDate],
	[requiredDate],
	[shippedDate],
	[status],
	[orders].[customerNumber],
	[customers].[customerName],
	[customers].[city],
	[customers].[country]
FROM 
	[orders]
	INNER JOIN [customers]
	ON [orders].[customerNumber] = [customers].[customerNumber]
WHERE 
	[customers].[country] = 'USA'
	AND [status] != 'Shipped'
	AND	[status] != 'Resolved'
ORDER BY [customers].[customerName];