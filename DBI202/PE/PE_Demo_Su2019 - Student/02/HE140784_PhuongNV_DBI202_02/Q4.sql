--USE [PE_Demo_S2019]
SELECT
	[OrderID],
	[Orders].OrderDate,
	[TotalAmount]
FROM 
	(
	SELECT
		[OrderID],
		SUM([Quantity]*[SalePrice]*(1-[Discount])) AS [TotalAmount]
	FROM [OrderDetails]
	GROUP BY [OrderID]
	) AS [Total_Ords]
	INNER JOIN [Orders]
	ON [Total_Ords].OrderID = [Orders].ID
WHERE [TotalAmount] > 8000
ORDER BY [TotalAmount] DESC;