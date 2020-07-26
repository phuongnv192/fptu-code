CREATE PROCEDURE [proc_numberOfOrders]
	@customerNumber int,
	@numberOfOrders int OUT
AS
BEGIN
	SET @numberOfOrders = 
	(
	SELECT 
		COUNT([customerNumber]) AS NumberOfOrders
	FROM [orders]
	GROUP BY [customerNumber]
	HAVING [customerNumber] = @customerNumber
	)
END;

/*
declare @x int
exec proc_numberOfOrders 103, @x output
select @x as NumberOfOrders
*/