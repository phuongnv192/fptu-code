--USE [PE_Demo_S2019]
SELECT *
FROM
	(
	SELECT TOP 5
		[SubCategoryID],
		COUNT([SubCategoryID]) AS [NumberOfProducts]
	FROM [Product]
	GROUP BY [SubCategoryID]
	ORDER BY [NumberOfProducts] DESC
	) AS [Highest_Num]
UNION ALL
SELECT *
FROM
	(
	SELECT TOP 5
		[SubCategoryID],
		COUNT([SubCategoryID]) AS [NumberOfProducts]
	FROM [Product]
	GROUP BY [SubCategoryID]
	ORDER BY [NumberOfProducts] ASC
	) AS [Lowest_Num]
ORDER BY [NumberOfProducts] DESC;