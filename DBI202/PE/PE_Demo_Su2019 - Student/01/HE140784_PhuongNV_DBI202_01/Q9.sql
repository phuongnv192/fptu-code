CREATE TRIGGER [InsertProduct] ON [Product]
AFTER INSERT
AS
BEGIN
	SELECT 
		INSERTED.[ProductName],
		[SubCategory].[SubCategoryName]
	FROM 
		INSERTED
		INNER JOIN [SubCategory]
		ON INSERTED.[SubCategoryID] = [SubCategory].[ID]
END;

insert into Product(ProductName, UnitPrice, SubCategoryID)
values ('Craft paper', 0.5, 3)
