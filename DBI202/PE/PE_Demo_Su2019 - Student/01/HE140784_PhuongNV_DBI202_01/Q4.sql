--USE [PE_Demo_S2019]
SELECT 
	[Sum_SubCat].SubCategoryID,
    [SubCategory].[SubCategoryName],
	[Sum_SubCat].NumberOfProducts
FROM
	[dbo].[SubCategory]
	INNER JOIN 
	(
	SELECT
		[SubCategoryID],
		COUNT(*) AS [NumberOfProducts]
	FROM [PE_Demo_S2019].[dbo].[Product]
	GROUP BY [SubCategoryID] HAVING COUNT(*) > 100
	) AS [Sum_SubCat]
	ON [Sum_SubCat].SubCategoryID = [SubCategory].ID
ORDER BY [Sum_SubCat].NumberOfProducts DESC;