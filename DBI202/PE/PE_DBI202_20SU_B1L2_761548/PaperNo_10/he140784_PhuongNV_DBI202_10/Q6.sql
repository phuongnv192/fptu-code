SELECT * 
FROM [employees]
EXCEPT
(
SELECT DISTINCT
	[employees].[employeeNumber],
	[employees].[lastName],
	[employees].[firstName],
	[employees].[email],
	[employees].[officeCode],
	[employees].[reportsTo],
	[employees].[jobTitle]
FROM 
	[customers]
	INNER JOIN [employees]
	ON [customers].[salesRepEmployeeNumber] = [employees].[employeeNumber]
)

