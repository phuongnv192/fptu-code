/* Ngô Văn Phương - HE140784 */

/*   Question 1 - create DDL   */
--create database LAB4
--drop database LAB4
USE [LAB4]

CREATE TABLE [Departments](
	[DeptID] [varchar](4) NOT NULL,
	[Name] [nvarchar](50) NOT NULL,
	[NoOfStudents] [int] NULL,
 CONSTRAINT [PK_Departments] PRIMARY KEY (DeptID)
 );

CREATE TABLE [Students](
	[StudentID] [varchar](4) NOT NULL,
	[LastName] [nvarchar](30) NULL,
	[FirstName] [nvarchar](20) NULL,
	[Sex] [varchar](1) NULL,
	[DateOfBirth] [date] NULL,
	[PlaceOfBirth] [nvarchar](30) NULL,
	[DeptID] [varchar](4) NULL,
	[Scholarship] [float] NULL,
	[AverageScore] [numeric](4, 2) NULL,
 CONSTRAINT [PK_Students] PRIMARY KEY (StudentID),
 CONSTRAINT [Check_Sex] CHECK (Sex IN ('F','M')),
 CONSTRAINT FK_DeptID FOREIGN KEY (DeptID) REFERENCES Departments(DeptID)
);

CREATE TABLE [Courses](
	[CourseID] [varchar](4) NOT NULL,
	[Name] [nvarchar](35) NULL,
	[Credits] [tinyint] NULL,
 CONSTRAINT [PK_Courses] PRIMARY KEY (CourseID)
);

CREATE TABLE [Results](
	[StudentID] [varchar](4) NOT NULL,
	[CourseID] [varchar](4) NOT NULL,
	[Year] [int] NOT NULL,
	[Semester] [int] NOT NULL,
	[Mark] [float] CHECK (Mark >= 0 AND Mark <= 10) NULL,
	[Grade] [varchar](6) NULL,
 CONSTRAINT [PK_Results] PRIMARY KEY ([StudentID],[CourseID],[Year],[Semester]),
 CONSTRAINT FK_CourseID FOREIGN KEY (CourseID) REFERENCES Courses(CourseID),
 CONSTRAINT FK_StudentID FOREIGN KEY (StudentID) REFERENCES Students(StudentID)
);

/* create DML   */
USE LAB4

INSERT INTO [Departments] 
([DeptID], [Name])
VALUES
('IS', 'Information Systems'),
('NC', 'Network and Communication'),
('SE', 'Software Engineering'),
('CE', 'Computer Engineering'),
('CS', 'Computer Science')
;

INSERT INTO [Students] 
([StudentID],[LastName],[FirstName],[Sex],[DateOfBirth],[PlaceOfBirth],[DeptID],[Scholarship])
VALUES
('S001', N'Lê', N'Kim Lan', 'F', '1990-02-23', N'Hà nội', 'IS', 130000),
('S002', N'Trần', N'Minh Chánh', 'M', '1992-12-24', N'Bình Định', 'NC', 150000),
('S003', N'Lê', N'An Tuyết', 'F', '1991-02-21', N'Hải phòng', 'IS', 170000),
('S004', N'Trần', N'Anh Tuấn', 'M', '1993-12-20', 'TpHCM', 'NC', 80000),
('S005', N'Trần', N'Thị Mai', 'F', '1991-08-12', 'TpHCM', 'SE', 0),
('S006', N'Lê', N'Thị Thu Thủy', 'F', '1991-01-02', 'An Giang', 'IS', 0),
('S007', N'Nguyễn', N'Kim Thư', 'F', '1990-02-02', N'Hà Nội', 'SE', 180000),
('S008', N'Lê', N'Văn Long', 'M', '1992-12-08', 'TpHCM', 'IS', 190000)
;

INSERT INTO [Courses] 
([CourseID],[Name],[Credits])
VALUES
('DS01', 'Database Systems', 3),
('AI01', 'Artificial Intelligence', 3),
('CN01', 'Computer Network', 3),
('CG01', 'Computer Graphics', 4),
('DSA1', 'Data Structures and Algorithms', 4)
;

INSERT INTO [Results] 
([StudentID],[CourseID],[Year], [Semester], [Mark])
VALUES
('S001', 'DS01', 2017, 1, 3),
('S001', 'DS01', 2017, 2, 6),
('S001', 'AI01', 2017, 1, 4.5),
('S001', 'AI01', 2017, 2, 6),
('S001', 'CN01', 2017, 3, 5),
('S002', 'DS01', 2016, 1, 4.5),
('S002', 'DS01', 2017, 1, 7),
('S002', 'CN01', 2016, 3, 10),
('S002', 'DSA1', 2016, 3, 9),
('S003', 'DS01', 2017, 1, 2),
('S003', 'DS01', 2017, 3, 5),
('S003', 'CN01', 2017, 2, 2.5),
('S003', 'CN01', 2017, 3, 4),
('S004', 'DS01', 2017, 3, 4.5),
('S004', 'DSA1', 2018, 1, 10),
('S005', 'DS01', 2017, 2, 7),
('S005', 'CN01', 2017, 2, 2.5),
('S005', 'CN01', 2018, 1, 5),
('S006', 'AI01', 2018, 1, 6),
('S006', 'CN01', 2018, 2, 10)
;


/*   Question 2               */
USE LAB4

UPDATE [Departments]
SET [NoOfStudents] = 
(
SELECT COUNT(*)
FROM Students
GROUP BY DeptID HAVING Departments.DeptID = Students.DeptID
);
--SELECT * FROM Departments


/*   Question 3               */
USE LAB4

UPDATE [Students]
SET [AverageScore] =
(
SELECT AVG(MaxScore)
FROM 
	(
	SELECT StudentID, MAX(Mark) AS MaxScore
	FROM Results
	GROUP BY StudentID,CourseID
	) AS Results_Max
GROUP BY StudentID HAVING Results_Max.StudentID = Students.StudentID
);
--SELECT * FROM Students


/*   Question 4               */
USE LAB4

UPDATE [Results]
SET [Grade] = CASE WHEN Mark >= 5 AND Mark <= 10 THEN 'Passed' ELSE 'Failed' END;
--SELECT * FROM Results


/*   Question 5               */
USE LAB4

SELECT 
	StudentID,
	LastName + ' ' + FirstName AS 'Fullname',
	DateOfBirth, PlaceOfBirth,
	DeptID,
	Scholarship
FROM Students
WHERE Scholarship <= 160000
ORDER BY Scholarship DESC;


/*   Question 6               */
USE LAB4

SELECT 
	Departments.[DeptID],
	Departments.[Name] AS DepartmentName, 
	StudentID,
	LastName,
	FirstName
FROM Students
RIGHT JOIN Departments
ON Students.DeptID = Departments.DeptID;


/*   Question 7               */
USE LAB4

SELECT Students.StudentID, LastName, FirstName, A.NumberOfCourses
FROM 
	(
	SELECT StudentID, COUNT(StudentID) AS NumberOfCourses
	FROM Results
	GROUP BY StudentID
	) AS A
RIGHT JOIN Students
ON Students.StudentID = A.StudentID
ORDER BY NumberOfCourses ASC;


/*   Question 8               */
USE LAB4

SELECT 
	X.DeptID,
	X.[Name] AS DepartmentName,
	A.NumberOfFemaleStudents,
	B.NumberOfMaleStudents
FROM 
	Departments AS X
	LEFT JOIN 
		(
		SELECT DeptID, COUNT(Sex) AS NumberOfFemaleStudents
		FROM Students
		WHERE Sex = 'F'
		GROUP BY DeptID
		) AS A
	ON X.DeptID = A.DeptID
	LEFT JOIN 
		(
		SELECT DeptID, COUNT(Sex) AS NumberOfMaleStudents
		FROM Students
		WHERE Sex = 'M'
		GROUP BY DeptID
		) AS B
	ON X.DeptID = B.DeptID;


/*   Question 9               */
USE LAB4

SELECT 
	isNot_IS.DepartmentName,
	isNot_IS.StudentID,
	isNot_IS.FullName
FROM
	(
	SELECT 
		Students.StudentID,
		Students.LastName + ' ' + Students.FirstName AS FullName,
		Departments.[Name] AS DepartmentName,
		Results.Mark
	FROM
		Results
		FULL JOIN Students
		ON Students.StudentID = Results.StudentID
		INNER JOIN Departments
		ON Students.DeptID = Departments.DeptID
		INNER JOIN Courses
		ON Results.CourseID = Courses.CourseID
	WHERE Departments.[Name] != 'Information Systems' AND Courses.[Name] = 'Database Systems'
	) AS isNot_IS
	INNER JOIN 
	(
	SELECT 
		Students.StudentID,
		Students.LastName + ' ' + Students.FirstName AS FullName,
		Results.Mark
	FROM
		Students
		INNER JOIN Departments
		ON Students.DeptID = Departments.DeptID
		FULL JOIN Results
		ON Students.StudentID = Results.StudentID
	WHERE Departments.[Name] = 'Information Systems'
	) AS is_IS
	ON isNot_IS.Mark > is_IS.Mark
GROUP BY isNot_IS.DepartmentName, isNot_IS.StudentID, isNot_IS.FullName;

--OR

USE LAB4

SELECT 
	isNot_IS.StudentID,
	isNot_IS.FullName,
	isNot_IS.DepartmentName
FROM
	(
	SELECT 
		Students.StudentID,
		Students.LastName + ' ' + Students.FirstName AS FullName,
		Departments.[Name] AS DepartmentName,
		Results.Mark
	FROM
		Results
		FULL JOIN Students
		ON Students.StudentID = Results.StudentID
		INNER JOIN Departments
		ON Students.DeptID = Departments.DeptID
		INNER JOIN Courses
		ON Results.CourseID = Courses.CourseID
	WHERE Departments.[Name] != 'Information Systems' AND Courses.[Name] = 'Database Systems'
	) AS isNot_IS
WHERE isNot_IS.Mark >
	(
	SELECT MIN(Results.Mark)
	FROM
		Students
		INNER JOIN Departments
		ON Students.DeptID = Departments.DeptID
		FULL JOIN Results
		ON Students.StudentID = Results.StudentID
	WHERE Departments.[Name] = 'Information Systems'
	)
GROUP BY isNot_IS.StudentID, isNot_IS.FullName, isNot_IS.DepartmentName;


/*   Question 10              */
USE LAB4

SELECT 
	Students_List.CourseID,
	Courses.[Name] AS CourseName, 
	Students_List.FullName AS BestStudentFullName
	--,Course_MaxScore.MaxScore
FROM 
	Courses
	LEFT JOIN 
		(
		SELECT 
			Students.StudentID, 
			Students.LastName + ' ' + Students.FirstName AS FullName, 
			Results.CourseID,
			Results.Mark
		FROM Students
		INNER JOIN Results
		ON Students.StudentID = Results.StudentID
		) AS Students_List
	ON Courses.CourseID = Students_List.CourseID
	INNER JOIN 
		(	
		SELECT CourseID, MAX(Mark) AS MaxScore
		FROM Results
		GROUP BY CourseID
		) AS Course_MaxScore
	ON Students_List.CourseID = Course_MaxScore.CourseID AND Students_List.Mark = Course_MaxScore.MaxScore
ORDER BY Students_List.CourseID;