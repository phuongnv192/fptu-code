SELECT
	[products].[productCode],
	[products].[productName],
	[products].[productCategory]
FROM 
	[products]

SELECT * FROM orderdetails
SELECT 
	[productCode],
	COUNT([productCode]) AS [numberOfOrders],
	SUM([quantityOrdered]) AS [totalQuantityOrdered]
FROM orderdetails
GROUP BY [productCode]
ORDER BY [productCode]