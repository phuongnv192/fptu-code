--USE [PE_Demo_S2019]
SELECT
	[Customer].ID,
	[Customer].CustomerName,
	[Count_Ord].NumberOfOrders
FROM
	(
	SELECT
		CustomerID,
		COUNT(CustomerID) AS NumberOfOrders
	FROM [Orders]
	GROUP BY CustomerID 
	) AS Count_Ord	
	INNER JOIN
	[Customer]
	ON [Customer].ID = [Count_Ord].CustomerID
WHERE [Count_Ord].NumberOfOrders = 
	(
	SELECT MAX(Ord_Num)
	FROM
		(
		SELECT
			COUNT(CustomerID) AS Ord_Num
		FROM [Orders]
		GROUP BY CustomerID 
		) AS Max_Ord	
	);