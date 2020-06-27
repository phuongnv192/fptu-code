--USE [PE_Demo_S2019]

SELECT [ID]
      ,[CustomerName]
      ,[Segment]
      ,[Country]
      ,[City]
      ,[State]
      ,[PostalCode]
      ,[Region]
  FROM [dbo].[Customer]
  WHERE City = 'Arlington' AND Segment = 'Consumer';