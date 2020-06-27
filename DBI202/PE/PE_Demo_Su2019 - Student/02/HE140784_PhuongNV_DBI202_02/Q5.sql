--USE [PE_Demo_S2019]
SELECT
	[ID],
	[OrderDate],
	[ShipDate],
	[ShipMode],
	[CustomerID]
FROM [Orders]
WHERE [OrderDate] = (SELECT MAX([OrderDate]) FROM [Orders]);