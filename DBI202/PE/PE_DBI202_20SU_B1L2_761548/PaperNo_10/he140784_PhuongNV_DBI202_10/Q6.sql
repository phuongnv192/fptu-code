(
	SELECT
		[employeeNumber],
		[lastName],
		[firstName],
		[email],
		[officeCode],
		[reportsTo],
		[jobTitle]
	FROM [employees]
)
EXCEPT
(
	SELECT
		[employeeNumber],
		[lastName],
		[firstName],
		[email],
		[officeCode],
		[reportsTo],
		[jobTitle]
	FROM [employees]
	WHERE [employeeNumber] = ANY (SELECT DISTINCT [salesRepEmployeeNumber] FROM [customers])
);