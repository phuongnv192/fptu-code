--USE [PE_Demo_S2019]
SELECT
	[Count_Ords].ProductID,
	[Product].ProductName,
	[NumberOfOrders]
FROM 
	[Product]
	INNER JOIN
	(
	SELECT 
		[OrderDetails].ProductID,
		COUNT([ProductID]) AS [NumberOfOrders]
	FROM [OrderDetails]	
	GROUP BY [ProductID]
	) AS Count_Ords
	ON [Product].ID = [Count_Ords].ProductID
WHERE [Count_Ords].NumberOfOrders = 
	(
	SELECT MIN([Ord_Num])
	FROM 
		(
		SELECT COUNT([ProductID]) AS [Ord_Num]
		FROM [OrderDetails]	
		GROUP BY [ProductID]
		) AS X
	)
ORDER BY [Count_Ords].ProductID ASC;