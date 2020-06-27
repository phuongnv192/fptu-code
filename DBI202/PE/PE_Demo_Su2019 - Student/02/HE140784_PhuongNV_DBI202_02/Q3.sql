--USE [PE_Demo_S2019]
SELECT [Customer].[ID]
      ,[CustomerName]
      ,[City]
      ,[State]
FROM 
	[Customer]
	INNER JOIN [Orders]
	ON [Customer].ID = [Orders].CustomerID
WHERE [OrderDate] BETWEEN '2017-12-5' AND '2017-12-10' AND DATEDIFF(day,[OrderDate],[ShipDate]) < 3
ORDER BY [State] ASC, [City] DESC;