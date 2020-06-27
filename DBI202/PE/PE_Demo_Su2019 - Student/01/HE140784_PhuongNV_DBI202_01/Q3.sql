--USE [PE_Demo_S2019]
SELECT [Customer].[ID]
      ,[CustomerName]
      ,[Segment]
      ,[Country]
      ,[City]
      ,[State]
      ,[PostalCode]
      ,[Region]
  FROM 
	[dbo].[Customer]
	INNER JOIN [Orders]
	ON [Customer].ID = [Orders].CustomerID
  WHERE 
	LEFT([CustomerName], 1) = 'B' 
	AND YEAR([Orders].OrderDate) = 2017 
	AND MONTH([Orders].OrderDate) = 12
  ORDER BY Segment DESC, CustomerName ASC;