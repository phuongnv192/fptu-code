DELETE FROM [products]
WHERE [products].productCode != any (
SELECT 
	[products].productCode
FROM 
	[products]
	JOIN [orderdetails]
	ON [products].[productCode] = [orderdetails].[productCode]
)


