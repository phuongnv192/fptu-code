CREATE TRIGGER [InsertSubCategory] ON [SubCategory]
AFTER INSERT
AS
BEGIN
	SELECT
		[SubCategory].[SubCategoryName],
		[Category].[CategoryName]
	FROM
		[SubCategory]
		INNER JOIN [Category]
		ON [SubCategory].[CategoryID] = [Category].[ID]
		INNER JOIN INSERTED
		ON [SubCategory].[ID] = INSERTED.[ID]
END;

/*
insert into SubCategory(SubCategoryName, CategoryID)
values ('Beds',2)
*/