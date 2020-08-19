DELETE FROM [products]
WHERE [productCode] = ANY 
	(
	SELECT [productCode]FROM products
	EXCEPT
	SELECT DISTINCT [productCode] FROM [orderdetails]
	);