--CREATE DATABASE PE_Q1
--DROP DATABASE PE_Q1
USE PE_Q1

CREATE TABLE [Students](
	[StudentID] [int] NOT NULL,
	[Name] [nvarchar](50) NULL,
	[Gender] [char](1) NULL,
	[Address] [nvarchar](200) NULL,
 CONSTRAINT [PK_Students] PRIMARY KEY ([StudentID])
 );

 CREATE TABLE [Teachers](
	[TeacherID] [int] NOT NULL,
	[Name] [nvarchar](50) NULL,
	[Gender] [char](1) NULL,
	[Address] [nvarchar](200) NULL,
 CONSTRAINT [PK_Teachers] PRIMARY KEY([TeacherID])
 );

CREATE TABLE [Classes](
	[ClassID] [int] NOT NULL,
	[TeacherID] [int] NULL,
	[GroupID] [char](6) NULL,
	[courseID] [char](6) NULL,
	[NoCredits] [int] NULL,
	[Semester] [char](10) NULL,
	[year] [int] NULL,
 CONSTRAINT [PK_Classes] PRIMARY KEY ([ClassID]),
 CONSTRAINT [FK_TeacherID] FOREIGN KEY ([TeacherID]) REFERENCES [Teachers]([TeacherID])
);

CREATE TABLE [Attend](
	[Date] [date] NOT NULL,
	[Slot] [int] NOT NULL,
	[ClassID] [int] NOT NULL,
	[StudentID] [int] NOT NULL,
	[Attend] [bit] NULL,
 CONSTRAINT [PK_Attend] PRIMARY KEY ([Date],[Slot],[ClassID],[StudentID]),
 CONSTRAINT [FK_ClassID] FOREIGN KEY ([ClassID]) REFERENCES [Classes]([ClassID]),
 CONSTRAINT [FK_StudentID] FOREIGN KEY ([StudentID]) REFERENCES [Students]([StudentID])
);