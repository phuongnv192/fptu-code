/* Ngô Văn Phương - HE140784 */
--CREATE DATABASE LAB5
--USE LAB5

/* create DDL */
CREATE TABLE [NhanVien] (
	[HoNV] [nvarchar](15) NULL,
	[TenLot] [nvarchar](20) NULL,
	[Ten] [nvarchar](15) NULL,
	[MaNV] [int] NOT NULL,
	[NgSinh] [date] NULL,
	[DiaChi] [nvarchar](200) NULL,
	[Phai] [nvarchar](3) NULL,
	[Luong] [int] NULL,
	[Ma_NQL] [int] NULL,
	[Phg] [tinyint] NULL,
 CONSTRAINT [PK_NhanVien] PRIMARY KEY ([MaNV]),
 CONSTRAINT [FK_NhanVien_MaNQL] FOREIGN KEY ([Ma_NQL]) REFERENCES [NhanVien]([MaNV])
);

CREATE TABLE [PhongBan](
	[TenPhg] [nvarchar](50) NULL,
	[MaPh] [tinyint] NOT NULL,
	[TrPhg] [int] NULL,
	[Ng_NhanChuc] [date] NULL,
 CONSTRAINT [PK_PhongBan] PRIMARY KEY ([MaPh]),
 CONSTRAINT [FK_PhongBan_TrPhg] FOREIGN KEY ([TrPhg]) REFERENCES [NhanVien]([MaNV])
);

CREATE TABLE [DiaDiem_Phg](
	[MaPhg] [tinyint] NOT NULL,
	[DiaDiem] [nvarchar](20) NOT NULL,
 CONSTRAINT [PK_DiaDiem_Phg] PRIMARY KEY ([MaPhg],[DiaDiem]),
 CONSTRAINT [FK_DiaDiem_Phg_MaPhg] FOREIGN KEY ([MaPhg]) REFERENCES [PhongBan]([MaPh])
);

CREATE TABLE [ThanNhan](
	[Ma_NVien] [int] NOT NULL,
	[TenTN] [nvarchar](20) NOT NULL,
	[Phai] [nvarchar](3) NULL,
	[NgSinh] [date] NULL,
	[QuanHe] [nvarchar](15) NULL,
 CONSTRAINT [PK_ThanNhan] PRIMARY KEY ([Ma_NVien],[TenTN]),
 CONSTRAINT [FK_ThanNhan_MaNVien] FOREIGN KEY ([Ma_NVien]) REFERENCES [NhanVien]([MaNV])
);

CREATE TABLE [DeAn](
	[TenDA] [nvarchar](30) NULL,
	[MaDA] [tinyint] NOT NULL,
	[DDiem_DA] [nvarchar](20) NULL,
	[Phong] [tinyint] NULL
 CONSTRAINT [PK_DeAn] PRIMARY KEY ([MaDA]),
 CONSTRAINT [FK_DeAn_Phong] FOREIGN KEY ([Phong]) REFERENCES [PhongBan]([MaPh])
);

CREATE TABLE [PhanCong](
	[Ma_NVien] [int] NOT NULL,
	[SoDA] [tinyint] NOT NULL,
	[ThoiGian] [float] NULL,
 CONSTRAINT [PK_PhanCong] PRIMARY KEY ([Ma_NVien],[SoDA]),
 CONSTRAINT [FK_PhanCong_MaNVien] FOREIGN KEY ([Ma_NVien]) REFERENCES [NhanVien]([MaNV]),
 CONSTRAINT [FK_PhanCong_SoDA] FOREIGN KEY ([SoDA]) REFERENCES [DeAn]([MaDA])
);

/* create DML   */
USE LAB5

INSERT INTO [NhanVien] (
	[HoNV],
	[TenLot],
	[Ten],
	[MaNV],
	[NgSinh],
	[DiaChi],
	[Phai],
	[Luong],
	[Ma_NQL],
	[Phg])
VALUES
	('Dinh', 'Ba', 'Tien',123456789,'1955-01-09', '731 Tran Hung Dao, Q1, TP HCM', 'Nam', 30000,333445555, 5),
	('Nguyen', 'Thanh', 'Tung',333445555,'1945-12-08', '638 Nguyen Van Cu, Q5, TP HCM', 'Nam', 40000,888665555, 5),
	('Bui', 'Thuy', 'Vu',999887777,'1958-07-19', '332 Nguyen Thai Hoc, Q1, TP HCM', 'Nam', 25000,987654321, 4),
	('Le', 'Thi', 'Nhan',987654321,'1931-06-20', '291 Ho Van Hue, QPN, TP HCM', 'Nu', 43000,888665555, 4),
	('Nguyen', 'Manh', 'Hung',666884444,'1952-09-15', '975 Ba Ria, Vung Tau', 'Nam', 38000,333445555, 5),
	('Tran', 'Thanh', 'Tam',453453453,'1962-07-31', '543 Mai Thi Luu, Q1, TP HCM', 'Nam', 25000,333445555, 5),
	('Tran', 'Hong', 'Quan',987987987,'1959-03-29', '980 Le Hong Phong, Q10, TP HCM', 'Nam', 25000,987654321, 4),
	('Vuong', 'Ngoc', 'Quyen',888665555,'1927-10-10', '450 Trung Vuong, Ha Noi', 'Nu', 55000,NULL, 1);

INSERT INTO [PhongBan] (
	[TenPhg],
	[MaPh],
	[TrPhg],
	[Ng_NhanChuc])
VALUES
	('Nghien cuu', 5, 333445555, '1978-05-22'),
	('Dieu hanh', 4, 987987987, '1985-01-01'),
	('Quan ly', 1, 888665555, '1971-06-19');

INSERT INTO [DiaDiem_Phg] (
	[MaPhg],
	[DiaDiem])
VALUES
	(1, 'TP HCM'),
	(4, 'Ha Noi'),
	(5, 'Vung Tau'),
	(5, 'Nha Trang'),
	(5, 'TP HCM');

INSERT INTO [ThanNhan] (
	[Ma_NVien],
    [TenTN],
    [Phai],
    [NgSinh],
    [QuanHe])
VALUES
	(333445555,'Quang', 'Nu', '1976-04-05', 'Con gai'),
	(333445555,'Khang', 'Nam', '1973-10-25', 'Con trai'),
	(333445555,'Duong', 'Nu', '1948-05-03', 'Vo chong'),
	(987654321,'Dang', 'Nam', '1932-02-29', 'Vo chong'),
	(123456789,'Duy', 'Nam', '1978-01-01', 'Con trai'),
	(123456789,'Chau', 'Nu', '1978-12-31', 'Con gai');

INSERT INTO [DeAn] (
	[TenDA],
	[MaDA],
	[DDiem_DA],
	[Phong])
VALUES
	('San pham X', 1, 'Vung Tau', 5),
	('San pham Y', 2, 'Nha Trang', 5),
	('San pham Z', 3, 'TP HCM', 5),
	('Tin hoc hoa', 10, 'Ha Noi', 4),
	('Cap quang', 20, 'TP HCM', 1),
	('Dao tao', 30, 'Ha Noi', 4);

INSERT INTO [PhanCong] (
	[Ma_NVien],
	[SoDA],
	[ThoiGian])
VALUES
	(123456789, 1, 32.5),
	(123456789, 2, 7.5),
	(666884444, 3, 40),
	(453453453, 1, 20),
	(453453453, 2, 20),
	(333445555, 3, 10),
	(333445555, 10, 10),
	(333445555, 20, 10),
	(999887777, 30, 30),
	(999887777, 10, 10),
	(987987987, 10, 35),
	(987987987, 30, 5),
	(987654321, 30, 20),
	(987654321, 20, 15),
	(888665555, 20, null);

/* I.1 - SP_1 */
CREATE PROCEDURE SP_1
	@s Date,
	@f Date
AS
BEGIN
	SELECT
		A.[MaNV],
		A.[Ten],
		A.[NgSinh],
		A.[Ma_NQL] AS [Supervisor’s ID],
		B.[Ten] AS [Supervisor’s Name]
	FROM 
		[NhanVien] AS A
		LEFT JOIN
		[NhanVien] AS B
		ON A.[Ma_NQL] = B.[MaNV]
		INNER JOIN [PhongBan]
		ON A.[Phg] = [PhongBan].[MaPh]
	WHERE [PhongBan].[Ng_NhanChuc] >= @s AND [PhongBan].[Ng_NhanChuc] <= @f;
END;

--USE LAB5
--EXEC SP_1 '1971-01-01', '1971-12-31'

/* I.2 - SP_2 */
CREATE PROCEDURE SP_2
AS
BEGIN
	SELECT
		[MaNV],
		[Ten],
		[Luong]
	FROM [NhanVien]
	WHERE [Luong] > 
		(
		SELECT
			AVG(X.[Luong])
		FROM [NhanVien] AS X
		GROUP BY [Phg] HAVING [NhanVien].[Phg] = X.[Phg]
		);
END;

--USE LAB5
--EXEC SP_2

/* I.3 - SP_3 */
CREATE PROCEDURE SP_3 @n int
AS
BEGIN
	SELECT TOP (@n)
		[MaNV],
		[Ten],
		[Luong]
	FROM [NhanVien]
	ORDER BY [Luong] DESC;
END;

--USE LAB5
--EXEC SP_3 6

/* I.4 - SP_4 */
CREATE PROCEDURE SP_4 
	@city nvarchar(20)
AS
BEGIN
	UPDATE [NhanVien]
	SET [Luong] = [Luong]*1.1
	WHERE [NhanVien].[Phg] = any 
		(
		SELECT DISTINCT [MaPhg]
		FROM
			[NhanVien] AS X
			JOIN [DiaDiem_Phg]
			ON X.[Phg] = [DiaDiem_Phg].[MaPhg]
		WHERE [DiaDiem_Phg].[DiaDiem] = @city
		)
END;

/* reset salary */
CREATE PROCEDURE SP_4_reset 
	@city nvarchar(20)
AS
BEGIN
	UPDATE [NhanVien]
	SET [Luong] = [Luong]/1.1
	WHERE [NhanVien].[Phg] = any 
		(
		SELECT DISTINCT [MaPhg]
		FROM
			[NhanVien] AS X
			JOIN [DiaDiem_Phg]
			ON X.[Phg] = [DiaDiem_Phg].[MaPhg]
		WHERE [DiaDiem_Phg].[DiaDiem] = @city
		)
END;

--USE LAB5
/*
EXEC SP_4 'Ha Noi'
SELECT *
FROM
	[NhanVien]
	JOIN [DiaDiem_Phg]
	ON [NhanVien].[Phg] = [DiaDiem_Phg].[MaPhg]
WHERE [DiaDiem_Phg].[DiaDiem] = 'Ha Noi'
ORDER BY [MaNV]
EXEC SP_4_reset 'Ha Noi'
*/

/* I.5 - SP_5 */

/* nhập dữ liệu phòng số 6: không có nhân viên làm
INSERT INTO [PhongBan] VALUES ('Phuong', 6, 987987987,'2020-07-11');
INSERT INTO [DeAn] VALUES ('de an x', 69, 'Da Nang', 6);
INSERT INTO [PhanCong] VALUES (123456789, 69, 32.5);
INSERT INTO [DiaDiem_Phg] VALUES (6, 'Hung Yen');
SELECT * FROM PhongBan;
SELECT * FROM DeAn;
SELECT * FROM PhanCong;
SELECT * FROM DiaDiem_Phg; */

CREATE PROCEDURE SP_5
AS
BEGIN
	/* create new table to count employees by department */
	CREATE TABLE [count_emp] (
		[MaPh] tinyint not null PRIMARY KEY,
		[Emp_num] int not null);
	INSERT INTO [count_emp]
	SELECT * FROM
		(
		SELECT
			[PhongBan].[MaPh],
			COUNT([NhanVien].[Phg]) AS Num_Employees
		FROM 
			[PhongBan]
			LEFT JOIN [NhanVien]
			ON [PhongBan].[MaPh] = [NhanVien].[Phg]
		GROUP BY [PhongBan].[MaPh]
		) AS X;

	DELETE FROM [PhanCong] --[PhanCong] dẫn FK về [DeAn] nên xóa trước
	WHERE [PhanCong].[SoDA] =
		(
		SELECT [DeAn].[MaDA]
		FROM [DeAn]
		WHERE [DeAn].[Phong] = (SELECT [MaPh] FROM [count_emp] WHERE [Emp_num] = 0)
		);
	DELETE FROM [DeAn] --[DeAn] dẫn FK về [PhongBan] nên xóa trước
	WHERE [DeAn].[Phong] = (SELECT [MaPh] FROM [count_emp] WHERE [Emp_num] = 0);
	DELETE FROM [DiaDiem_Phg] --[DiaDiem_Phg] dẫn FK về [PhongBan] nên xóa trước
	WHERE [DiaDiem_Phg].[MaPhg] = (SELECT [MaPh] FROM [count_emp] WHERE [Emp_num] = 0);
	DELETE FROM [PhongBan]
	WHERE [PhongBan].[MaPh] = (SELECT [MaPh] FROM [count_emp] WHERE [Emp_num] = 0);
	DROP TABLE [count_emp];
END;

/*
EXEC SP_5;
SELECT * FROM PhongBan;
SELECT * FROM DeAn;
SELECT * FROM PhanCong;
SELECT * FROM DiaDiem_Phg;
*/

/* II.1 */
CREATE TRIGGER [tr_1_Salary] ON [NhanVien]
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
	IF 
		( --lấy ra lương trung bình
		SELECT AVG([NhanVien].[Luong])
		FROM [NhanVien]
		WHERE [NhanVien].[Phg] = (SELECT INSERTED.[Phg] FROM INSERTED) -- của department có nhân viên trên
			OR [NhanVien].[Phg] = (SELECT DELETED.[Phg] FROM DELETED)
		) >= 50000
	BEGIN
		PRINT 'Average salary of each department must be fewer than 50000'
		ROLLBACK TRANSACTION
	END;
END;

/*
INSERT INTO [NhanVien]
VALUES ('aaa', 'bbb', 'ccc',111111111,'1966-06-06', 'FPT Hoa Lac', 'Nam', 120000,333445555, 4);
INSERT INTO [NhanVien]
VALUES ('ddd', 'eee', 'fff',222222222,'1966-06-06', 'xxx', 'Nam', 3000,333445555, 4);

SELECT * FROM [NhanVien]

SELECT 
	[Phg] AS [Department],
	AVG([Luong]) AS [Avg_Salary]
FROM [NhanVien]
GROUP BY [Phg]
*/


/* II.2 */

CREATE TRIGGER [tr_2_Salary] ON [NhanVien]
AFTER INSERT, DELETE, UPDATE
AS

IF 
	(
	SELECT COUNT(*) --đếm số phòng ban có lương trưởng phòng < nhân viên
	FROM
		(
		SELECT *
		FROM
			( --lấy ra lương của từng trưởng phòng
			SELECT
				[PhongBan].[MaPh],
				[NhanVien].[Luong] AS [Head_salary]
			FROM 
				[PhongBan]
				INNER JOIN [NhanVien]
				ON [PhongBan].[TrPhg] = [NhanVien].[MaNV]
			) AS [Dept_Head_salary]
			LEFT JOIN
			( --lấy ra lương của nhân viên theo từng phòng, không tính trưởng phòng
			SELECT
				[NhanVien].[Phg],
				[NhanVien].[Luong]
			FROM 
				[NhanVien]
				INNER JOIN [PhongBan]
				ON [PhongBan].[MaPh] = [NhanVien].[Phg]
			WHERE [NhanVien].[MaNV] != [PhongBan].[TrPhg]
			) AS [Emp_Salary_except_head]
			ON [Dept_Head_salary].[MaPh] = [Emp_Salary_except_head].[Phg]
		WHERE [Dept_Head_salary].[Head_salary] < [Emp_Salary_except_head].[Luong]
			AND (
				[Dept_Head_salary].[MaPh] = (SELECT INSERTED.[Phg] FROM INSERTED)
				OR [Dept_Head_salary].[MaPh] = (SELECT DELETED.[Phg] FROM DELETED))
		) AS [Table_should_empty] --lấy ra danh sách phòng ban có lương trưởng phòng < nhân viên
	) > 0	
BEGIN
	PRINT 'The salary of the head of each department must be greater than or equal to salary of all employees in this department.'
	ROLLBACK TRANSACTION
END;

/*
UPDATE [NhanVien] SET [Luong] = 25000 WHERE [MaNV] = 987987987
*/

/* II.3 */
CREATE TRIGGER [tr_3_Salary_diff] ON [NhanVien]
AFTER INSERT, DELETE, UPDATE
AS
BEGIN
	DECLARE @diff float;
	DECLARE @avg_hn float;
	DECLARE @avg_hcm float;
	
	SET @avg_hn = 
		(
		SELECT 
			AVG([NhanVien].[Luong])
		FROM 
			[NhanVien]
			INNER JOIN [DiaDiem_Phg]
			ON [NhanVien].[Phg] = [DiaDiem_Phg].[MaPhg]
		WHERE [DiaDiem_Phg].[DiaDiem] = 'Ha Noi'
		)
	SET @avg_hcm = 
		(
		SELECT 
			AVG([NhanVien].[Luong])
		FROM 
			[NhanVien]
			INNER JOIN [DiaDiem_Phg]
			ON [NhanVien].[Phg] = [DiaDiem_Phg].[MaPhg]
		WHERE [DiaDiem_Phg].[DiaDiem] = 'TP HCM'
		)
	SET @diff = @avg_hn - @avg_hcm
	IF  @diff >= 10000 OR @diff <= -10000
	BEGIN
		PRINT 'The different between average salary of employees in HCM and HN must fewer than 10000'
		ROLLBACK TRANSACTION
	END;
END;
/*
INSERT INTO [NhanVien]
VALUES ('ddd', 'eee', 'fff',222222262,'1966-06-06', 'xxx', 'Nam', 9000000,333445555, 4);
*/

/* II.4 */
CREATE TRIGGER [tr_4_ThanNhan] ON [ThanNhan]
AFTER INSERT, UPDATE
AS
IF	(
	SELECT [Count_Familiars].[Familiars]
	FROM
		(
		SELECT [Ma_NVien], COUNT([Ma_NVien]) AS [Familiars]
		FROM [ThanNhan]
		GROUP BY [Ma_NVien]
		) AS [Count_Familiars]
		INNER JOIN INSERTED
		ON INSERTED.[Ma_NVien] = [Count_Familiars].[Ma_NVien]
	) > 5
BEGIN 
	PRINT 'Can not have more than five familiars'
	ROLLBACK TRANSACTION
END;

/*
INSERT INTO [ThanNhan] VALUES (333445555,'zz', 'Nu', '1999-01-01', 'Con gai');
INSERT INTO [ThanNhan] VALUES (333445555,'yy', 'Nu', '1999-12-12', 'Con gai');
INSERT INTO [ThanNhan] VALUES (333445555,'xx', 'Nu', '1999-12-31', 'Con gai');
*/

/* II.5 */
/*
INSERT INTO [NhanVien] VALUES ('aaa', 'aaa', 'aaa',999999999,'1966-06-06', 'xxx', 'Nu', 200000,333445555, 4);
INSERT INTO [NhanVien] VALUES ('bbb', 'bbb', 'bbb',999999998,'1966-06-06', 'xxx', 'Nu', 200000,333445555, 4);
INSERT INTO [NhanVien] VALUES ('ccc', 'ccc', 'ccc',999999997,'1966-06-06', 'xxx', 'Nu', 200000,333445555, 4);
INSERT INTO [NhanVien] VALUES ('ddd', 'ddd', 'ddd',999999996,'1966-06-06', 'xxx', 'Nu', 200000,333445555, 4);
*/

CREATE TRIGGER [tr_5_Sex_diff] ON [NhanVien]
AFTER INSERT, DELETE, UPDATE
AS
BEGIN
	DECLARE @diff float = 
		(
		SELECT
			CAST(( SELECT COUNT(CASE WHEN [Phai] = 'Nam' THEN 1 END) AS [NumOfMale] FROM [NhanVien]) AS FLOAT)
			/
			CAST((SELECT COUNT(CASE WHEN [Phai] = 'Nu' THEN 1 END) AS [NumOfMale] FROM [NhanVien]) AS FLOAT)
		)
	IF @diff >= 1.1 OR @diff <= CAST(10 AS FLOAT) / CAST(11 AS FLOAT)
	BEGIN
		PRINT 'The different between number of male and female employees must fewer than 10%'
		ROLLBACK TRANSACTION
	END;
END;
/*
INSERT INTO [NhanVien]
VALUES ('eee', 'eee', 'eee',999999995,'1966-06-06', 'xxx', 'Nu', 200000,333445555, 4);
*/