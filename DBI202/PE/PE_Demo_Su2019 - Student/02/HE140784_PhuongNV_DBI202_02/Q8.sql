CREATE PROCEDURE TotalAmount 
	@OrderID nvarchar(255),
	@TotalAmount float OUT
AS
BEGIN
	SET @TotalAmount = 
		(
		SELECT SUM(X.[Total])
		FROM 
			(
			SELECT 
				[OrderDetails].[SalePrice]*[OrderDetails].[Quantity]*(1-[OrderDetails].[Discount]) AS [Total]
			FROM [OrderDetails]
			WHERE [OrderDetails].[OrderID] = @OrderID
			) AS X
		)
END;

/*
declare @t float
exec TotalAMount 'CA-2014-100006', @t output 
print @t
*/