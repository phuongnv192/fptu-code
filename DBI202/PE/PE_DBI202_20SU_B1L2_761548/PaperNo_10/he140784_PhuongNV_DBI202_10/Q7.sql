WITH [raw_table] AS
(
	SELECT
		[orderNumber],
		[orderdetails].[productCode],
		[productName],
		[productCategory],
		[quantityOrdered],
		([priceEach] - [buyPrice]) * [quantityOrdered] AS [profit]
	FROM 
		[orderdetails]
		INNER JOIN [products]
		ON [orderdetails].[productCode] = [products].[productCode]
	WHERE [productCategory] = 'Planes'
)

SELECT
	[productCode],
	[productName],
	[productCategory],
	COUNT(*) AS [numberOfOrders],
	COUNT([orderNumber]) AS [numberOfCustomers],
	SUM([quantityOrdered]) AS [totalQuantityOrdered],
	SUM([profit]) AS [totalProfit]
FROM [raw_table]
GROUP BY [productCode], [productName], [productCategory]
ORDER BY [totalProfit] DESC;