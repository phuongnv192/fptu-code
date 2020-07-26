WITH [TotalByID] AS 
(
SELECT 
	[customerNumber],
	[orders].[orderNumber],
	A.[Total] AS [newTotal]
FROM 
	[orders]
	INNER JOIN
	(
	SELECT 
		[orderNumber],
		SUM([orderdetails].[quantityOrdered]*[orderdetails].[priceEach]) AS [Total]
	FROM [orderdetails]
	GROUP BY [orderNumber]
	) AS A
	ON [orders].[orderNumber] = A.[orderNumber]
)

SELECT 
	[customers].[customerNumber],
	[customers].[customerName],
	[customers].[city],
	[customers].[country],
	[FinalTotal].[totalAmountOfPayments]
FROM 
	[customers]
	LEFT JOIN 
	(
	SELECT 
		[customerNumber],
		SUM([newTotal]) AS [totalAmountOfPayments]
	FROM [TotalByID]
	GROUP BY [customerNumber]
	) AS [FinalTotal]
	ON [customers].[customerNumber] = [FinalTotal].[customerNumber]
WHERE [customers].[country] = 'Germany'
ORDER BY [totalAmountOfPayments] ASC;