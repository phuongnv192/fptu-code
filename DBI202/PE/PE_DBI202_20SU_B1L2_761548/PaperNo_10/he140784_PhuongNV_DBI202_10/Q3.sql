SELECT
	[orderNumber],
	[productCode],
	[quantityOrdered],
	[priceEach]
FROM [orderdetails]
WHERE [productCode] = 'S18_1749' AND [quantityOrdered] > 25
ORDER BY [priceEach] ASC, [quantityOrdered] DESC;