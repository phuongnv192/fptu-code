WITH [totalPayments] AS 
(
	SELECT 
		[customerNumber],
		SUM([amount]) AS [totalAmountOfPayments]
	FROM [payments]
	GROUP BY [customerNumber]
)

SELECT 
	[customers].[customerNumber],
	[customerName],
	[city],
	[country],
	[totalAmountOfPayments]
FROM 
	[customers]
	LEFT JOIN [totalPayments]
	ON [customers].[customerNumber] = [totalPayments].[customerNumber]
WHERE [country] = 'Germany'
ORDER BY [totalAmountOfPayments];