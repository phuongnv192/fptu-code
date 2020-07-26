CREATE TABLE [Genres] (
	[Genre] varchar(50),
	[Description] nvarchar(200)
CONSTRAINT [PK_Genre] PRIMARY KEY ([Genre])
);

CREATE TABLE [Movies] (
	[MovieNumber] int,
	[Title] nvarchar(200),
	[Year] int,
	[Genre] varchar(50)
CONSTRAINT [PK_MovieNumber] PRIMARY KEY ([MovieNumber]),
CONSTRAINT [FK_Genre] FOREIGN KEY ([Genre]) REFERENCES [Genres]([Genre])
);

CREATE TABLE [Persons] (
	[PersonID] int,
	[FullName] nvarchar(200),
	[Gender] nvarchar(10)
CONSTRAINT [PK_PersonID] PRIMARY KEY ([PersonID])
);

CREATE TABLE [Rate] (
	[MovieNumber] int,
	[PersonID] int,
	[Time] DateTime,
	[Comment] text,
	[NumbericRating] float
CONSTRAINT [PK_Rate] PRIMARY KEY ([MovieNumber],[PersonID]),
CONSTRAINT [FK_MovieNumber] FOREIGN KEY ([MovieNumber]) REFERENCES [Movies]([MovieNumber]),
CONSTRAINT [FK_PersonID] FOREIGN KEY ([PersonID]) REFERENCES [Persons]([PersonID])
);