CREATE TRIGGER [tr_insertPayment] ON [payments]
AFTER INSERT 
AS
BEGIN
	SELECT
		[customers].[customerNumber],
		[customers].[customerName],
		INSERTED.[checkNumber],
		INSERTED.[paymentDate],
		INSERTED.[amount]
	FROM 
		[customers]
		INNER JOIN INSERTED
		ON [customers].[customerNumber] = INSERTED.[customerNumber]
END;

/*
INSERT INTO [payments]
VALUES
(103, 'HQ336364','2004-10-29',1000),
(112, 'QM789234','2005-10-30',200);
*/