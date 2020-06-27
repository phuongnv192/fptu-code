--USE [PE_Demo_S2019]
SELECT
	[Prd_MaxQ].ProductID,
	[Product].ProductName,
	[Quantity]
FROM
	[Product]
	INNER JOIN 
	(
	SELECT
		[ProductID],
		[Quantity]
	FROM [OrderDetails]
	WHERE Quantity = (SELECT MAX(Quantity) FROM OrderDetails)
	) AS Prd_MaxQ
	ON [Product].ID = [Prd_MaxQ].ProductID;