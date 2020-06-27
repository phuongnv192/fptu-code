--USE [PE_Demo_S2019]
SELECT * 
  FROM
	(
	SELECT TOP 5 *
	FROM [Product]
	ORDER BY UnitPrice DESC
	) AS Highest_Price
UNION ALL
SELECT * 
  FROM
	(
	SELECT TOP 5 *	
	FROM [Product]
	ORDER BY UnitPrice ASC
	) AS Lowest_Price
ORDER BY UnitPrice DESC;