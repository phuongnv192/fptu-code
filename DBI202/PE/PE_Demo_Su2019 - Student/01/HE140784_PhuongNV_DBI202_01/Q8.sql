CREATE PROCEDURE CountProduct 
	@OrderID nvarchar(255),
	@NbProducts int OUT
AS
BEGIN
	SET @NbProducts = 
		(
		SELECT COUNT([OrderDetails].[ProductID])
		FROM [OrderDetails]
		WHERE [OrderID] = @OrderID
		)
END;

/*
declare @t int
exec CountProduct 'CA-2014-100391', @t output 
print @t
*/