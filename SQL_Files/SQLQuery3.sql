use [BrensDenDB]
Go
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

CREATE PROCEDURE [dbo].[Visitor_Crud]

   @Action varchar(20),
   @visId int = null,
   @FirstName varchar(50) = null,
   @LastName varchar(50) = null,
   @Email varchar(50) = null



AS
BEGIN
SET NOCOUNT ON;

--select for login
   if @Action = 'Select4Login'
   Begin
     Select * from dbo.VISITOR where vis_id = @visId

   END

 
  --select for user profile
  if @Action = 'Select4Profile'

  Begin
  Select *from dbo.VISITOR where vis_id = @visId

  END

  --insert registration
  if @Action = 'Insert'
  BEGIN
  Insert into dbo.VISITOR (vis_id, vis_first_name, vis_last_name, vis_email)
  values (@visId, @FirstName, @LastName, @Email)
  End

END
