SELECT 
	[orderNumber],
	[orderDate],
	[requiredDate],
	[shippedDate],
	[status],
	[orders].[customerNumber],
	[customerName],
	[city],
	[country]
FROM 
	[orders]
	INNER JOIN [customers]
	ON [orders].[customerNumber] = [customers].[customerNumber]
WHERE [country] = 'USA' AND [shippedDate] IS NULL
ORDER BY [customerName] ASC;